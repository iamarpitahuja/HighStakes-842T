#include "devices.hpp"
#include "opcontrol.hpp"

/**
 * Declares the functions we use in driver control
 *
 * File that contains our mogo mech function, 
 * moves our intake up and down, automatically
 * moves our ladybrown to a load position, manually 
 * controls our intake and ladybrown and two doinkers
 *
 * @author Arpit Ahuja, Sana Barige, Diya Ladani
 * @version 1.0
 * @since 2025-02-10
 */


/**
 * @brief Function that controls our mogo clamp mechanism
 *
 */
//method to clamp onto mogos and release them
void mogoMech(){
    static bool raised = false; //static boolean value that changes with every press
    if(master.get_digital_new_press(MOGO_DOWN_BUTTON)){ // if the mogo down button (X) is pressed
        if (!raised) { // and if raised is false (!raised makes it true)
            mogo.set_value(false); // clamp goes down
            raised = true; // boolean variable is flipped
        } else {
            mogo.set_value(true); // if raised is true then the mogo unclamps
            raised = false; // boolean variable returns to state where it can clamp
        }
    }
}

/**
 * @brief Function that controls our intake piston and moves it up and down
 *
 */
void moveIntake(){
    static bool raised = false; // static boolean value that changes with each press
    if(master.get_digital_new_press(INTAKE_PIS_BUTTON)){ // if controller detects button A is pressed
        if (!raised) { // if raised is false then intake piston goes back up
            intakePis.set_value(false); // piston is set to false
            raised = true; // raised is set to true
        } else { // if raised is true
            intakePis.set_value(true); // piston is set to true
            raised = false; // raised is set back to false
        }
    }
}

//method to move arm to certain height
void moveAutoArm(){
    while(master.get_digital(ARM_AUTO_UP_BUTTON) && ((rot.get_position() / 100) >= -140)){
                //arm.move(ARM_UP_SPEED);
                //arm.move(-ARM_DOWN_SLOW_SPEED);
                    arm.move(50);
                    pros::delay(150);
                }   
               pros::delay(10);
            }
            //while ((rot.get_angle() / 100) < 0 ) {
                //arm.move(ARM_DOWN_SLOW_SPEED);
              //  arm.move(127);
               //pros::delay(100);
            //}
       

    //while(master.get_digital(ARM_AUTO_DOWN_BUTTON) && (rot.get_angle() / 100) > 85){
      //  arm.move(-ARM_DOWN_SLOW_SPEED);
        //pros::delay(100);
    //} //end of while 


/**
 * @brief controls the buttons that make our intake motor spin forward or reverse
 *
 */
//method to intake and outtake
void intakeControl(){
    const bool intakeButtonPressed = master.get_digital(INTAKE_BUTTON); // boolean that stays true if intake button (r1) is pressed
    const bool outtakeButtonPressed = master.get_digital(OUTTAKE_BUTTON); // boolean that stays true if outtake button (r2) is pressed
    if (intakeButtonPressed){ // if this is true
        intake.move(INTAKE_SPEED); // move intake at 127
    } 
    else if (outtakeButtonPressed) { // if this is true
        intake.move(-OUTTAKE_FAST_SPEED); // move intake at -127 (outtake)
    } 
    else{ // if neither are true
        intake.move(0); // dont move intake at all
    } 
}

/**
 * @brief controls the buttons that move our ladybrown up and down
 *
 */
//method to manually control arm
void armControl(){
    const bool armUpButtonPressed = master.get_digital(ARM_UP_BUTTON); //boolean that is true if arm up button is pressed
    const bool armDownButtonPressed = master.get_digital(ARM_DOWN_BUTTON); //boolean that is true if arm down button is pressed
    if (armUpButtonPressed){ // if this boolean is true
        arm.move(127); // arm moves up at max speed
    }
    else if (armDownButtonPressed){ // if arm down button bool is true
        arm.move(-110); // arm moves down at nearly top speed
    }
    else{ // if neither are true
        arm.move(0); // arm doesnt move
    }
}

/**
 * @brief Function that controls our right doinker 
 *
 */
void rightDoinkerControl(){
    static bool doink = false; // static doink boolean value
    if(master.get_digital_new_press(RIGHT_DOINKER_BUTTON)){ // if controller right doinker button is pressed
        if (!doink) { // if doink is false
            rightDoinkerMech.set_value(false); // right doinker mech goes down
            doink = true; // doink is set to true
        } else { // if doink is true
            rightDoinkerMech.set_value(true); // right doinker goes back up
            doink = false; // doink is set back to false
        }
    }
}

/**
 * @brief Function that controls our left doinker
 *
 */
void leftDoinkerControl(){
    static bool oink = false; // static doink boolean value
    if(master.get_digital_new_press(LEFT_DOINKER_BUTTON)){ // if controller left doinker button is pressed
        if (!oink) { // if oink is false
            leftDoinkerMech.set_value(false); // left doinker mech goes down
            oink = true; // oink is set to true
        } else { // if oink is true
            leftDoinkerMech.set_value(true); // left doinker goes back up
            oink = false; // oink is set back to false
        }
    }
}

