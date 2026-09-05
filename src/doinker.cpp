#include "main.h"

// Adjust port letters to match the parts

void set_lower_input(bool input) {
  lower_doinker.set(input);
}
void set_upper_input(bool input) {
  upper_doinker.set(input);
}

void doinker_opcontrol() {
  // Left doinker toggles with L1
if (master.get_digital_new_press(DIGITAL_L1)) {
  lower_doinker.set(!lower_doinker.get());
} 
}

void doinker_control() {
  // Right doinker toggles with L2
  if (master.get_digital_new_press(DIGITAL_L2)) {
    upper_doinker.set(!upper_doinker.get());
  }
}