#pragma once
#include "pros/adi.hpp"
#include "devices.hpp"

// header lady brown lift macro 
extern bool lift_to_target_position(int targetPosition, int maxTime, int speed);

// header macro to bring lady brown back down
extern void down_to_target_position(int targetPosition, int maxTime);

//header lady brown load macro
extern void armLoadMacro();

