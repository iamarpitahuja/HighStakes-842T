#include "autos.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\devices.hpp"
#include "pidTuner.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\subsystemHeaderFiles\ladyBrown.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\subsystemHeaderFiles\distanceSense.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\subsystemHeaderFiles\intakeUnjam.hpp"
#include "cmath"
// #include "C:\Users\kc004\OneDrive\Desktop\tears-SKILLS\include\subsystemHeaderFiles\colorSort.hpp"
//#include <ladyBrown.hpp>

ASSET(awp1_txt);
ASSET(newCurve_txt);
ASSET(skills1_txt);

//global instance -- false piston is up, true piston is down
// lift_to_target_position(-200);
pidTuner gainScheduler;

void selector(int auton){
    switch(auton){
        case 0:
            worldsSkills();
            break;      
        case 1:
            blank();
            break;
    }
}

void worldsSkills(){    
    chassis.setPose(0,0,0);
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(0, 13.68, 500, {.maxSpeed = 110});
    intake.move(-127); 
    chassis.turnToHeading(-90, 500, {.maxSpeed = 100});
    pros::Task intakeUnjammer(intakeUnjam);
    chassis.moveToPoint(24, 13.98, 1000, {.forwards = false, .maxSpeed = 85}); 
    chassis.waitUntilDone();
    //CLAMP FIRST MOGO
    mogo.set_value(true);
    pros::delay(100);
    chassis.setPose(24, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(25.64, 37.53, 700, {.maxSpeed = 127});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntil(6);
    chassis.turnToHeading(37, 500, {.maxSpeed = 100});
    chassis.moveToPoint(49.09, 58.5, 1000, {.maxSpeed = 100});
    chassis.turnToHeading(90, 500, {.maxSpeed = 100});

    // chassis.moveToPose(57.09, 57.5, 88, 1200, {.lead = 0.2,.maxSpeed = 90}); //was 127
    chassis.waitUntil(12);
    lift_to_target_position(-78, 800, 15);
    intakeUnjammer.suspend();
    chassis.moveToPoint(67.0, 59, 900, {.maxSpeed = 90});
    //-60.5
    // chassis.setPose(60, chassis.getPose().y, chassis.getPose().theta);
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(100);
    intake.move(0);
    lift_to_target_position(-450, 800, 90);
    chassis.moveToPoint(50.86, 59.15, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-127);
    down_to_target_position(0, 800);
    chassis.turnToHeading(180, 700, {.maxSpeed = 80});
    chassis.waitUntilDone();
    printf("heading: %f\n", (double)chassis.getPose(true).theta);
    if(leftDist.get_confidence() >= 10){
        chassis.setPose(64.0-(getLeftDist()) * fabs(cos((chassis.getPose(true).theta))), chassis.getPose().y, chassis.getPose().theta);
    }
    // pros::delay(2000);
    //17.3, 67, 63.9, (17.1, 47.4, 64)
    //0.6
    printf("leftDist: %f\n", getLeftDist());
    printf("cosine scale: %f\n", getLeftDist()*(cos(chassis.getPose(true).theta)));
    printf("sensor confidence: %ld\n", leftDist.get_confidence());
    intakeUnjammer.resume();
    chassis.moveToPoint(49.28, 23.14, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.waitUntil(1);
    down_to_target_position(0, 800);
    chassis.moveToPoint(chassis.getPose().x, -0.16, 1000, {.maxSpeed = 95}); //was 70
    chassis.waitUntil(2);
    down_to_target_position(0, 800);
    chassis.waitUntil(5);
    intake.move(0);
    chassis.waitUntil(6);
    intake.move(127);
    chassis.swingToHeading(82, lemlib::DriveSide::RIGHT, 800, {.maxSpeed = 100});
    chassis.moveToPoint(57.43, 11.49, 800, {.maxSpeed = 90});
    chassis.turnToHeading(-25, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(60, 2.99, 800, {.forwards = false, .maxSpeed = 90});
    //unclamp
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    chassis.moveToPoint(50.6, 12.51, 800, {.maxSpeed = 120});
    chassis.waitUntil(5);
    intake.move(80);
    chassis.turnToHeading(-90, 600, {.maxSpeed = 100});
    chassis.waitUntilDone();
    //17.9, 63, 17.3, -3.4, -3.5, 
    if(leftDist.get_confidence() >= 10){
        chassis.setPose(chassis.getPose().x, -3.5+(getLeftDist()) * fabs(sin((chassis.getPose(true).theta))), chassis.getPose().theta);
    }
    printf("leftDist: %f\n", getLeftDist());
    printf("cosine scale: %f\n", getLeftDist()*fabs(sin(chassis.getPose(true).theta)));
    printf("sensor confidence: %ld\n", leftDist.get_confidence());
    chassis.moveToPoint(-2.09, chassis.getPose().y, 1500, {.maxSpeed = 115});
    chassis.turnToHeading(90, 1000, {.maxSpeed = 100});
    intake.move(-80);
    chassis.moveToPoint(-23.1, chassis.getPose().y, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    //CLAMP SECOND MOGO
    mogo.set_value(true);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.moveToPoint(-23.1, 31.45, 800, {.maxSpeed = 127});
    chassis.turnToHeading(-38, 500, {.maxSpeed = 100});
    chassis.moveToPoint(-48, 60.0, 1000, {.maxSpeed = 100});
    chassis.turnToHeading(-90, 500, {.maxSpeed = 100});
    // chassis.moveToPose(-57, 58.0, -90, 1500, {.lead = 0.2,.maxSpeed = 95}); //was 57.3
    chassis.waitUntil(12);
    lift_to_target_position(-78, 800, 15); //-68
    intakeUnjammer.suspend();
    //3.1, -61, 
    chassis.moveToPoint(-67.0, 60.0, 900, {.maxSpeed = 105});
    chassis.waitUntilDone();
    // chassis.setPose(-60, chassis.getPose().y, chassis.getPose().theta);
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(200);
    intake.move(0);
    lift_to_target_position(-550, 700, 100);
    //-51
    chassis.moveToPoint(-49.86, 57, 1000, {.forwards = false, .maxSpeed = 100});
    //17.5, -47.6, -49.7, 16.8
    chassis.waitUntil(5);
    intake.move(-127);
    //
    down_to_target_position(0, 800);
    chassis.turnToHeading(-180, 800, {.maxSpeed = 80});
    chassis.waitUntilDone();
    printf("heading: %f\n", (double)chassis.getPose(true).theta);
    if(rightDist.get_confidence() >= 10){
        chassis.setPose(-66.5+(getRightDist()) * fabs(cos((chassis.getPose(true).theta))), chassis.getPose().y, chassis.getPose().theta);
    }
    // pros::delay(2000);
    //17.3, 67, 63.9, (17.1, 47.4, 64)
    //0.6
    printf("leftDist: %f\n", getRightDist());
    printf("cosine scale: %f\n", getRightDist()*(cos(chassis.getPose(true).theta)));
    printf("sensor confidence: %ld\n", rightDist.get_confidence());
    intakeUnjammer.resume();
    chassis.moveToPoint(-48.71, 19.51, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.waitUntil(1);
    down_to_target_position(0, 800);
    chassis.moveToPoint(chassis.getPose().x, -0.5, 1000, {.maxSpeed = 95}); //was 65
    chassis.waitUntil(1);
    down_to_target_position(0, 800);
    chassis.swingToHeading(-86, lemlib::DriveSide::LEFT, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-57.07, 11.82, 800, {.maxSpeed = 90});
    chassis.turnToHeading(25, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-60, 0, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    chassis.moveToPoint(-48.72, 9.75, 800, {.maxSpeed = 127});
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.waitUntilDone();
    //17.2, -49.6, 
    if(leftDist.get_confidence() >= 10){
        chassis.setPose(-66.5+(getLeftDist()) * fabs(cos((chassis.getPose(true).theta))), chassis.getPose().y, chassis.getPose().theta);
    }
    printf("leftDist: %f\n", getLeftDist());
    printf("cosine scale: %f\n", getLeftDist()*fabs(cos(chassis.getPose(true).theta)));
    printf("sensor confidence: %ld\n", leftDist.get_confidence());
    intakeUnjammer.suspend();
    intake.move(127);
    chassis.moveToPoint(-48.12, 82.73, 1800, {.maxSpeed = 100});
    // chassis.waitUntil(40);
    chassis.waitUntilDone();
    if(leftDist.get_confidence() >= 10){
        chassis.setPose(-66.5+(getLeftDist()) * fabs(cos((chassis.getPose(true).theta))), chassis.getPose().y, chassis.getPose().theta);
    }
    lift_to_target_position(-75, 400, 15);
    chassis.turnToHeading(90, 800, {.maxSpeed = 100});
    intake.move(127);
    chassis.moveToPoint(-26.8, 82.34, 1000, {.maxSpeed = 120});
    chassis.waitUntil(8);
    intake.move(0);
    chassis.waitUntil(10);
    lift_to_target_position(-200, 600, 40);
    intake.move(80);
    chassis.turnToHeading(180, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-26.8, 117.34, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntil(2);
    intake.move(0);
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(105, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-55.41, 123.06, 1000, {.forwards = false, .maxSpeed = 90});
    mogo.set_value(false);
    chassis.moveToPoint(-23.93, 114.52, 1000, {.maxSpeed = 127});
    chassis.turnToHeading(-58, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-2.65, 109.67, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    //0.83, 123, 90
    chassis.moveToPoint(-2.65, 127, 800, {.maxSpeed = 95});
    chassis.waitUntilDone();
    //3.77, 121.865, 123.733, 3.43
    if(frontDist.get_confidence() >= 10){
        chassis.setPose(chassis.getPose().x, 123.73+(getFrontDist()) * fabs(cos((chassis.getPose(true).theta))), chassis.getPose().theta);
    }
    printf("leftDist: %f\n", getFrontDist());
    printf("cosine scale: %f\n", getFrontDist()*fabs(sin(chassis.getPose(true).theta)));
    printf("sensor confidence: %ld\n", frontDist.get_confidence());
    //y is 114.5
    chassis.moveToPoint(chassis.getPose().x, 117.5, 800, {.forwards = false, .maxSpeed = 110});
    chassis.waitUntilDone();
    lift_to_target_position(-550, 800, 90);
    //108
    chassis.moveToPoint(chassis.getPose().x, 109, 600, {.forwards = false, .maxSpeed = 127});
    chassis.turnToHeading(133, 800, {.maxSpeed = 100});
    //20.5, 87.3
    chassis.moveToPoint(20.5, 87.3, 800, {.maxSpeed = 127});
    chassis.waitUntil(5);
    down_to_target_position(0, 800);
    chassis.waitUntil(7);
    intake.move(127);
    //90 y is same
    chassis.turnToHeading(90, 800, {.maxSpeed = 100});
    //44
    chassis.moveToPoint(44, chassis.getPose().y, 800, {.maxSpeed = 127});
    //turn to 0
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(chassis.getPose().x, 117, 800, {.maxSpeed = 127});
    //43.5, 113
    //90
    //55, y is same
    //-140
    

}

void realSkills(){
    chassis.setPose(0,0,0);
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(0, 13.18, 500, {.maxSpeed = 110});
    intake.move(-127); 
    chassis.turnToHeading(-88, 500, {.maxSpeed = 100});
    chassis.moveToPoint(22.8, 13.18, 1000, {.forwards = false, .maxSpeed = 110}); 
    chassis.waitUntilDone();
    //CLAMP FIRST MOGO
    mogo.set_value(true);
    pros::delay(100);
    chassis.setPose(22.8, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(25.64, 37.53, 700, {.maxSpeed = 127});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntil(6);
    chassis.turnToHeading(50, 500, {.maxSpeed = 100});
    chassis.moveToPose(57.09, 58, 90, 1200, {.lead = 0.2,.maxSpeed = 105}); //was 127
    chassis.waitUntil(12);
    lift_to_target_position(-68, 800, 15);
    chassis.moveToPoint(66.0, 58, 800, {.maxSpeed = 127});
    chassis.waitUntilDone();
    pros::delay(500);
    intake.move(0);
    lift_to_target_position(-550, 800, 90);
    chassis.moveToPoint(49.86, 59.15, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-80);
    down_to_target_position(0, 800);
    chassis.turnToHeading(180, 800, {.maxSpeed = 80});
    //50.28, -0.16
    chassis.moveToPoint(49.28, 23.14, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.moveToPoint(chassis.getPose().x, -0.16, 1000, {.maxSpeed = 95}); //was 70
    //82
    chassis.swingToHeading(82, lemlib::DriveSide::RIGHT, 800, {.maxSpeed = 100});
    //57.43, 11.49
    chassis.moveToPoint(57.43, 11.49, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(-27, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(61.7, 3.99, 800, {.forwards = false, .maxSpeed = 90});
    //unclamp
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //50.6, 10.4
    chassis.moveToPoint(50.6, 10.76, 800, {.maxSpeed = 120});
    chassis.waitUntil(5);
    intake.move(80);
    //90
    chassis.turnToHeading(-90, 600, {.maxSpeed = 100});
    //-2.09, 10.61
    chassis.moveToPoint(-2.09, 10.61, 1500, {.maxSpeed = 115});
    //-90
    chassis.turnToHeading(90, 1000, {.maxSpeed = 100});
    intake.move(-80);
    //-20.35, 10.61
    chassis.moveToPoint(-23.1, 10.61, 800, {.forwards = false, .maxSpeed = 110});
    //0
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.waitUntil(3);
    intake.move(127);
    //-23.1, 31.45
    chassis.moveToPoint(-23.1, 31.45, 800, {.maxSpeed = 127});
    //-52
    chassis.turnToHeading(-52, 500, {.maxSpeed = 100});
    //-56.92, 55.64, -90
    chassis.moveToPose(-57, 57.5, -90, 1500, {.lead = 0.2,.maxSpeed = 80}); //was -63
    chassis.waitUntil(12);
    lift_to_target_position(-67, 800, 15);

    chassis.moveToPoint(-66.0, 57.5, 900, {.maxSpeed = 127});
    chassis.waitUntilDone();
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(200);
    intake.move(0);
    lift_to_target_position(-550, 700, 100);
    //-51
    chassis.moveToPoint(-49.86, 57, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-80);
    down_to_target_position(0, 800);
    chassis.turnToHeading(-180, 800, {.maxSpeed = 80});
    down_to_target_position(0, 800);
    
    //-48.71, 19.51
    //-48.08, -0.5    
    chassis.moveToPoint(-48.71, 19.51, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.moveToPoint(chassis.getPose().x, -0.5, 1000, {.maxSpeed = 95}); //was 65
    chassis.swingToHeading(-86, lemlib::DriveSide::LEFT, 800, {.maxSpeed = 100});
    //-57.07, 11.82, 
    chassis.moveToPoint(-57.07, 11.82, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(25, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(-60, 0, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //-49.72, 9.75
    chassis.moveToPoint(-49.72, 9.75, 800, {.maxSpeed = 127});
    //0
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    intake.move(127);
    //-51.6, 82.73
    chassis.moveToPoint(-47.12, 75, 1800, {.maxSpeed = 120, .minSpeed = 80, .earlyExitRange = .2});
    chassis.waitUntil(40);
    lift_to_target_position(-73, 800, 15);
    chassis.moveToPoint(-47.12, 82.73, 900, {.maxSpeed = 100});
    //-105
    chassis.turnToHeading(-105, 800, {.maxSpeed = 100});
    chassis.moveToPoint(0.5, 105.56, 1600, {.forwards = false, .maxSpeed = 80}); //was 1500, 80
    chassis.waitUntil(3);
    intake.move(75);
    chassis.waitUntilDone();
    mogo.set_value(true);
    intake.move(0);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});

    chassis.moveToPoint(0.65, 127, 1000, {.maxSpeed = 90});
    intake.move(127);
    //reset to 118
    chassis.waitUntilDone();
    pros::delay(50);
    chassis.setPose(chassis.getPose().x, 117, chassis.getPose().theta);
    //112.5
    chassis.moveToPoint(0, 109, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(2);
    intake.move(0);
    chassis.waitUntilDone();
    lift_to_target_position(-550, 700, 50);
    //99.76, 
    chassis.moveToPoint(chassis.getPose().x, 99.76, 800, {.forwards = false, .maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(-80);
    chassis.waitUntil(3);
    down_to_target_position(0, 800);
    chassis.turnToHeading(84, 800, {.maxSpeed = 100});
    // 46.4, 104.16
    chassis.moveToPoint(48.0, 104.16, 1000, {.maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(127);
    //170
    chassis.turnToHeading(170, 800, {.maxSpeed = 100});
    //47.27, 80.77
    chassis.moveToPoint(47.27, 78.77, 800, {.maxSpeed = 127});
    //270
    chassis.turnToHeading(270, 800, {.maxSpeed = 100});
    //15.95, y is same
    chassis.moveToPoint(24.95, chassis.getPose().y, 800, {.maxSpeed = 127});
    //-134
    chassis.turnToHeading(228, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-3.04, 54.53, 1000, {.maxSpeed = 110});
    //305, 
    chassis.turnToHeading(315, 800, {.maxSpeed = 100});
    //-27.6, 80.11, 
    chassis.moveToPoint(-27.6, 80.11, 800, {.maxSpeed = 127});
    //310
    chassis.turnToHeading(310, 200, {.maxSpeed = 100});
    //-61.14, 97.97
    chassis.moveToPoint(-59.14, 97.97, 1000, {.maxSpeed = 110});
    //left doinker out
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(true);
    //516
    chassis.turnToHeading(175, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed = 100});
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(false);
    //-64.85, 105.19
    chassis.moveToPoint(-64.85, 105.19, 800, {.forwards = false, .maxSpeed = 110});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    chassis.moveToPoint(-58.83, 90.14, 500, {.maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.tank(-120,-120);
    pros::delay(400);
    // chassis.moveToPoint(-65.53, 115, 700, {.forwards = false, .maxSpeed = 127});
    chassis.moveToPoint(-53.77, 84.25, 1000, {.maxSpeed = 115});
    chassis.turnToHeading(240, 700, {.maxSpeed = 100});
    chassis.moveToPoint(23.0, 114.5, 1500, {.forwards = false, .maxSpeed = 127});
    // chassis.waitUntil(10);
    // mogo.set_value(true);
    chassis.turnToHeading(-90, 300, {.maxSpeed = 100});
    intake.move(-60);
    chassis.moveToPoint(66, 116, 1000, {.forwards = false, .maxSpeed = 120});
    chassis.turnToHeading(220, 800, {.maxSpeed = 100});
    // chassis.waitUntilDone();
    // chassis.tank(-100,-100);
    // pros::delay(100);
    chassis.tank(50,50);


    //22.43, 77.07
    // chassis.moveToPoint(22.43, 77.07, 800, {.forwards = false, .maxSpeed = 127});
    // chassis.waitUntil(10);
    // lift_to_target_position(-400, 800, 50);
    // //tank 70
    // chassis.waitUntilDone();
    // chassis.tank(-60,-60);
    // pros::delay(1000);
    // chassis.tank(60, 60);



}


void firstDaySKILLS(){

    chassis.setPose(0,0,0);
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(0, 13.18, 500, {.maxSpeed = 110});
    intake.move(-127); 
    chassis.turnToHeading(-88, 500, {.maxSpeed = 100});
    chassis.moveToPoint(22.8, 13.18, 1000, {.forwards = false, .maxSpeed = 110}); 
    chassis.waitUntilDone();
    //CLAMP FIRST MOGO
    mogo.set_value(true);
    pros::delay(100);
    chassis.setPose(22.8, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(25.64, 37.53, 700, {.maxSpeed = 127});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntil(6);
    chassis.turnToHeading(50, 500, {.maxSpeed = 100});
    chassis.moveToPose(57.09, 57.5, 88, 1200, {.lead = 0.2,.maxSpeed = 90}); //was 127
    chassis.waitUntil(12);
    lift_to_target_position(-68, 800, 15);
    chassis.moveToPoint(67.0, 59, 800, {.maxSpeed = 117});
    chassis.waitUntilDone();
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(100);
    intake.move(0);
    lift_to_target_position(-500, 800, 90);
    chassis.moveToPoint(49.86, 59.15, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-80);
    down_to_target_position(0, 800);
    chassis.turnToHeading(180, 700, {.maxSpeed = 80});
    //50.28, -0.16
    chassis.moveToPoint(49.28, 23.14, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.moveToPoint(chassis.getPose().x, -0.16, 1000, {.maxSpeed = 95}); //was 70
    //82
    chassis.swingToHeading(82, lemlib::DriveSide::RIGHT, 800, {.maxSpeed = 100});
    //57.43, 11.49
    chassis.moveToPoint(57.43, 11.49, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(-27, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(61.7, 3.99, 800, {.forwards = false, .maxSpeed = 90});
    //unclamp
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //50.6, 10.4
    chassis.moveToPoint(50.6, 11.0, 800, {.maxSpeed = 120});
    chassis.waitUntil(5);
    intake.move(80);
    //90
    chassis.turnToHeading(-90, 600, {.maxSpeed = 100});
    //-2.09, 10.61
    chassis.moveToPoint(-2.09, 11.0, 1500, {.maxSpeed = 115});
    //-90
    chassis.turnToHeading(90, 1000, {.maxSpeed = 100});
    intake.move(-80);
    //-20.35, 10.61
    chassis.moveToPoint(-23.1, 10.61, 800, {.forwards = false, .maxSpeed = 110});
    //0
    chassis.waitUntilDone();
    mogo.set_value(true);

    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.waitUntil(3);
    intake.move(127);
    //-23.1, 31.45
    chassis.moveToPoint(-23.1, 31.45, 800, {.maxSpeed = 127});
    //-52
    chassis.turnToHeading(-52, 500, {.maxSpeed = 100});
    //-56.92, 55.64, -90
    chassis.moveToPose(-57, 57.5, -90, 1500, {.lead = 0.2,.maxSpeed = 80}); //was -63
    chassis.waitUntil(12);
    lift_to_target_position(-67, 800, 15);
    chassis.moveToPoint(-66.0, 59, 900, {.maxSpeed = 127});
    chassis.waitUntilDone();
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(200);
    intake.move(0);
    lift_to_target_position(-550, 700, 100);
    //-51
    chassis.moveToPoint(-49.86, 57, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-80);
    down_to_target_position(0, 800);
    chassis.turnToHeading(-180, 800, {.maxSpeed = 80});
    down_to_target_position(0, 800);
    chassis.moveToPoint(-48.71, 19.51, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.moveToPoint(chassis.getPose().x, -0.5, 1000, {.maxSpeed = 95}); //was 65
    chassis.swingToHeading(-86, lemlib::DriveSide::LEFT, 800, {.maxSpeed = 100});
    //-57.07, 11.82, 
    chassis.moveToPoint(-57.07, 11.82, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(25, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(-60, 0, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //-49.72, 9.75
    chassis.moveToPoint(-49.72, 9.75, 800, {.maxSpeed = 127});
    //0
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    intake.move(127);
    //-51.6, 82.73
    chassis.moveToPoint(-48.12, 75, 1800, {.maxSpeed = 120, .minSpeed = 80, .earlyExitRange = .2});
    chassis.waitUntil(40);
    lift_to_target_position(-73, 800, 15);
    chassis.moveToPoint(-48.12, 82.73, 500, {.maxSpeed = 100});
    //-105
    chassis.turnToHeading(-105, 800, {.maxSpeed = 100});
    chassis.moveToPoint(1.5, 105.56, 1600, {.forwards = false, .maxSpeed = 80}); //was 1500, 80
    chassis.waitUntil(3);
    intake.move(20);
    chassis.waitUntilDone();
    mogo.set_value(true);
    intake.move(0);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(1.65, 127, 900, {.maxSpeed = 65});
    intake.move(127);
    //reset to 118
    chassis.waitUntilDone();
    pros::delay(50);
    chassis.setPose(chassis.getPose().x, 117, chassis.getPose().theta);
    intake.move(5);
    //112.5
    chassis.moveToPoint(chassis.getPose().x, 109, 1000, {.forwards = false, .maxSpeed = 100});
    // chassis.waitUntil(2);
    // intake.move(0);
    chassis.waitUntilDone();
    lift_to_target_position(-550, 700, 50);
    
    //99.76, 
    chassis.moveToPoint(chassis.getPose().x, 99.76, 800, {.forwards = false, .maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(-80);
    chassis.waitUntil(3);
    down_to_target_position(0, 800);
    chassis.turnToHeading(86, 800, {.maxSpeed = 100});
    // 46.4, 104.16
    chassis.moveToPoint(48.0, 100.16, 1000, {.maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(127);
    //170
    chassis.turnToHeading(170, 800, {.maxSpeed = 100});
    //47.27, 80.77
    chassis.moveToPoint(47.27, 78.77, 800, {.maxSpeed = 127});
    //270
    chassis.turnToHeading(270, 800, {.maxSpeed = 100});
    //15.95, y is same
    chassis.moveToPoint(24.95, chassis.getPose().y, 800, {.maxSpeed = 127});
    //-134
    chassis.turnToHeading(228, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-3.04, 54.53, 1000, {.maxSpeed = 110});
    //305, 
    chassis.turnToHeading(315, 800, {.maxSpeed = 100});
    //-27.6, 80.11, 
    chassis.moveToPoint(-27.6, 80.11, 800, {.maxSpeed = 127});
    //310
    chassis.turnToHeading(310, 200, {.maxSpeed = 100});
    //-61.14, 97.97
    chassis.moveToPoint(-59.14, 98.97, 1000, {.maxSpeed = 110});
    //left doinker out
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(true);
    chassis.turnToHeading(0, 200, {.maxSpeed = 100});
    chassis.moveToPoint(-59.14, 115, 700, {.maxSpeed = 127});
    //516
    chassis.turnToHeading(180, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed = 100});
    chassis.waitUntilDone();
    intake.move(-80);
    leftDoinkerMech.set_value(false);
    //-64.85, 105.19
    chassis.moveToPoint(-64.85, 105.19, 800, {.forwards = false, .maxSpeed = 110});
    mogo.set_value(false);
    chassis.waitUntilDone();
    chassis.tank(-127,-127, true);
    pros::delay(350);
    // chassis.moveToPoint(-62.53, 112, 700, {.forwards = false, .maxSpeed = 127});
    chassis.moveToPoint(-53.77, 84.25, 1000, {.maxSpeed = 115});
    chassis.turnToHeading(235, 700, {.maxSpeed = 100});
    chassis.moveToPoint(5.0, 113.0, 1500, {.forwards = false, .maxSpeed = 127}); //23, 105
    intake.move(127);
    // chassis.waitUntil(10);
    // mogo.set_value(true);
    chassis.turnToHeading(-105, 300, {.maxSpeed = 100}); //-95
    intake.move(-40);
    chassis.moveToPoint(54.0, 125.0, 1000, {.forwards = false, .maxSpeed = 80}); //56, 120.5
    chassis.waitUntil(10);
    mogo.set_value(true);
    chassis.waitUntilDone();    
    mogo.set_value(false);
    // chassis.turnToHeading(220, 800, {.maxSpeed = 100});
    // chassis.waitUntilDone();
    chassis.tank(-120,-100, true);
    pros::delay(400);
    chassis.tank(30,30, true);
    //47, 106.9



}



void newSkills(){
    chassis.setPose(0,0,0);
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(0, 13.18, 500, {.maxSpeed = 110});
    intake.move(-127); 
    chassis.turnToHeading(-88, 500, {.maxSpeed = 100});
    chassis.moveToPoint(22.8, 13.18, 1000, {.forwards = false, .maxSpeed = 110}); 
    chassis.waitUntilDone();
    //CLAMP FIRST MOGO
    mogo.set_value(true);
    pros::delay(100);
    chassis.setPose(22.8, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(25.64, 37.53, 700, {.maxSpeed = 127});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntil(6);
    chassis.turnToHeading(50, 500, {.maxSpeed = 100});
    chassis.moveToPose(57.09, 57.5, 88, 1200, {.lead = 0.2,.maxSpeed = 90}); //was 127
    chassis.waitUntil(12);
    lift_to_target_position(-68, 800, 15);
    chassis.moveToPoint(67.0, 59, 800, {.maxSpeed = 127});
    chassis.waitUntilDone();
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(100);
    intake.move(0);
    lift_to_target_position(-500, 800, 90);
    chassis.moveToPoint(49.86, 59.15, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-80);
    down_to_target_position(0, 800);
    chassis.turnToHeading(180, 700, {.maxSpeed = 80});
    //50.28, -0.16
    chassis.moveToPoint(49.28, 23.14, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.moveToPoint(chassis.getPose().x, -0.16, 1000, {.maxSpeed = 95}); //was 70
    //82
    chassis.swingToHeading(82, lemlib::DriveSide::RIGHT, 800, {.maxSpeed = 100});
    //57.43, 11.49
    chassis.moveToPoint(57.43, 11.49, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(-27, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(61.7, 3.99, 800, {.forwards = false, .maxSpeed = 90});
    //unclamp
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //50.6, 10.4
    chassis.moveToPoint(50.6, 10.76, 800, {.maxSpeed = 120});
    chassis.waitUntil(5);
    intake.move(80);
    //90
    chassis.turnToHeading(-90, 600, {.maxSpeed = 100});
    //-2.09, 10.61
    chassis.moveToPoint(-2.09, 10.61, 1500, {.maxSpeed = 115});
    //-90
    chassis.turnToHeading(90, 1000, {.maxSpeed = 100});
    intake.move(-80);
    //-20.35, 10.61
    chassis.moveToPoint(-23.1, 10.61, 800, {.forwards = false, .maxSpeed = 110});
    //0
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.waitUntil(3);
    intake.move(127);
    //-23.1, 31.45
    chassis.moveToPoint(-23.1, 43, 800, {.maxSpeed = 127}); 
    //-63
    chassis.turnToHeading(-63, 800, {.maxSpeed = 100});
    //-56.44, 55.77
    chassis.moveToPoint(-56.44, 55.77, 800, {.maxSpeed = 127}); 
    //-195
    chassis.turnToHeading(-195, 800, {.maxSpeed = 100});
    //-48.71, 19.51
    //-48.08, -0.5    
    chassis.moveToPoint(-48.71, 19.51, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.turnToHeading(-180, 500, {.maxSpeed = 100});
    chassis.moveToPoint(chassis.getPose().x, -0.5, 1000, {.maxSpeed = 95}); //was 65
    chassis.swingToHeading(-86, lemlib::DriveSide::LEFT, 800, {.maxSpeed = 100});
    //-57.07, 11.82, 
    chassis.moveToPoint(-57.07, 11.82, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(25, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(-60, 0, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //-49.72, 9.75
    chassis.moveToPoint(-49.72, 9.75, 800, {.maxSpeed = 127});
    //0
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    intake.move(127);
    //-51.6, 82.73
    chassis.moveToPoint(-48.12, 75, 1800, {.maxSpeed = 120, .minSpeed = 80, .earlyExitRange = .2});
    chassis.waitUntil(40);
    lift_to_target_position(-73, 800, 15);
    chassis.moveToPoint(-48.12, 82.73, 500, {.maxSpeed = 100});
    //-105
    chassis.turnToHeading(-105, 800, {.maxSpeed = 100});
    chassis.moveToPoint(1.5, 105.56, 1600, {.forwards = false, .maxSpeed = 80}); //was 1500, 80
    chassis.waitUntil(3);
    intake.move(75);
    chassis.waitUntilDone();
    mogo.set_value(true);
    intake.move(0);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(1.65, 127, 900, {.maxSpeed = 65});
    intake.move(127);
    //reset to 118
    chassis.waitUntilDone();
    pros::delay(50);
    chassis.setPose(chassis.getPose().x, 117, chassis.getPose().theta);
    //112.5
    chassis.moveToPoint(chassis.getPose().x, 109, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(2);
    intake.move(0);
    chassis.waitUntilDone();
    lift_to_target_position(-550, 700, 50);
    
    //99.76, 
    chassis.moveToPoint(chassis.getPose().x, 99.76, 800, {.forwards = false, .maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(-80);
    chassis.waitUntil(3);
    down_to_target_position(0, 800);
    chassis.turnToHeading(86, 800, {.maxSpeed = 100});
    // 46.4, 104.16
    chassis.moveToPoint(48.0, 100.16, 1000, {.maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(127);
    //170
    chassis.turnToHeading(170, 800, {.maxSpeed = 100});
    //47.27, 80.77
    chassis.moveToPoint(47.27, 78.77, 800, {.maxSpeed = 127});
    //270
    chassis.turnToHeading(270, 800, {.maxSpeed = 100});
    //15.95, y is same
    chassis.moveToPoint(24.95, chassis.getPose().y, 800, {.maxSpeed = 127});
    //-134
    chassis.turnToHeading(228, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-3.04, 54.53, 1000, {.maxSpeed = 110});
    //305, 
    chassis.turnToHeading(315, 800, {.maxSpeed = 100});
    //-27.6, 80.11, 
    chassis.moveToPoint(-27.6, 80.11, 800, {.maxSpeed = 127});
    //310
    chassis.turnToHeading(310, 200, {.maxSpeed = 100});
    //-61.14, 97.97
    chassis.moveToPoint(-59.14, 98.97, 1000, {.maxSpeed = 110});
    //left doinker out
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(true);
    chassis.turnToHeading(0, 200, {.maxSpeed = 100});
    chassis.moveToPoint(-59.14, 115, 700, {.maxSpeed = 127});
    //516
    chassis.turnToHeading(180, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed = 100});
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(false);
    //-64.85, 105.19
    chassis.moveToPoint(-64.85, 105.19, 800, {.forwards = false, .maxSpeed = 110});
    mogo.set_value(false);
    chassis.waitUntilDone();
    chassis.tank(-100,-100, true);
    pros::delay(300);
    intake.move(-80);
    // chassis.moveToPoint(-62.53, 112, 700, {.forwards = false, .maxSpeed = 127});
    chassis.moveToPoint(-53.77, 84.25, 1000, {.maxSpeed = 115});
    chassis.turnToHeading(235, 700, {.maxSpeed = 100});
    chassis.moveToPoint(5.0, 113.0, 1500, {.forwards = false, .maxSpeed = 127}); //23, 105
    intake.move(127);
    // chassis.waitUntil(10);
    // mogo.set_value(true);
    chassis.turnToHeading(-105, 300, {.maxSpeed = 100}); //-95
    intake.move(-40);
    chassis.moveToPoint(54.0, 125.0, 1000, {.forwards = false, .maxSpeed = 100}); //56, 120.5
    // chassis.waitUntil(10);
    // mogo.set_value(true);
    chassis.waitUntilDone();    
    // mogo.set_value(false);
    chassis.turnToHeading(220, 800, {.maxSpeed = 100});
    // chassis.waitUntilDone();
    // chassis.tank(-100,-100);
    // pros::delay(100);
    //47, 106.9
    chassis.moveToPoint(47, 106.9, 800, {.maxSpeed = 90, .minSpeed = 60, .earlyExitRange = 1});
    //22.95, 87.2
    chassis.moveToPoint(22.95, 87.2, 1000, {.maxSpeed = 127});
    chassis.waitUntil(2);
    lift_to_target_position(-400, 800, 50);
    //50
    chassis.turnToHeading(50, 800, {.maxSpeed = 100});
    chassis.waitUntilDone();
    chassis.tank(-70, -70, true);
    pros::delay(800);
    chassis.tank(100, 100, true);
    //22.43, 77.07
    chassis.moveToPoint(22.43, 70.07, 800, {.forwards = false, .maxSpeed = 127});
    chassis.waitUntil(10);
    lift_to_target_position(-400, 800, 50);
    //tank 70
    chassis.waitUntilDone();
    chassis.tank(-15,-15, true);
    pros::delay(350); //800
    chassis.cancelMotion();
    down_to_target_position(-170, 800);
    intakePis.set_value(false);
    chassis.tank(60, 60, true);
}


void skills(){
    chassis.setPose(0,0,0);
    intake.move(127);
    pros::delay(500);
    chassis.moveToPoint(0, 13.18, 500, {.maxSpeed = 110});
    intake.move(-127); 
    chassis.turnToHeading(-88, 500, {.maxSpeed = 100});
    chassis.moveToPoint(22.8, 13.18, 1000, {.forwards = false, .maxSpeed = 110}); 
    chassis.waitUntilDone();
    //CLAMP FIRST MOGO
    mogo.set_value(true);
    pros::delay(100);
    chassis.setPose(22.8, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(25.64, 37.53, 700, {.maxSpeed = 127});
    chassis.waitUntil(4);
    intake.move(127);
    chassis.turnToHeading(50, 500, {.maxSpeed = 100});
    chassis.moveToPoint(57.71, 60.85, 1000, {.maxSpeed = 120});
    chassis.turnToHeading(203, 500, {.maxSpeed = 100});
    chassis.moveToPose(47.95, 37.82, 180, 1200, {.lead = 0.3,.maxSpeed = 127});
    chassis.moveToPoint(49.07, 3.47, 2500, {.maxSpeed = 110});
    chassis.waitUntil(3);
    intake.move(-127);
    chassis.waitUntil(6);
    intake.move(127);
    chassis.swingToHeading(90, lemlib::DriveSide::RIGHT, 900, {.maxSpeed = 100});
    chassis.moveToPoint(59.23, 12.98, 800, {.maxSpeed = 115});
    chassis.turnToHeading(-30, 800, {.maxSpeed = 80});
    chassis.moveToPoint(62.73, 2.63, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntil(4);
    intake.move(-127);
    chassis.waitUntilDone();
    mogo.set_value(false);
    //FIRST MOGO IN CORNER
    chassis.moveToPoint(52.46, 12.29, 800, {.maxSpeed = 110});
    intake.move(127);
    chassis.turnToHeading(-90, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-4.35, 10.53, 1800, {.maxSpeed = 110});
    chassis.turnToHeading(90, 800, {.maxSpeed = 100});
    intake.move(-90);
    chassis.moveToPoint(-20.88, 10.97, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(true);
    // PICK SECOND MOGO
    chassis.setPose(-20.88, 10.97, chassis.getPose().theta);
    pros::delay(100);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-20.88, 39, 800, {.maxSpeed = 127});
    chassis.waitUntil(4);
    intake.move(120);
    chassis.turnToHeading(-57, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-55.29, 59.53, 1250, {.maxSpeed = 127});
    chassis.turnToHeading(-200, 800, {.maxSpeed = 100});
    chassis.moveToPose(-46.99, 39.84, -180, 1200, {.lead = 0.3, .maxSpeed = 127});
    chassis.moveToPoint(-47, 3.04, 2500, {.maxSpeed = 100});
    chassis.waitUntil(3);
    intake.move(-127);
    chassis.waitUntil(6);
    intake.move(127);
    chassis.swingToHeading(-90, lemlib::DriveSide::LEFT, 900, {.maxSpeed = 100});
    chassis.moveToPoint(-55.77, 15.12, 800, {.maxSpeed = 110});
    chassis.turnToHeading(26, 800, {.maxSpeed = 80});
    chassis.moveToPoint(-59.32, 4.51, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    intake.move(-127);
    mogo.set_value(false);
    //SECOND MOGO IN CORNER
    chassis.moveToPoint(-48.53,7.29, 500, { .maxSpeed = 115});
    chassis.waitUntil(5);
    intake.move(120);
    chassis.turnToHeading(7, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-42, 61.59, 1500, {.maxSpeed = 110}); //-39.97
    chassis.turnToHeading(43, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-16.26, 87.43, 1300, {.maxSpeed = 80});
    chassis.turnToHeading(220, 800, {.maxSpeed = 100});
    intake.move(0);
    chassis.moveToPoint(10.02, 110.51, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(4);
    intake.move(-10);
    chassis.waitUntilDone();
    mogo.set_value(true);
    //CLAMP THIRD MOGO
    chassis.setPose(10.02, 110.51, chassis.getPose().theta);
    pros::delay(100);
    chassis.turnToHeading(148, 700, {.maxSpeed = 100});
    chassis.moveToPoint(27.33, 86.89, 1000, {.maxSpeed = 127});
    chassis.waitUntil(5);
    intake.move(120);
    chassis.turnToHeading(90, 700, {.maxSpeed = 100});
    chassis.moveToPoint(50.77, 87.43, 1000, {.maxSpeed = 127});
    chassis.turnToHeading(207, 1200, {.maxSpeed = 100});
    chassis.moveToPoint(65.37, 120.37, 1000, {.forwards = false, .maxSpeed = 120});
    chassis.waitUntilDone();
    intake.move(-20);
    mogo.set_value(false);
    chassis.moveToPoint(52.06, 110.26, 800, { .maxSpeed = 110});
    chassis.moveToPoint(67.07, 123.9, 1200, {.forwards = false, .maxSpeed = 105});
    chassis.waitUntilDone();
    chassis.moveToPoint(44.94, 98.52, 800, { .maxSpeed = 110});
    chassis.turnToHeading(125, 500, {.maxSpeed = 100});
    mogo.set_value(true);
    
    chassis.moveToPoint(-53.48, 128, 3000, {.forwards = false, .maxSpeed = 115});
    chassis.waitUntil(3);
    intake.move(0);
    chassis.waitUntilDone();
    mogo.set_value(false);
    chassis.tank(-70, -70);
    pros::delay(300);
    chassis.tank(60, 60);

}

void blank() {
    chassis.setPose(0,0,90);
    /*
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(0, 13.18, 500, {.maxSpeed = 110});
    intake.move(-127); 
    chassis.turnToHeading(-88, 500, {.maxSpeed = 100});
    chassis.moveToPoint(22.8, 13.18, 1000, {.forwards = false, .maxSpeed = 110}); 
    chassis.waitUntilDone();
    //CLAMP FIRST MOGO
    mogo.set_value(true);
    pros::delay(100);
    chassis.setPose(22.8, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(25.64, 37.53, 700, {.maxSpeed = 127});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntil(6);
    lift_to_target_position(-68, 800, 15);
    chassis.turnToHeading(50, 500, {.maxSpeed = 100});
    chassis.moveToPose(57.09, 58, 90, 1200, {.lead = 0.2,.maxSpeed = 127});
    chassis.waitUntil(12);
    lift_to_target_position(-200, 800, 15);
    //lift_to_target_position(-68, 800, 15);
    chassis.moveToPoint(66.0, 58, 800, {.maxSpeed = 127});
    chassis.waitUntilDone();
    pros::delay(500);
    intake.move(0);
    lift_to_target_position(-550, 800, 60);
    chassis.moveToPoint(49.86, 59.15, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-80);
    down_to_target_position(0, 800);
    chassis.turnToHeading(180, 800, {.maxSpeed = 80});
    down_to_target_position(0, 800);
    //50.28, -0.16
    chassis.moveToPoint(49.28, 23.14, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.moveToPoint(chassis.getPose().x, -0.16, 1000, {.maxSpeed = 65});
    //82
    chassis.swingToHeading(82, lemlib::DriveSide::RIGHT, 800, {.maxSpeed = 100});
    //57.43, 11.49
    chassis.moveToPoint(57.43, 11.49, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(-27, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(61.7, 3.99, 800, {.forwards = false, .maxSpeed = 90});
    //unclamp
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //50.6, 10.4
    chassis.moveToPoint(50.6, 10.76, 800, {.maxSpeed = 120});
    chassis.waitUntil(5);
    intake.move(80);
    //90
    chassis.turnToHeading(-90, 600, {.maxSpeed = 100});
    //-2.09, 10.61
    chassis.moveToPoint(-2.09, 10.61, 1500, {.maxSpeed = 110});
    //-90
    chassis.turnToHeading(90, 1000, {.maxSpeed = 100});
    intake.move(-80);
    //-20.35, 10.61
    chassis.moveToPoint(-23.1, 10.61, 800, {.forwards = false, .maxSpeed = 110});
    //0
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.waitUntil(3);
    intake.move(127);
    //-23.1, 31.45
    chassis.moveToPoint(-23.1, 31.45, 800, {.maxSpeed = 127});
    //-52
    chassis.turnToHeading(-52, 500, {.maxSpeed = 100});
    //-56.92, 55.64, -90
    chassis.moveToPose(-56.92, 58.0, -90, 1200, {.lead = 0.2,.maxSpeed = 117});
    chassis.waitUntil(12);
    lift_to_target_position(-67, 800, 15);
    chassis.moveToPoint(-66.0, 57.0, 800, {.maxSpeed = 127});
    chassis.waitUntilDone();
    pros::delay(500);
    intake.move(0);
    lift_to_target_position(-550, 700, 60);
    //-51
    chassis.moveToPoint(-49.86, 57, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-80);
    down_to_target_position(0, 800);
    chassis.turnToHeading(-180, 800, {.maxSpeed = 80});
    down_to_target_position(0, 800);
    //-48.71, 19.51
    //-48.08, -0.5    
    chassis.moveToPoint(-48.71, 19.51, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.moveToPoint(chassis.getPose().x, -0.5, 1000, {.maxSpeed = 65});
    chassis.swingToHeading(-86, lemlib::DriveSide::LEFT, 800, {.maxSpeed = 100});
    //-57.07, 11.82, 
    chassis.moveToPoint(-57.07, 11.82, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(25, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(-60, 0.74, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //-49.72, 9.75
    chassis.moveToPoint(-49.72, 9.75, 800, {.maxSpeed = 127});
    //0
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    intake.move(127);
    //-51.6, 82.73
    chassis.moveToPoint(-47.12, 82.73, 2000, {.maxSpeed = 115});
    chassis.waitUntil(40);
    lift_to_target_position(-73, 800, 15);
    //-105
    chassis.turnToHeading(-105, 800, {.maxSpeed = 100});
    //0.23, 105.56
    chassis.moveToPoint(0.5, 105.56, 1500, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntil(3);
    intake.move(60);
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    //-1.54, 120
    chassis.moveToPoint(0.65, 127, 1000, {.maxSpeed = 90});
    //reset to 118
    chassis.waitUntilDone();
    pros::delay(50);
    chassis.setPose(chassis.getPose().x, 118, chassis.getPose().theta);
    //112.5
    chassis.moveToPoint(0, 111.5, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(2);
    intake.move(0);
    chassis.waitUntilDone();
    lift_to_target_position(-550, 700, 50);
    //99.76, 
    chassis.moveToPoint(chassis.getPose().x, 99.76, 800, {.forwards = false, .maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(-80);
    chassis.waitUntil(3);
    down_to_target_position(0, 800);
    chassis.turnToHeading(84, 800, {.maxSpeed = 100});
    // 46.4, 104.16
    chassis.moveToPoint(48.0, 104.16, 1000, {.maxSpeed = 127});
    chassis.waitUntil(1);
    intake.move(127);
    //170
    chassis.turnToHeading(170, 800, {.maxSpeed = 100});
    //47.27, 80.77
    chassis.moveToPoint(47.27, 78.77, 800, {.maxSpeed = 127});
    //270
    chassis.turnToHeading(270, 800, {.maxSpeed = 100});
    //15.95, y is same
    chassis.moveToPoint(24.95, chassis.getPose().y, 800, {.maxSpeed = 127});
    //-134
    chassis.turnToHeading(228, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-3.04, 54.53, 1000, {.maxSpeed = 110});
    //305, 
    chassis.turnToHeading(315, 800, {.maxSpeed = 100});
    //-27.6, 80.11, 
    chassis.moveToPoint(-27.6, 80.11, 800, {.maxSpeed = 127});
    //310
    chassis.turnToHeading(310, 200, {.maxSpeed = 100});
    //-61.14, 97.97
    chassis.moveToPoint(-59.14, 97.97, 1000, {.maxSpeed = 110});
    //left doinker out
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(true);
    //516
    chassis.turnToHeading(516, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed = 100});
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(false);
    //-64.85, 105.19
    chassis.moveToPoint(-64.85, 105.19, 800, {.forwards = false, .maxSpeed = 110});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //-58.83, 95.14
    chassis.moveToPoint(-58.83, 95.14, 800, {.maxSpeed = 127});
    //-65.53, 105.59
    chassis.moveToPoint(-65.53, 105.19, 800, {.forwards = false, .maxSpeed = 127});
    //-53.77, 84.25
    chassis.moveToPoint(-53.77, 84.25, 800, {.maxSpeed = 127, .minSpeed = 80, .earlyExitRange = 1});
    chassis.waitUntil(10);
    //mogo.set_value(true);
    //605
    chassis.turnToHeading(65, 800, {.maxSpeed = 100, .minSpeed = 70, .earlyExitRange = 1});
    //25.55, 114.5
    chassis.moveToPoint(23.0, 114.5, 2000, {.maxSpeed = 127, .minSpeed = 80, .earlyExitRange = 1});
    // //622
    chassis.turnToHeading(90, 500, {.maxSpeed = 100, .minSpeed = 70, .earlyExitRange = 1});
    // //53.77, 121.15
    chassis.moveToPoint(55.5, 117.44, 800, {.maxSpeed = 127});
    */
   printf("frontDist: %f\n", getFrontDist());
   printf("cosine of 180 %f\n", cos(M_PI));
   printf("sensor confidence: %ld\n", frontDist.get_confidence());
   //62.5
   //68.85
   if(frontDist.get_confidence() >= 10){
    chassis.setPose(65.65-(getFrontDist() * abs(sin(chassis.getPose().theta * M_PI / 180))), chassis.getPose().y, chassis.getPose().theta);
   }
   
}

//DON'T USE ANY BELOW THIS


void SKILLS(){
    chassis.setPose(0,0,0);
    intake.move(127);
    pros::delay(400);
    chassis.moveToPoint(0, 13.68, 500, {.maxSpeed = 110});
    intake.move(-127); 
    chassis.turnToHeading(-90, 500, {.maxSpeed = 100});
    pros::Task intakeUnjammer(intakeUnjam);
    chassis.moveToPoint(22.8, 13.68, 1000, {.forwards = false, .maxSpeed = 110}); 
    chassis.waitUntilDone();
    //CLAMP FIRST MOGO
    mogo.set_value(true);
    pros::delay(100);
    chassis.setPose(22.8, chassis.getPose().y, chassis.getPose().theta);
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.moveToPoint(25.64, 37.53, 700, {.maxSpeed = 127});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntil(6);
    chassis.turnToHeading(50, 500, {.maxSpeed = 100});
    chassis.moveToPose(57.09, 57.5, 88, 1200, {.lead = 0.2,.maxSpeed = 90}); //was 127
    chassis.waitUntil(12);
    lift_to_target_position(-68, 800, 15);
    intakeUnjammer.suspend();
    chassis.moveToPoint(67.0, 59, 900, {.maxSpeed = 90});
    chassis.waitUntilDone();
    // chassis.setPose(60, chassis.getPose().y, chassis.getPose().theta);
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(100);
    intake.move(0);
    lift_to_target_position(-500, 800, 90);
    chassis.moveToPoint(50.86, 59.15, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-127);
    down_to_target_position(0, 800);
    chassis.turnToHeading(180, 700, {.maxSpeed = 80});
    intakeUnjammer.resume();
    //50.28, -0.16
    chassis.moveToPoint(49.28, 23.14, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.waitUntil(1);
    down_to_target_position(0, 800);
    chassis.moveToPoint(chassis.getPose().x, -0.16, 1000, {.maxSpeed = 95}); //was 70
    chassis.waitUntil(2);
    down_to_target_position(0, 800);
    chassis.waitUntil(5);
    intake.move(0);
    chassis.waitUntil(6);
    intake.move(127);
    chassis.swingToHeading(82, lemlib::DriveSide::RIGHT, 800, {.maxSpeed = 100});
    chassis.moveToPoint(57.43, 11.49, 800, {.maxSpeed = 90});
    chassis.turnToHeading(-27, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(61.7, 3.99, 800, {.forwards = false, .maxSpeed = 90});
    //unclamp
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //50.6, 10.4
    chassis.moveToPoint(50.6, 12.51, 800, {.maxSpeed = 120});
    chassis.waitUntil(5);
    intake.move(80);
    //90
    chassis.turnToHeading(-90, 600, {.maxSpeed = 100});
    //-2.09, 10.61
    chassis.moveToPoint(-2.09, 12.51, 1500, {.maxSpeed = 115});
    //-90
    chassis.turnToHeading(90, 1000, {.maxSpeed = 100});
    intake.move(-80);
    //-20.35, 10.61
    chassis.moveToPoint(-23.1, 12.51, 800, {.forwards = false, .maxSpeed = 110});
    //0
    chassis.waitUntilDone();
    mogo.set_value(true);

    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    chassis.waitUntil(3);
    intake.move(127);
    //-23.1, 31.45
    chassis.moveToPoint(-23.1, 31.45, 800, {.maxSpeed = 127});
    //-52
    chassis.turnToHeading(-52, 500, {.maxSpeed = 100});
    //-56.92, 55.64, -90
    chassis.moveToPose(-57, 58.0, -90, 1500, {.lead = 0.2,.maxSpeed = 95}); //was 57.3
    chassis.waitUntil(12);
    lift_to_target_position(-67, 800, 15);
    intakeUnjammer.suspend();
    chassis.moveToPoint(-70.0, 58.0, 900, {.maxSpeed = 105});
    chassis.waitUntilDone();
    // chassis.setPose(-60, chassis.getPose().y, chassis.getPose().theta);
    pros::delay(400);
    intake.move(0);
    pros::delay(100);
    intake.move(127);
    pros::delay(200);
    intake.move(0);
    lift_to_target_position(-550, 700, 100);
    //-51
    chassis.moveToPoint(-49.86, 57, 1000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntil(5);
    intake.move(-127);
    down_to_target_position(0, 800);
    chassis.turnToHeading(-180, 800, {.maxSpeed = 80});
    intakeUnjammer.resume();
    chassis.moveToPoint(-48.71, 19.51, 1000, {.maxSpeed = 127});
    chassis.waitUntil(0.5);
    intake.move(127);
    chassis.waitUntil(1);
    down_to_target_position(0, 800);
    chassis.moveToPoint(chassis.getPose().x, -0.5, 1000, {.maxSpeed = 95}); //was 65
    chassis.waitUntil(1);
    down_to_target_position(0, 800);
    chassis.swingToHeading(-86, lemlib::DriveSide::LEFT, 800, {.maxSpeed = 100});
    //-57.07, 11.82, 
    chassis.moveToPoint(-57.07, 11.82, 800, {.maxSpeed = 90});
    //-27
    chassis.turnToHeading(25, 800, {.maxSpeed = 100});
    //61.7, 3.99
    chassis.moveToPoint(-60, 0, 800, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    mogo.set_value(false);
    intake.move(-80);
    //-49.72, 9.75
    chassis.moveToPoint(-48.72, 9.75, 800, {.maxSpeed = 127});
    //0
    chassis.turnToHeading(0, 800, {.maxSpeed = 100});
    intakeUnjammer.suspend();
    intake.move(127);
    //-51.6, 82.73
    chassis.moveToPoint(-48.12, 76, 1800, {.maxSpeed = 120, .minSpeed = 80, .earlyExitRange = .2});
    // chassis.waitUntil(40);
    // lift_to_target_position(-73, 800, 15);
    chassis.moveToPoint(-48.12, 82.73, 500, {.maxSpeed = 100});
    chassis.waitUntil(6);
    intake.move(0);
    //-105
    chassis.turnToHeading(-105, 800, {.maxSpeed = 100});
    chassis.moveToPoint(1.5, 105.56, 1600, {.forwards = false, .maxSpeed = 80}); //was 1500, 80
    // chassis.waitUntil(3);
    // intake.move(20);
    chassis.waitUntilDone();
    mogo.set_value(true);
    chassis.turnToHeading(95, 800, {.maxSpeed = 100});
    intake.move(127);
    // 46.4, 104.16
    chassis.moveToPoint(48.0, 103.5, 1000, {.maxSpeed = 127});
    intakeUnjammer.resume();
    chassis.waitUntil(1);
    intake.move(127);
    //170
    chassis.turnToHeading(170, 800, {.maxSpeed = 100});
    //47.27, 80.77
    chassis.moveToPoint(47.27, 78.77, 800, {.maxSpeed = 127});
    chassis.waitUntil(3);
    intake.move(-127);
    chassis.waitUntil(8);
    intake.move(127);
    //270
    chassis.turnToHeading(270, 800, {.maxSpeed = 100});
    //15.95, y is same
    chassis.moveToPoint(24.95, chassis.getPose().y, 800, {.maxSpeed = 127});
    //-134
    chassis.turnToHeading(228, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-3.04, 54.53, 1000, {.maxSpeed = 110});
    //305, 
    chassis.turnToHeading(318, 800, {.maxSpeed = 100});
    chassis.moveToPoint(-25.6, 81.11, 800, {.maxSpeed = 127}); //-27.6, 80.11
    //310
    chassis.turnToHeading(307, 200, {.maxSpeed = 100});
    //-61.14, 97.97
    chassis.moveToPoint(-59.14, 98.97, 1000, {.maxSpeed = 110});
    //left doinker out
    chassis.waitUntilDone();
    leftDoinkerMech.set_value(true);
    chassis.turnToHeading(0, 200, {.maxSpeed = 100});
    chassis.moveToPoint(-55.14, 120, 700, {.maxSpeed = 127});
    //516
    chassis.turnToHeading(180, 800, {.direction = lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed = 127});
    chassis.waitUntilDone();
    intake.move(-80);
    leftDoinkerMech.set_value(false);
    //-64.85, 105.19
    chassis.turnToHeading(120, 250, {.maxSpeed = 127});
    chassis.moveToPoint(-65.34, chassis.getPose().y, 800, {.forwards = false, .maxSpeed = 110}); //y = 105
    // chassis.waitUntil(3);
    mogo.set_value(false);
    chassis.waitUntilDone();
    chassis.tank(-127,-127, true);
    pros::delay(450);
    // chassis.moveToPoint(-62.53, 112, 700, {.forwards = false, .maxSpeed = 127});
    chassis.moveToPoint(-53.77, 84.25, 1000, {.maxSpeed = 100});
    chassis.turnToHeading(235, 700, {.maxSpeed = 100});
    // chassis.moveToPoint(5.0, 109.0, 1500, {.forwards = false, .maxSpeed = 127}); //23, 105
    // intake.move(127);
    // chassis.turnToHeading(-105, 300, {.maxSpeed = 100}); //-95
    intake.move(-40);
    chassis.moveToPoint(46.0, 126.0, 2000, {.forwards = false, .maxSpeed = 110}); //56, 120.5
    chassis.waitUntil(10);
    mogo.set_value(true);
    chassis.waitUntilDone();    
    mogo.set_value(false);
    chassis.moveToPoint(54.0, 124.0, 900, {.forwards = false, .maxSpeed = 65}); //56, 120.5
    // chassis.turnToHeading(220, 800, {.maxSpeed = 100});
    // chassis.waitUntilDone();
    chassis.tank(-100,-100, true);
    pros::delay(400);   

    //HANG-------------------------
    chassis.moveToPose(23.6, 76.9, -135, 1700, {.maxSpeed = 127});
    chassis.waitUntil(10);
    lift_to_target_position(-400, 800, 50);
    //tank 70
    chassis.waitUntilDone();
    chassis.turnToHeading(408, 800, {.maxSpeed = 100}); //-95
    chassis.waitUntilDone();
    chassis.tank(-40,-40, true);
    pros::delay(1600); //800
    chassis.cancelMotion();
    down_to_target_position(-170, 500);
    intakePis.set_value(false);
    chassis.tank(60, 60, true);
}

