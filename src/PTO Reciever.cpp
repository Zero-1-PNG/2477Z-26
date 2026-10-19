#include "PTO Giver.hpp"
using namespace ez;

pros::adi::DigitalOut pto_lift_piston('A'); // PTO Shift Piston
pros::adi::DigitalOut claw_piston('B');     // Claw Clamp Piston
bool pto_lift_enabled = false;

// Toggles the PTO piston and sets motor brake modes
void pto_toggle_lift(bool toggle) {
  pto_lift_enabled = toggle;

  chassis.pto_toggle({chassis.left_motors[LEFT_LIFT_MOTOR], chassis.right_motors[RIGHT_LIFT_MOTOR]}, toggle);
  pto_lift_piston.set_value(toggle);
  
  if (toggle) {
    chassis.left_motors[LEFT_LIFT_MOTOR].set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    chassis.right_motors[RIGHT_LIFT_MOTOR].set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  }
}

// Master operator loop for your lift and claw
void lift_control() {
  // 1. L2 Toggles the PTO Transmission between Drive Base and Lift
  if (master.get_digital_new_press(DIGITAL_L2)) {
    pto_toggle_lift(!pto_lift_enabled);
  }

  // 2. L1 Toggles the Claw Clamp (Clamps down / Releases)
  if (master.get_digital_new_press(DIGITAL_L1)) {
    claw_piston.set_value(!claw_piston.get_value());
  }

  // 3. Control the Lift via R1 and R2 (Only works if Lift Mode is engaged!)
  if (!pto_lift_enabled) {
    return; // Safety: If PTO is off, don't let R1/R2 steal or move the drive base motors!
  }

  if (master.get_digital(DIGITAL_R1)) {
    // Raise lift
    chassis.left_motors[LEFT_LIFT_MOTOR_PORT_1].move(127);
    chassis.right_motors[RIGHT_LIFT_MOTOR_PORT_10].move(127);
  } 
  else if (master.get_digital(DIGITAL_R2)) {
    // Lower lift
    chassis.left_motors[LEFT_LIFT_MOTOR_PORT_1].move(-127);
    chassis.right_motors[RIGHT_LIFT_MOTOR_PORT_10].move(-127);
  } 
  else {
    // Stop lift motors from moving when no button is pressed
    chassis.left_motors[LEFT_LIFT_MOTOR_PORT_1].move(0);
    chassis.right_motors[RIGHT_LIFT_MOTOR_PORT_10].move(0);
  }
}