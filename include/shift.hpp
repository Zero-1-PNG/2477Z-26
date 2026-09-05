#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

inline pros::Motor left_shift(1); // Two small gears for the intake: make it spin backward and cut the speed to half when on Drivebase 8/6/26
inline pros::Motor right_shift(10); // Two small gears for the intake: make it spin backward and cut the speed to half when on Drivebase 8/6/26

void set_left_input(int shift);
void set_right_input(int shift);
void shift_opcontrol();