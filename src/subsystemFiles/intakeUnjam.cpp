#include "pros/adi.hpp"
#include "pros/misc.h"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\devices.hpp"
#include "opcontrol.hpp"

//decreae y by 2 decrease x by 1
void intakeUnjam(){
    uint32_t lastCheckTime = pros::millis();
        while (true) {
            // prints intake funcs
            if(pros::millis() - lastCheckTime >= 300){
                if(intake.get_efficiency()/100 <= 0.1){
                    intake.move(-127);
                    pros::delay(300);
                    intake.move(127);
                    lastCheckTime = pros::millis();
            } else{
                lastCheckTime = pros::millis();
            }
            // delay to save resources
            pros::delay(25);
        }
    }
}