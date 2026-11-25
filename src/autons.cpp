#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 120;
const int TURN_SPEED = 10;
const int SWING_SPEED = 120;


// . . .
// Make your own autonomous functions here!
// . . .

// Trigger the selected autonomous routine

void SoloAWP() {
lower_doinker.set(false);
chassis.pid_drive_set(20_in, 100);
chassis.pid_wait();
chassis.pid_turn_set(-90_deg, 100);
chassis.pid_wait();
upper_doinker.set(false);
}

void BluesideAuton() {
  // . . .
  // Autonomous code goes here
  // . . .
}

void NeutralStealPlatDown() {
  // . . .
  // Autonomous code goes here
  // . . .
}

void NeutralStealPlatUp() {
  // . . .
  // Autonomous code goes here
  // . . .
}
