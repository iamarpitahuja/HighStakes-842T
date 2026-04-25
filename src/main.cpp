#include "main.h"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\devices.hpp"
#include "fmt/core.h"
#include "opcontrol.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\autos.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\subsystemHeaderFiles\ladyBrown.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\subsystemHeaderFiles\distanceSense.hpp"
#include "robodash/views/selector.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\driverHelperMethods.hpp"




//rd::Selector selector({{"red2ring", &red2ring}, {"Red-Solo-Awp", &redSoloAuto}, {"redElims", &redElims}, {"blue2ring", &blue2ring}, {"Blue-Solo-Awp", &blueSoloAuto}, {"blueElims", &blueElims}, {"Skills", &skills}});
//rd_view_t* view = rd_view_create("Odometry");

int auton = 0;

/**
 * @brief entry point of the program
 *
 */
void initialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(0, "842T Nova");
    chassis.calibrate(); // calibrate sensors
    pros::delay(2000);
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // sets arm brake mode
    rot.reset_position();
    intakePis.set_value(true);

    // thread to print location on brain screen
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(3, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(4, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(5, "Theta: %f", chassis.getPose().theta); // heading
            //pros::lcd::print(7, "ArmPos: %ld", rot.get_position()/100);
            pros::lcd::print(6, "frontDistance: %f", getFrontDist());
            pros::lcd::print(7, "frontDistance Confidence: %ld", frontDist.get_confidence());
            // delay to save resources
            pros::delay(25);
        }
    });

    /*pros::Task intake_unjam([&]() {
        uint32_t lastCheckTime = pros::millis();
        while (true) {
            // prints intake funcs
            if(pros::millis() - lastCheckTime >= 300){
                if(intake.get_efficiency()/100 <= 0.15){
                    intake.move(-2);
                    pros::delay(100);
                    intake.move(127);
                    lastCheckTime = pros::millis();
            } else{
                lastCheckTime = pros::millis();
            }
            // delay to save resources
            pros::delay(25);
        }
    }});*/
}

void competition_initialize() {
    
    const int autoCount = 2; //CHANGE NUMBER BASED ON NUMBER OF AUTONOMOUS PROGRAMS

    const char* autoNames[autoCount] = { //creates a chart
    "SKILLS",
    "blank",
    };

    //display on the brain screen
    pros::lcd::set_text(1, "TOGGLE AUTO AND INITIALIZE ARM");
    pros::lcd::print(2, "%s", autoNames[auton]);
    //feedback loop with the limit switch
    while(true) {
    if(limitSwitch.get_new_press()) {
      auton++;
      if(auton == autoCount) {
        auton = 0;
      } //end of if
      pros:: lcd::print(2, "%s", autoNames[auton]);
      pros::lcd::print(3, "%d", auton);
    } //end of if
    //dont update too quickly
    pros::delay(50);
  } //end of while

}

/**
 * @brief runs when field control is set to autonomous
 *
 */
void autonomous() {
    // run the selected autonomous routine
    selector(auton);
    //chassis.setPose(0,0,0);
    //chassis.calibrate();
    //chassis.moveToPoint(0, 48, 5000, {.maxSpeed = 127});
    // focus on the odometry views
    //rd_view_focus(view);

}

/**
 * @brief runs when field control is set to opcontrol
 *
 */
void opcontrol() {
    // loop while in driver control
    //rd_view_focus(view);
    while (true) {
        // drivetrain
        const int throttle = master.get_analog(THROTTLE_AXIS);
        const int steer = master.get_analog(STEER_AXIS);
        chassis.arcade(throttle, steer, false, DESATURATION_BIAS);

        //intake code
        intakeControl();
        moveIntake();

        //arm code
        armControl();
        
        //mogo up
        mogoMech();

        //control doinker
        leftDoinkerControl();
        rightDoinkerControl();

        //load the arm
        armLoadMacro();
        
        // if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
        //     chassis.moveToPoint(chassis.getPose().x - 3, chassis.getPose().y, 800, {.forwards = false, .maxSpeed = 65});
        // }
        // else if(master.get_digital_new_press(ARM_AUTO_DOWN_BUTTON)){
        //     chassis.moveToPoint(chassis.getPose().x + 3, chassis.getPose().y, 800, {.forwards = false, .maxSpeed = 65});
        // }
        // // delay to save resources
        // pros::delay(10); 

    } //end of while
}

