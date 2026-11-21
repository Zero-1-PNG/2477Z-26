#include "main.h"


void set_shift(int power) {
  left_shift.move(power);
  right_shift.move(power);
}

void shift_opcontrol() {

  static bool was_on_lift = false;

  bool on_lift = !lower_doinker.get();

    if (on_lift != was_on_lift) {
    chassis.pto_toggle({left_shift, right_shift}, on_lift); on_lift;
   

    pros::motor_brake_mode_e_t brake = on_lift ? 
    MOTOR_BRAKE_HOLD : chassis.drive_brake_get();
    left_shift.set_brake_mode(brake);
    right_shift.set_brake_mode(brake);
    was_on_lift = on_lift;
  }

   if (!on_lift) return;

   if (master.get_digital(DIGITAL_R1)) {
    set_shift(-115);

  } else if (master.get_digital(DIGITAL_R2)) {
    set_shift(115);

  } else {
    set_shift(0);
  }
}

