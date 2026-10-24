#include "main.h"
using namespace ez;

bool pto_lift_enabled = false; // PTO Lift Mode State
bool claw_enabled = false; // Claw Clamp State

// Toggles the PTO piston and sets motor brake modes
void pto_toggle_lift(bool toggle) {
  pto_lift_enabled = toggle;
  chassis.pto_toggle({left_lift_motor, right_lift_motor}, toggle);
  pto_lift_piston.set_value(toggle);
  if (toggle) {
    left_lift_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    right_lift_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  }
}

void move_lift_motors(int input) {
  if (!pto_lift_enabled) return; 
    // Safety: If PTO is off, don't let R1/R2 steal or move the drive base motors!
  left_lift_motor.move(input);
  right_lift_motor.move(input);
}

// Master operator loop for your lift and claw
void lift_control() {
  // 1. L2 Toggles the PTO Transmission between Drive Base and Lift
  if (master.get_digital_new_press(DIGITAL_L2)) {
    pto_toggle_lift(!pto_lift_enabled);
  }

  // 2. L1 Toggles the Claw Clamp (Clamps down / Releases)
  if (master.get_digital_new_press(DIGITAL_L1)) {
    claw_enabled = (!claw_enabled);
  }

  //Control the Lift via R1 and R2 (Only works if Lift Mode is engaged)
  if (!pto_lift_enabled) {
    return; 
    // Safety: If PTO is off, don't let R1/R2 steal or move the drive base motors!
  }

  if (master.get_digital(DIGITAL_R1)) {
    // Raise lift
    move_lift_motors(-127);
  }
  else if (master.get_digital(DIGITAL_R2)) {
    // Lower lift
    move_lift_motors(127);
  }
  else {
    // Stop lift motors from moving when no button is pressed
    move_lift_motors(0);
  }
}