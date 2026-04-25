#pragma once

/**
 * Declares the headers for our autonomous functions.
 *
 * Contains all the global auton functions we use in competition. 
 *
 * @author Arpit Ahuja, Sana Barige, Diya Ladani
 * @version 1.0
 * @since 2025-02-10
 */


/////////////////////////////////////////
// Utility Functions
///////////////////////////
//eject_ring function
extern void armLoadMacro(); //arm macro

/////////////////////////////////////////
// Autonomous Routines
///////////////////////////

extern void worldsSkills();


extern void realSkills();
extern void skills();
extern void newSkills();
/**
 * @brief blank auton that does nothing (just in case robot malfunctions)
 *
 */
extern void blank();

/**
 * @brief case-switch that iterates through our autons
 *
 */
extern void selector(int auton);


extern void firstDaySKILLS();


extern void SKILLS();


