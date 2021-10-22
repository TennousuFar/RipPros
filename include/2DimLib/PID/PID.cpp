#include "PID.hpp"

PID::PID(){};

/**
 * PID Tuning Methods
 */
double PID::Max_Acceleration(pros::Motor obj){
    return 1.1;
};

double PID::Rise_Time(){
    return 1.1;

};

double PID::Overshoot(){
    return 1.1;
};

double PID::Settling_Time(){
    return 1.1;
};



void PID::set_PID(double KP1, double KI1 = 0, double KD1 = 1, double Max_Int1 = 0){
    KP = KP1, KI = KI1, KD = KD1;
    Max_Int = Max_Int1;
};

void PID::set_Position(double Desired_Position1, double Speed){
    Desired_Position = Desired_Position1;
    Max_Speed = Speed;
}

void PID::get_Speed(){
    





}