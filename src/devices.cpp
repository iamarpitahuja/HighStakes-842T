// #include "C:\Users\kc004\OneDrive\Desktop\tears 2.11.25\include\devices.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\devices.hpp"
#include "opcontrol.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\autoTuning.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor intake(INTAKE_PORT, INTAKE_GEARSET); // intake object
pros::MotorGroup arm({ARM_LEFT, ARM_RIGHT}, ARM_GEARSET); //arm object 

pros::Optical colorSort(opticalSensor);
pros::adi::DigitalOut mogo(MOGO); //MOGO Mech
pros::adi::DigitalOut leftDoinkerMech(leftDoinker); //left doinker mech
pros::adi::DigitalOut rightDoinkerMech(rightDoinker); //right doinker mech
pros::adi::DigitalOut intakePis(intakePiston); //MOGO Mech


pros::ADIDigitalIn limitSwitch(AUTON_SELECTOR); //autoselector
pros::Imu imu(IMU_PORT); // inertial sensor

pros::Rotation rot(armRotational); 
pros::Rotation horizontalRot(horizontalOdomRotational);
pros::Rotation vertRot(vertOdomRotational);
pros::Distance frontDist(frontDistSensor);
pros::Distance rightDist(rightDistSensor);
pros::Distance leftDist(leftDistSensor);

pros::MotorGroup leftMotors({LEFT_FRONT_DRIVE_PORT, LEFT_MIDDLE_DRIVE_PORT, LEFT_BACK_DRIVE_PORT}, DRIVE_GEARSET);
pros::MotorGroup rightMotors({RIGHT_FRONT_DRIVE_PORT, RIGHT_MIDDLE_DRIVE_PORT, RIGHT_BACK_DRIVE_PORT}, DRIVE_GEARSET);

lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              CHASSIS_TRACK_WIDTH, // chassis track width
                              lemlib::Omniwheel::NEW_275, // chassis wheel diameter
                              CHASSIS_RPM, // chassis RPM
                              CHASSIS_CHASE_POWER // scaled coefficient of friction
);

//horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontalRot, 2.0, -1.943121); //-0.55||   -1.6
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertRot, 2.0, -0.03641); //1.1||    -0.3

lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, we don't have a second one
                            nullptr, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, we don't have a second one
                            &imu // inertial sensor
);
// forward/backward PID
lemlib::ControllerSettings linearController(LINEAR_KP, // proportional gain (kP)
                                            LINEAR_KI, // integral gain (kI)
                                            LINEAR_KD, // derivative gain (kD)
                                            LINEAR_ANTI_WINDUP, // anti windup
                                            LINEAR_SMALL_ERROR, // small error range, in inches
                                            LINEAR_SMALL_ERROR_TIMEOUT, // small error range timeout, in milliseconds
                                            LINEAR_LARGE_ERROR, // large error range, in inches
                                            LINEAR_LARGE_ERROR_TIMEOUT, // large error range timeout, in milliseconds
                                            LINEAR_MAX_ACCEL // maximum acceleration (slew)
);

// turning PID
lemlib::ControllerSettings angularController(ANGULAR_KP, // proportional gain (kP)
                                             ANGULAR_KI, // integral gain (kI)
                                             ANGULAR_KD, // derivative gain (kD)
                                             ANGULAR_ANTI_WINDUP, // anti windup
                                             ANGULAR_SMALL_ERROR, // small error range, in degrees
                                             ANGULAR_SMALL_ERROR_TIMEOUT, // small error range timeout, in milliseconds
                                             ANGULAR_LARGE_ERROR, // large error range, in degrees
                                             ANGULAR_LARGE_ERROR_TIMEOUT, // large error range timeout, in milliseconds
                                             ANGULAR_MAX_ACCEL // maximum acceleration (slew)
);

lemlib::ExpoDriveCurve throttleCurve(THROTTLE_DEADBAND, // joystick deadband out of 127
                                     THROTTLE_MINIMUM_OUTPUT, // minimum output where drivetrain will move out of 127
                                     THROTTLE_EXPO_GAIN // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(STEER_DEADBAND, // joystick deadband out of 127
                                  STEER_MINIMUM_OUTPUT, // minimum output where drivetrain will move out of 127
                                  STEER_EXPO_GAIN // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        linearController, // linear PID settings
                        angularController, // angular PID settings
                        sensors, // sensor settings
                        &throttleCurve, // throttle curve settings
                        &steerCurve // steer curve settings
);