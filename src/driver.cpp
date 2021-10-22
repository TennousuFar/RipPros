#include "../include/main.h"
//#include "../include/Robot/lib.hpp"
using namespace pros;

void Driver_Base_T(void *){
    while (true){
        Yeet.leftDriveSpeed(USER.left_Y() + USER.right_X());
        Yeet.rightDriveSpeed(USER.right_X() - USER.left_Y());
        delay (20);
    }
}

void Driver_Lift_T(void *){
    while (true){
        delay(10);
    }
}

void Driver_Fork_T(void *){
    while (true){
        delay(10);
    }
}
void Driver_Intake_T(void *){
    while (true){
        delay(10);
    }
}

