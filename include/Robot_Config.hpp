#pragma once
using namespace pros;

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Base Motors *---------------------------------------------*/
extern Motor FL;        // Front Left Drive
extern Motor FR;         // Front Right Drive
extern Motor BL;          // Back Left Drive
extern Motor BR;          // Back Right Drive

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Task Motors *---------------------------------------------*/
extern Motor LIFT; // Lift Motor
extern Motor FORK;  // Score Motor
extern Motor INTAKE; // Left Motor Intake
extern Motor CONVEYER; // Right Motor Intake

/*---------------------------------------------------------------------------------------------------------*/
extern Controller CONTROLLER; // MASTER Contoller
class Robot;
extern Robot Yeet;
class Driver;
extern Driver USER; 

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Base Sensors *--------------------------------------------*/
extern Rotation LEFT_WHEEL_SENSOR;
extern Rotation RIGHT_WHEEL_SENSOR;
extern Rotation AUX_WHEEL_SENSOR;
extern Imu INER_SENSOR;

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Task Sensors *--------------------------------------------*/
extern Rotation LIFT_SENSOR;

/*---------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------* Class Objects *--------------------------------------------*/


/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Driver Tasks *--------------------------------------------*/
void Driver_Base_T(void *);
void Driver_Lift_T(void *);
void Driver_Fork_T(void *);
void Driver_Intake_T(void *);

/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------* Auton Tasks *---------------------------------------------*/
//void Auton_Base_T(void *);
//void Auton_Lift_T(void *);
//void Auton_Fork_T(void *);
//void Auton_Intake_T(void *);
//void Auton_Odom_T(void *);
