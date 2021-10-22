#include "../../include/Robot/Controller.hpp"
//#include "../../include/main.h"

Driver::Driver(pros::Controller &cont){
    Cont = &cont;
    }
/*---------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------* Analog Output *--------------------------------------------*/
int Driver::left_X(){
    return Cont->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
}
int Driver::left_Y(){
    return Cont->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
}
int Driver::right_X(){
    return Cont->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
}
int Driver::right_Y(){
    return Cont->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
}

/*---------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------* Digital Output *--------------------------------------------*/

// Right Controller Buttons
bool Driver::dit_X(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_X);
}
bool Driver::dit_Y(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_Y);
}
bool Driver::dit_A(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_A);
}
bool Driver::dit_B(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_B);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

// Left Controller Buttons
bool Driver::dit_Right(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT);
}
bool Driver::dit_Left(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_LEFT);
}
bool Driver::dit_Up(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_UP);
}
bool Driver::dit_Down(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_DOWN);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Top Controller Buttons
bool Driver::dit_R1(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_R1);
}
bool Driver::dit_R2(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_R2);
}
bool Driver::dit_L1(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_L1);
}
bool Driver::dit_L2(){
    return Cont->get_digital(pros::E_CONTROLLER_DIGITAL_L2);
}