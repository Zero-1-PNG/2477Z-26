#include "main.h"

void set_left_input(int shift) {
  left_shift.move_velocity(shift);
}

void set_right_input(int shift) {
  right_shift.move_velocity(shift);
}

void shift_opcontrol() {
  if (master.get_digital(DIGITAL_R1)) {
    set_left_input(127);
    set_right_input(127);
  }
  else if (master.get_digital(DIGITAL_R2)) {
    set_left_input(-127);
    set_right_input(-127);
  }
  else {

    set_left_input(0);
    set_right_input(0);
  }
}

// could i use ez :: Drive chassis in a else if function using C++ to control the speed of two motors even though those motors were dfined in another function
