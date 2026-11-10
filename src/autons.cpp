#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 127;
const int TURN_SPEED = 90;
const int SWING_SPEED = 120;

// . . .
// Make your own autonomous functions here!
// . . .

// Trigger the selected autonomous routine

void SoloAWP() {
  
  chassis.drive_imu_reset(); 
  chassis.drive_sensor_reset(); 
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD); 

chassis.pid_drive_set(9_in, 40);
chassis.pid_wait();
chassis.pid_turn_set(90_deg, 100);
chassis.pid_wait();
chassis.pid_drive_set(8_in, 50);
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
