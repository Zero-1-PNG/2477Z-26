#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

#define LEFT_LIFT_MOTOR_1 
#define RIGHT_LIFT_MOTOR_10

extern pros::adi::DigitalOut claw_piston;
extern pros::adi::DigitalOut pto_lift_piston;

extern bool pto_lift_enabled;

void pto_toggle_lift(bool toggle);
void lift_control();