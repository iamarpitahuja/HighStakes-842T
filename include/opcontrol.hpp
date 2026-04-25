#pragma once

/**
 * Declares the integers that contain our values for buttons and mechanisms.
 *
 * Stores all the integers with our tuned drive
 * curve values and button definitions
 *
 * @author Arpit Ahuja, Sana Barige, Diya Ladani
 * @version 1.0
 * @since 2025-02-10
 */


/**
 * @brief Throttle curve deadband value of 0
 *
 */
constexpr int THROTTLE_DEADBAND = 0;

/**
 * @brief Minimum output is 0 so the robot is able to come to a stop
 *
 */
constexpr int THROTTLE_MINIMUM_OUTPUT = 0;

/**
 * @brief Our throttle curve multiples the joystick pisition by 1.019 for 
 * faster acceleration
 *
 */
constexpr float THROTTLE_EXPO_GAIN = 1.019;

/**
 * @brief Stter curve deadband value of 0
 *
 */
constexpr int STEER_DEADBAND = 0;

/**
 * @brief Minimum output of steer is 0 so robot doesn't turn all the time
 *
 */
constexpr int STEER_MINIMUM_OUTPUT = 0;

/**
 * @brief Steer (turn) is scaled by a value of 1.019
 *
 */
constexpr float STEER_EXPO_GAIN = 1.019;

/**
 * @brief this is the saturation rate of our optical sensor
 *
 */
constexpr float DESATURATION_BIAS = 0.75;

/**
 * @brief this is the intake speed of our robot stored as an integer
 *
 */
constexpr int INTAKE_SPEED = 120;

/**
 * @brief this is the fast outtake speed of our robot stored as an integer
 *
 */
constexpr int OUTTAKE_FAST_SPEED = 127;

/**
 * @brief this is the slow outtake speed of our robot stored as an integer. 
 *
 */
constexpr int OUTTAKE_SLOW_SPEED = 50; // TODO: change this back to 50

/**
 * @brief speed at which our ladybrown goes up
 *
 */
constexpr int ARM_UP_SPEED = 127;

/**
 * @brief the slower speed at which our ladybrown goes up
 *
 */
constexpr int ARM_UP_SLOW_SPEED = 60;

/**
 * @brief speed at which our ladybrown goes down
 *
 */
constexpr int ARM_DOWN_FAST_SPEED = 127;

/**
 * @brief the slower speed at which our ladybrown goes down
 *
 */
constexpr int ARM_DOWN_SLOW_SPEED = 60;

/**
 * @brief our throttle is controlled by the Y position of our left joystick
 *
 */
//throttle speed
#define THROTTLE_AXIS pros::E_CONTROLLER_ANALOG_LEFT_Y

/**
 * @brief our steer is controlled by the X position of our right joystick
 *
 */
#define STEER_AXIS pros::E_CONTROLLER_ANALOG_RIGHT_X

/**
 * @brief our robot intakes when the R1 button is pressed
 *
 */
//intake buttons
#define INTAKE_BUTTON pros::E_CONTROLLER_DIGITAL_R1

/**
 * @brief outtakes when the R2 button is pressed
 *
 */
#define OUTTAKE_BUTTON pros::E_CONTROLLER_DIGITAL_R2

/**
 * @brief intake piston goes up or down when button A is pressed
 *
 */
#define INTAKE_PIS_BUTTON pros::E_CONTROLLER_DIGITAL_A

/**
 * @brief mogo goes up and down with this button pressed
 *
 */
//Mogo buttons
#define MOGO_DOWN_BUTTON pros::E_CONTROLLER_DIGITAL_X
#define MOGO_UP_BUTTON pros::E_CONTROLLER_DIGITAL_B

/**
 * @brief ladybrown moves up when L1 is pressed
 *
 */
//Arm buttons
#define ARM_UP_BUTTON pros::E_CONTROLLER_DIGITAL_L1

/**
 * @brief ladybrown goes down when L2 is pressed
 *
 */
#define ARM_DOWN_BUTTON pros::E_CONTROLLER_DIGITAL_L2

/**
 * @brief ladybrown goes into its load position when up is pressed
 *
 */
//Arm Automatic
#define ARM_AUTO_UP_BUTTON pros::E_CONTROLLER_DIGITAL_UP
#define ARM_AUTO_DOWN_BUTTON pros::E_CONTROLLER_DIGITAL_DOWN



//Basket piston
//#define BASKET_BUTTON pros::E_CONTROLLER_DIGITAL_A

/**
 * @brief right doinker moves up and down when right button is pressed
 *
 */
//doinker piston
#define RIGHT_DOINKER_BUTTON pros::E_CONTROLLER_DIGITAL_RIGHT

/**
 * @brief left doinker button moves up and down when the left button is pressed
 *
 */
#define LEFT_DOINKER_BUTTON pros::E_CONTROLLER_DIGITAL_LEFT