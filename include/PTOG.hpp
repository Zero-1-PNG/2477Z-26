#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor left_lift_motor(1);  // Left Lift Motor
inline pros::Motor right_lift_motor(-10); // Right Lift Motor

inline pros::adi::DigitalOut claw_piston('A'); // Replace 'A' with the actual port used for the claw piston
inline pros::adi::DigitalOut pto_lift_piston('B'); // Replace 'B' with the actual port used for the PTO lift piston

extern bool pto_lift_enabled; // PTO Lift Mode State
extern bool claw_enabled; // Claw Clamp State

void lift_control();
void pto_toggle_lift(bool toggle);
void move_lift_motors(int input);