#pragma once
#include <vector>
#include <math.h>
#include <numeric>
#include <iostream>
#include "../../api.h"

class PID {

private:
    double Desired_Position, Error, Past_Error;
    double Derivative, Integral;
    double KP, KI, KD;
    double Max_Int, Max_Speed;

    /**
    * @param
    * @returns
    */
    double Max_Acceleration(pros::Motor obj);
    
    /**
    * @param
    * @returns
    */

    double Rise_Time();

    /**
    * @param
    * @returns
    */
    double Overshoot();

    /**
    * @param
    * @returns
    */
    double Settling_Time();

protected:
    void set_Position(double Desired_Position, double Speed);

public: 

    /**
     * @brief Construct a new PID object
     * 
     */
    PID();

    /**
     * @brief 
     * 
     * @param KP1 
     * @param KI1 
     * @param KD1 
     * @param Max_Int1 
     * @param Max_Speed1 
     */
    void set_PID(double KP1, double KI1, double KD1, double Max_Int1);

    void Tune_PID();

    void get_Speed();
};