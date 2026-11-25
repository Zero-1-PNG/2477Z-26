#include "main.h"

void set_left_input(int lifters) {
  left_lifters.move_velocity(lifters);
}

void set_right_input(int lifters) {
  right_lifters.move_velocity(lifters);
}
void lifters_opcontrol() {
  if (master.get_digital(DIGITAL_R1)) {
    set_left_input(115);
    set_right_input(115);
  }
  else if (master.get_digital(DIGITAL_R2)) {
    set_left_input(-115);
    set_right_input(-115);
  }
 else {
    set_left_input(0);
    set_right_input(0);
  }
}