#include "pros/adi.hpp"
#include "subsystemHeaderFiles\distanceSense.hpp"
#include "pros/misc.h"
// #include "C:\Users\kc004\OneDrive\Desktop\tears 2.11.25\include\devices.hpp"
#include "C:\Users\sheen\OneDrive - Great Valley School District\Summer Into notes\tears-SKILLS\include\devices.hpp"
#include "opcontrol.hpp"

float getFrontDist(){
    return (frontDist.get_distance())/25.4;
}

float getRightDist(){
    return (rightDist.get_distance())/25.4;
}

float getLeftDist(){
    return (leftDist.get_distance())/25.4;
}

