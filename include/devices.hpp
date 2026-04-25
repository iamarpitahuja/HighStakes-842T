#pragma once

/**
 * Declares the integers representing ports and creates device objects.
 *
 * Defines the gearset (red motor, blue motor, green motor) for the mechanisms on the robot
 * Contains integers that represent the ports connected to mechanisms,
 * and characters that represent Digital Pneumatic ports.
 * Our global chassis and pros objects are declared below as well
 *
 * @author Arpit Ahuja, Sana Barige, Diya Ladani
 * @version 1.0
 * @since 2025-02-10
 */


/**
 * @brief Includes all necessary header files we need to use
 *
 */
#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/misc.hpp"
#include "pros/optical.hpp"
#include "pros/distance.h"
#include "pros/distance.hpp"
/////////////////////////////////////////////////
// Device Configuration
///////////////////////////

/**
 * @brief Motor gear used for our drivetrain (blue)
 *
 */
#define DRIVE_GEARSET pros::MotorGears::blue

/**
 * @brief Motor gear used for our intake (blue)
 *
 */
#define INTAKE_GEARSET pros::MotorGears::blue
/**
 * @brief Motor gear used for our lady brown (green)
 *
 */
#define ARM_GEARSET pros::MotorGears::green

//RADIO = 16

/**
 * @brief Port number of our left front drive motor which is reversed
 *
 */
constexpr int LEFT_FRONT_DRIVE_PORT = -13;

/**
 * @brief Port number of our left middle drive motor which is normal
 *
 */
constexpr int LEFT_MIDDLE_DRIVE_PORT = -14;

/**
 * @brief Port number of our left back drive motor which is reversed
 *
 */
constexpr int LEFT_BACK_DRIVE_PORT = -12;

/**
 * @brief Port number of our right front drive motor which is normal
 *
 */
constexpr int RIGHT_FRONT_DRIVE_PORT = 18;

/**
 * @brief Port number of our right middle drive motor which is reversed
 *
 */
constexpr int RIGHT_MIDDLE_DRIVE_PORT = 17;

/**
 * @brief Port number of our right back drive motor which is normal
 *
 */
constexpr int RIGHT_BACK_DRIVE_PORT = 19;

/**
 * @brief Port number of our intake motor which is reversed
 *
 */
constexpr int INTAKE_PORT = -20; 

/**
 * @brief Port number of our left arm motor which is reversed
 *
 */
constexpr int ARM_LEFT = -20;

/**
 * @brief Port number of our right arm motor which is normal
 *
 */
constexpr int ARM_RIGHT = 20; 

/**
 * @brief Port number our front distance sensor
 *
 */
//constexpr int frontDistancePort = 15;

/**
 * @brief Port number of our back distance sensor
 *
 */
//constexpr int backDistancePort = 20;

/**
 * @brief Character that represents the ADI port for our Mogo pistons
 *
 */
constexpr char MOGO= 'e'; 

/**
 * @brief Character that represents the ADI port for our Auton selector
 *
 */
constexpr char AUTON_SELECTOR = 'b'; 

/**
 * @brief Character that represents the ADI port for our left doinker piston
 *
 */
constexpr char leftDoinker = 'h';

/**
 * @brief Character that represents the ADI port for our right doinker piston
 *
 */
constexpr char rightDoinker = 'g';

// constexpr char dLower = 'g';
// constexpr char dUpper = 'f';

/**
 * @brief Character that represents the ADI port for our intake piston
 * used to lift our intake up when scoring stacked rings
 */
constexpr char intakePiston = 'f';

/**
 * @brief Port number for our inertial sensor
 * used in our PID and heading control algorithms
 */
constexpr int IMU_PORT = 19;

/**
 * @brief Port number for the rotational sensor on our lady brown
 * used in our lady brown PID
 */
constexpr int armRotational = 16; //arm

/**
 * @brief Port number for our optical sensormjb ,
 * used for color sorting
 */
constexpr int opticalSensor = 20;

/**
 * @brief Port for our rotational sensor on our vertical odometry pod
 *
 */
constexpr int vertOdomRotational = 15; //vertical odom

/**
 * @brief Port for our rotational sensor on our horizontal odometry pod
 *
 */
constexpr int horizontalOdomRotational = -8; // horizontal odom

constexpr int frontDistSensor = 20;
constexpr int leftDistSensor = 20;
constexpr int rightDistSensor = 20;


/**
 * @brief Float that represnets the track width (wheel to wheel) of our drivebase
 *
 */
constexpr float CHASSIS_TRACK_WIDTH = 11.5;

/**
 * @brief Float that represents the RPM of our drive base 
 *
 */
constexpr float CHASSIS_RPM = 450;

//left distance is 10
//right distance is 14
//front distance is 13

/////////////////////////////////////////////////
// Global Device Objects
///////////////////////////

/**
 * @brief Pros controller object named master
 *
 */
extern pros::Controller master;

/**
 * @brief Chassis object that combines our sensors together as one object
 *
 */
extern lemlib::Chassis chassis;

/**
 * @brief Pros motor object for our intake
 *
 */
extern pros::Motor intake;

/**
 * @brief Pros motorgroup that combines our two ladybrown motors called arm
 *
 */
extern pros::MotorGroup arm;

/**
 * @brief Pros solenoid object that controls the mogo
 *
 */
extern pros::adi::DigitalOut mogo;

/**
 * @brief Pros rotational sensor object on our ladybrown
 *
 */
extern pros::Rotation rot; //arm rotation sensor

/**
 * @brief Pros rotational sensor object on our horizontal tracking wheel
 *
 */
extern pros::Rotation horizontalRot; //horizontal rotation sensor

/**
 * @brief Pros rotational sensor object on our vertical tracking wheel
 *
 */
extern pros::Rotation vertRot; //vertical rotation sensor
extern pros::adi::DigitalOut trapdoorMover;

/**
 * @brief Pros limit switch object used to iterate through our autons
 *
 */
extern pros::ADIDigitalIn limitSwitch;

/**
 * @brief Pros solenoid object used to control our left doinker
 *
 */
extern pros::adi::DigitalOut leftDoinkerMech;

/**
 * @brief Pros solenoid object used to control our right doinker
 *
 */
extern pros::adi::DigitalOut rightDoinkerMech;

extern pros::adi::DigitalOut descoreLower;
extern pros::adi::DigitalOut descoreUpper;

/**
 * @brief Pros solenoid object used to control our intake piston
 *
 */
extern pros::adi::DigitalOut intakePis;

/**
 * @brief Pros optical object that represents are optical sensor
 *
 */
extern pros::Optical colorSort; //optical sensor

/**
 * @brief Pros distance sensor object which is our front distance sensor
 *
 */
extern pros::Distance frontDist; //front distance sensor

/**
 * @brief Pros distance sensor object which is our back distance sensor
 *
 */
extern pros::Distance rightDist; //back distance sensor
extern pros::Distance leftDist;


