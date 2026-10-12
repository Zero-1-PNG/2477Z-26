#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;
extern ez::tracking_wheel horiz_tracker;

inline ez::Piston lower_doinker('A'); 

// For lift state 10/2/26
extern ez::PID shiftPID;
extern bool shift_to_lift;
extern int shift_target;

void shift_task();

// Your motors, sensors, etc. should go here. 8/6/26
