#include "devices.hpp"
#include "opcontrol.hpp"
#include "autos.hpp"

//function to score on alliance stake
void AllianceStake(){
    int angle = (rot.get_angle() / 100); //converts the returned centidegree to degree
    while(angle > 85){ //loop that runs until arm is at desired angle
        arm.move(-80);
        angle = (rot.get_angle() / 100);
        pros::delay(100);
    }
}