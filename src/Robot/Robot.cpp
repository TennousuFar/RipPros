#include "../../include/Robot/Robot.hpp"
//#include "../../include/main.h"
using namespace pros;



Robot::Robot(Motor& fl, Motor& fr, Motor& bl, Motor& br, Motor& lift, Motor& fork, Motor& intake, Motor& conveyer){
    FL = &fl;
    FR = &fr; 
    BL = &bl;
    BR = &br; 
    LIFT = &lift; 
    FORKLIFT = &fork; 
    INTAKE = &intake; 
    CONVEYER = &conveyer; 
}


void Robot::leftDriveSpeed(double speed){
    FL->move_velocity(speed);
    BL->move_velocity(speed);
}
void Robot::rightDriveSpeed(double speed){
    FR->move_velocity(speed);
    BR->move_velocity(speed);
}

/*---------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------* Lift Methods *---------------------------------------------*/

void Robot::lift_Move(){
    LIFT->move_velocity(liftSpeed);
}

void Robot::lift_Move(liftStates liftState){

}

void Robot::lift_ResetSensor (){

}

/*---------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------* Fork Lift Methods *-------------------------------------------*/
void Robot::forkLift_Move(){
    FORKLIFT->move_velocity(liftSpeed);
}

void Robot::forkLift_Move(forkStates State){

}

void Robot::forkLift_ResetSensor(){
}

/*---------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------* Intake Methods *--------------------------------------------*/