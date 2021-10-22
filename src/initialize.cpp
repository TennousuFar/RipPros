#include "../include/main.h"
using namespace pros;

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Base Motors *---------------------------------------------*/
Motor FL(11, E_MOTOR_GEARSET_18, MOTOR_ENCODER_ROTATIONS);        // Front Left Drive
Motor BL(12, E_MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS); // Back Left Drive
Motor FR(13, E_MOTOR_GEARSET_18, MOTOR_ENCODER_ROTATIONS);        // Front Right Drive
Motor BR(14, E_MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS); // Back Right Drive

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Task Motors *---------------------------------------------*/
Motor LIFT(20, E_MOTOR_GEARSET_36, false, MOTOR_ENCODER_ROTATIONS); // Lift Motor
Motor FORK(1, E_MOTOR_GEARSET_36, false, MOTOR_ENCODER_ROTATIONS);  // Score Motor
Motor INTAKE(17, E_MOTOR_GEARSET_18, MOTOR_ENCODER_ROTATIONS);      // Left Motor Intake
Motor CONVEYER(19, E_MOTOR_GEARSET_18, MOTOR_ENCODER_ROTATIONS);    // Right Motor Intake

/*---------------------------------------------------------------------------------------------------------*/
Controller CONTROLLER(E_CONTROLLER_MASTER);                         // MASTER Contoller
Driver USER(CONTROLLER);

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Base Sensors *--------------------------------------------*/
Rotation LEFT_WHEEL_SENSOR (1);
Rotation RIGHT_WHEEL_SENSOR(2);
Rotation AUX_WHEEL_SENSOR(3);
Imu INER_SENSOR(4);

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Task Sensors *--------------------------------------------*/
Rotation LIFT_SENSOR(1);
Robot Yeet(FL, FR, BL, BR, LIFT, FORK, INTAKE, CONVEYER);