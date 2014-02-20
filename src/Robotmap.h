#ifndef ROBOTMAP_H
#define ROBOTMAP_H
//ORCA=WIN

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1
#define LOADING_CONVEYOR_PORT 2
#define QUEUE_CONVEYOR_PORT 1

#define LOADING_BREAK_BEAM_PORT 1
#define QUEUE_BREAK_BEAM_PORT 2
#define SHOOTING_BREAK_BEAM_PORT 3

#define BALLCONVEYOR_AUTO_BUTTON 2
#define QUEUE_CONVEYOR_FORWARDBUTTON 6
#define QUEUE_CONVEYOR_REVERSEBUTTON 4
#define LOADING_CONVEYOR_FORWARDBUTTON 5
#define LOADING_CONVEYOR_REVERSEBUTTON 3

#define TIP_GYRO_PORT 1
#define TURN_GYRO_PORT 2
#define LEFT_ENCODER_PORT 6, 7
#define RIGHT_ENCODER_PORT 8, 9


#define BRIDGETIPPER_LIMIT_UPPER_PORT 4
#define BRIDGETIPPER_LIMIT_LOWER_PORT 5
#define BRIDGETIPPER_VICTOR_PORT 7
#define BRIDGETIPPER_JOYSTICK_SENSITIVITY 0.05
#define BRIDGETIPPER_JOYSTICK_SPEED 0.5
#define BRIDGETIPPER_RAISEBUTTON 0
#define BRIDGETIPPER_LOWERBUTTON 0

#define SCF_SPEED 0.33
#define	SCC_SPEED 0.406
#define SOB_SPEED 0.48
#define SBB_SPEED 0.61
#define SAD_SPEED 0.78
#define SKC_SPEED 0.42

#define SHOOTER_LEFT_MOTOR 5
#define SHOOTER_RIGHT_MOTOR 6

#define FLOOR_GROUND_US_THRESHOLD 0.2
#define BRIDGE_GROUND_US_THRESHOLD 0.2

#endif
