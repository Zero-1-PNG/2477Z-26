#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

// . . .
// Make your own autonomous functions here!
// . . .

// Trigger the selected autonomous routine

void SoloAWP() {
  chassis.pid_wait();
  chassis.pid_drive_set(18_in, 80, true); // trying to change the drive to true so it moves
  chassis.pid_wait();

chassis.pid_drive_set(18_in, 80);
chassis.pid_wait();
upper_doinker.set(false);
}

void ScoreRingsPlatDown() {
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
