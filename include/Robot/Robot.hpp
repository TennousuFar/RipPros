#pragma once
#include "../main.h"

//class pros::Motor; 


class Robot {
    private:
    pros::Motor* FL, *FR, *BL, *BR, *LIFT, *FORKLIFT, *INTAKE, *CONVEYER;

    int liftSpeed = 70;
    int forkLiftSpeed = 70;

    public:
        Robot(pros::Motor &fl, pros::Motor &fr, pros::Motor &bl, pros::Motor &br, pros::Motor &lift, pros::Motor &fork, pros::Motor &intake, pros::Motor &conveyer);

        void leftDriveSpeed(double speed);
        void rightDriveSpeed(double speed);
        
        
        //void intake ();

        /*---------------------------------------------------------------------------------------------------------*/
        /*--------------------------------------------* Lift Methods *---------------------------------------------*/
        typedef enum {
            LIFT_GROUND_STATE = 0,
            LIFT_INTAKE_STATE = 50,
            LIFT_SCORE_STATE = 100
        } liftStates;
        /**
         * @brief 
         * 
         */
        void lift_Move ();
        /**
         * @brief 
         * 
         * @param State 
         */
        void lift_Move (liftStates State);
        /**
         * @brief 
         * 
         */
        void lift_ResetSensor();

        /*---------------------------------------------------------------------------------------------------------*/
        /*-----------------------------------------* Fork Lift Methods *-------------------------------------------*/
        typedef enum {
            FORK_GROUND_STATE = 0,
            FORK_INTAKE_STATE = 50
        } forkStates;
        /**
         * @brief 
         * 
         */
        void forkLift_Move();

        /**
         * @brief 
         * 
         * @param State 
         */
        void forkLift_Move(forkStates State);

        /**
         * @brief 
         * 
         */
        void forkLift_ResetSensor();

        /*---------------------------------------------------------------------------------------------------------*/
        /*-------------------------------------------* Intake Methods *--------------------------------------------*/
};
