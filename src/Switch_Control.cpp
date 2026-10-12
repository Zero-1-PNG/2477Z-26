#include "main.h"
#include "subsystems.hpp"

ez::PID shiftPID(0.45, 0.0, 0.0, "Shift"); 
bool shift_to_lift = false; 
int shift_target = 0;

void shift_task() {
  pros::delay(500); 

  // Direct access to your two shifting motors
  pros::Motor r_shift(-10);
  pros::Motor l_shift(1);

  while (true) {
    if (shift_to_lift) {
      // 1. Fire the piston to swap gears to the lift
      lower_doinker.set_true(); 

      // 2. Run your Lift PID
      double current_pos = (l_shift.get_position() + r_shift.get_position()) / 2.0;
      double output = shiftPID.compute(shift_target, current_pos);

      r_shift.move_voltage(output);
      l_shift.move_voltage(output);
    } else {
      // Retract piston to the drivetrain
      lower_doinker.set_false(); 
      shiftPID.reset(); 

      // Keep the lift target tracking your current position
      shift_target = (l_shift.get_position() + r_shift.get_position()) / 2.0;

      //  leave the motors completely free for the chassis to drive normally!
    }

    pros::delay(ez::util::DELAY_TIME); 
  }
}
