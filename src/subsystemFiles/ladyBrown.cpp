#include "pros/adi.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\subsystemHeaderFiles\ladyBrown.hpp"
#include "pros/misc.h"
// #include "C:\Users\kc004\OneDrive\Desktop\tears 2.11.25\include\devices.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\devices.hpp"
#include "opcontrol.hpp"

using namespace pros;

lemlib::PID lbPID(
        1.9,
        0,
        4,
        5,
        false
);

bool lift_to_target_position(int targetPosition, int maxTime, int speed){
    double currentPos = rot.get_position() / 100; 
    bool atTarget = false;
    int startTime = pros::millis();
    while(currentPos > targetPosition && !atTarget){
        //double lbPos = lbPID.update(targetPosition-currentPos);
        arm.move(speed);
        currentPos = rot.get_position() / 100;
        pros::delay(10);    
        if ((pros::millis() - startTime) > maxTime) {
            atTarget = true;
        } //end of if        
    }
        pros::delay(10);
        arm.move(0);
        return atTarget;
}

void down_to_target_position(int targetPosition, int maxTime){
    double currentPos = rot.get_position() / 100; 
    bool atTarget = false;
    int startTime = pros::millis();
    while(currentPos < targetPosition && !atTarget){
        double lbPos = lbPID.update(targetPosition-currentPos);
        arm.move(-lbPos);
        currentPos = rot.get_position() / 100;
        pros::delay(10);    
        if ((pros::millis() - startTime) > maxTime) {
            atTarget = true;
        } //end of if        
    }
        pros::delay(10);
        arm.move(0);
}


void armLoadMacro(){
    if(master.get_digital(ARM_AUTO_UP_BUTTON)){
        double currentPos = rot.get_position() / 100; 
        bool atTarget = false;
        int startTime = pros::millis();
        while(currentPos > -70 && !atTarget){  //-145
            double lbPos = lbPID.update(-70-currentPos);
            arm.move(25);
            currentPos = rot.get_position() / 100;
            pros::delay(10);    
            if ((pros::millis() - startTime) > 500) {
                atTarget = true;
            } //end of if        
        }
            pros::delay(10);
            arm.move(0);
    }
}

