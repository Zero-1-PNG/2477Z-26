#include "main.h" 
using namespace ez;

inline bool pto_lift_enabled = false; 
inline bool claw_enabled = false;     

void pto_toggle_lift(bool toggle) {
    pto_lift_enabled = toggle;
    
    // Disconnect the motors from the EZ-Template chassis array
    chassis.pto_toggle({left_lift_motor, right_lift_motor}, toggle);
    pto_lift_piston.set_value(toggle);

    if (toggle) {
        // Lift Engaged: Active HOLD so it doesn't fall under its own weight
        left_lift_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        right_lift_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    } else {
        // Drive Base Engaged: Reset to BRAKE mode for tight tank driving steering
        left_lift_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
        right_lift_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    }
}

void move_lift_motors(int input) {
    if (!pto_lift_enabled) return; 
    left_lift_motor.move(input);
    right_lift_motor.move(-input);
}

void lift_control() {
    // L2 toggles between Drive Base and Lift Mode
    if (master.get_digital_new_press(DIGITAL_L2)) {
        pto_toggle_lift(!pto_lift_enabled);
    }

    // L1 toggles the Claw clamp
    if (master.get_digital_new_press(DIGITAL_L1)) {
        claw_enabled = !claw_enabled;
        claw_piston.set_value(claw_enabled); 
    }

    // Only allow R1/R2 button presses to communicate when Lift Mode is active
    if (pto_lift_enabled) {
        if (master.get_digital(DIGITAL_R1)) {
            move_lift_motors(-127);  // Raise lift
        } else if (master.get_digital(DIGITAL_R2)) {
            move_lift_motors(127); // Lower lift
        } else {
            move_lift_motors(0);    // Actively locks the lift in mid-air
        }
    }
}