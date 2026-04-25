#include "devices.hpp"

/**
 * A class with a constructor called pidTuner
 *
 * Helps change the pid values of motions after them 
 * in cases that require separate constants for separate motions.
 * can also change the small and large error and timeout
 *
 * @author Arpit Ahuja, Sana Barige, Diya Ladani
 * @version 1.0
 * @since 2025-02-10
 */

 /**
 * @brief class name pidTuner
 *
 */
class pidTuner {
    public:
        //constructor 
        pidTuner() {} // constructor called pidTuner
        
        /**
        * @brief method that changes kP, kI, kD values for angular PID
        *
        */
        void changeAngularPid(float P, float I, float D){
            chassis.angularPID.kP = P;
            chassis.angularPID.kI = I;
            chassis.angularPID.kD = D;
        }

        /**
        * @brief method that changes kP, kI, kD values for lateral PID
        *
        */
        void changeLateralPID(float P, float I, float D){
            chassis.lateralPID.kP = P;
            chassis.lateralPID.kI = I;
            chassis.lateralPID.kD = D;
        }

        /**
        * @brief method that changes large exit range and time for lateral PID
        *
        */
        void changeLargeLateralExits(float range, float time){
            chassis.lateralLargeExit.range = range;
            chassis.lateralLargeExit.time = time;
        }

        /**
        * @brief method that changes large exit range and time for angular PID
        *
        */
        void changeLargeAngularExits(float range, float time){
            chassis.angularLargeExit.range = range;
            chassis.angularLargeExit.time = time;
        }

        /**
        * @brief method that changes small exit range and time for lateral PID
        *
        */
        void changeSmallLateralExits(float range, float time){
            chassis.lateralSmallExit.range = range;
            chassis.lateralSmallExit.time = time;
        }

        /**
        * @brief method that changes small exit range and time for angular PID
        *
        */
        void changeSmallAngularExits(float range, float time){
            chassis.angularSmallExit.range = range;
            chassis.angularSmallExit.time = time;
    }
};


