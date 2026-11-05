#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here. 8/6/26

inline pros::Motor l_lift(1);
inline pros::Motor r_lift(-10);

inline void set_lift(int input) {
  l_lift.move(input);
  r_lift.move(input);
}

inline ez::PID liftPID{0.45, 0, 0, 0, "Lift"};

inline void lift_wait() {
  while (liftPID.exit_condition({l_lift, r_lift}, true) == ez::RUNNING) {
    pros::delay(ez::util::DELAY_TIME);
  }
}