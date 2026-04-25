#pragma once

/**
 * Declares the floats that contain our tuned PID values.
 *
 * Stores all the floats with our tuned lateral
 * and angular PID values 
 *
 * @author Arpit Ahuja, Sana Barige, Diya Ladani
 * @version 1.0
 * @since 2025-02-10
 */

constexpr float CHASSIS_CHASE_POWER = 8.0; // scaled coefficient of friction

/**
 * @brief Lateral PID kP (Proportional term) value
 *
 */
constexpr float LINEAR_KP = 5.35; //9.01 proportional gain (kP) //7.0

/**
 * @brief Lateral PID kI (Integral Term) value
 *
 */
constexpr float LINEAR_KI = 0.0; //0 integral gain (kI)

/**
 * @brief Lateral PID kD (Derivative Term) value
 *
 */
constexpr float LINEAR_KD = 36.5; //75 derivative gain (kD) //25

/**
 * @brief Lateral PID Integral reset threshold
 * ex: kI greater than 3 is reset to 0 to avoid integral windup
 * 
 */
constexpr float LINEAR_ANTI_WINDUP = 3.0; // anti windup

/**
 * @brief Lateral PID small error range at which the motion exits
 *
 */
constexpr float LINEAR_SMALL_ERROR = 0.0; // small error range, in inches

/**
 * @brief Lateral PID small error timeout
 * ex- max time the robot spends at this small error range before exiting
 */
constexpr int LINEAR_SMALL_ERROR_TIMEOUT = 0; // small error range timeout, in milliseconds

/**
 * @brief Lateral PID large error range at which motion exits
 *
 */
constexpr float LINEAR_LARGE_ERROR = 0.0; // large error range, in inches

/**
 * @brief Lateral PID large error timeout
 * ex- max time the robot spends at this large error range before exiting
 */
constexpr int LINEAR_LARGE_ERROR_TIMEOUT = 0; // large error range timeout, in milliseconds

/**
 * @brief maximum rate at which the robot accelerates to max speed
 * out of a range from 0-127
 */
constexpr float LINEAR_MAX_ACCEL = 5.0; // maximum acceleration (slew)

// Angular PID Values

/**
 * @brief Angular PID kP (Proportional term) value
 *
 */
constexpr float ANGULAR_KP = 1.8; // proportional gain (kP) //2.32

/**
 * @brief Angular PID kI (Integral term) value
 *
 */
constexpr float ANGULAR_KI = 0.1; // integral gain (kI)

/**
 * @brief Angular PID kD (Derivative term) value
 *
 */
constexpr float ANGULAR_KD = 25; // derivative gain (kD)

/**
 * @brief Angular PID Integral reset threshold
 * ex: kI greater than 3 is reset to 0 to avoid integral windup
 * 
 */
constexpr float ANGULAR_ANTI_WINDUP = 3.0; // anti windup

/**
 * @brief Angular PID small error range at which the motion exits
 *
 */
constexpr float ANGULAR_SMALL_ERROR = 0.0; // small error range, in degrees

/**
 * @brief Angular PID small error timeout
 * ex- max time the robot spends at this small error range before exiting
 */
constexpr int ANGULAR_SMALL_ERROR_TIMEOUT = 0; // small error range timeout, in milliseconds

/**
 * @brief Angular PID large error range at which motion exits
 *
 */
constexpr float ANGULAR_LARGE_ERROR = 0.0; // large error range, in degrees

/**
 * @brief Angular PID large error timeout
 * ex- max time the robot spends at this large error range before exiting
 */
constexpr int ANGULAR_LARGE_ERROR_TIMEOUT = 0; // large error range timeout, in milliseconds

/**
 * @brief maximum rate at which the robot accelerates to max speed
 * out of a range from 0-127
 */
constexpr float ANGULAR_MAX_ACCEL = 3.0; // maximum acceleration (slew)

// constexpr float LINEAR_KP = 5.3; // proportional gain (kP)
// constexpr float LINEAR_KI = 0.0; // integral gain (kI)
// constexpr float LINEAR_KD = 20.0; // derivative gain (kD)
// constexpr float LINEAR_ANTI_WINDUP = 3.0; // anti windup
// constexpr float LINEAR_SMALL_ERROR = 1.0; // small error range, in inches
// constexpr int LINEAR_SMALL_ERROR_TIMEOUT = 100; // small error range timeout, in milliseconds
// constexpr float LINEAR_LARGE_ERROR = 3.0; // large error range, in inches
// constexpr int LINEAR_LARGE_ERROR_TIMEOUT = 200.0; // large error range timeout, in milliseconds
// constexpr float LINEAR_MAX_ACCEL = 3.0; // maximum acceleration (slew)


// constexpr float ANGULAR_KP = 2.37; // proportional gain (kP)
// constexpr float ANGULAR_KI = 0.2; // integral gain (kI)
// constexpr float ANGULAR_KD = 21.5; // derivative gain (kD)
// constexpr float ANGULAR_ANTI_WINDUP = 3.0; // anti windup
// constexpr float ANGULAR_SMALL_ERROR = 1.0; // small error range, in degrees
// constexpr int ANGULAR_SMALL_ERROR_TIMEOUT = 100; // small error range timeout, in milliseconds
// constexpr float ANGULAR_LARGE_ERROR = 3.0; // large error range, in degrees
// constexpr int ANGULAR_LARGE_ERROR_TIMEOUT = 250; // large error range timeout, in milliseconds
// constexpr float ANGULAR_MAX_ACCEL = 3.0; // maximum acceleration (slew)