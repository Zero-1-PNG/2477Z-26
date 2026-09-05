#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

inline ez::Piston lower_doinker('A');  // Piston usage 8/6/26
inline ez::Piston upper_doinker('B');  // Claw usage 8/6/26

void set_lower_input(bool input);
void set_upper_input(bool input);
void doinker_opcontrol();
void doinker_control();