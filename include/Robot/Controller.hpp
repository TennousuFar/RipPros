#pragma once
#include "../main.h"
//using namespace pros;

//class pros::Controller; 

class Driver{
    private:
        pros::Controller *Cont;

    public:
        Driver(pros::Controller &cont);

        /*---------------------------------------------------------------------------------------------------------*/
        /*--------------------------------------------* Analog Output *--------------------------------------------*/
        /**
         * @brief
         *
         * @return int
         */
        int left_X();

        /**
         * @brief
         *
         * @return int
         */
        int left_Y();

        /**
         * @brief
         *
         * @return int
         */
        int right_X();

        /**
         * @brief
         *
         * @return int
         */
        int right_Y();

        /*---------------------------------------------------------------------------------------------------------*/
        /*-------------------------------------------* Digital Output *--------------------------------------------*/
        // Right Controller Buttons
        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_X();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_Y();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_A();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_B();

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        // Left Controller Buttons
        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_Right();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_Left();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_Up();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_Down();
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
        // Top Controller Buttons
        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_R1();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_R2();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_L1();

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        bool dit_L2();
};