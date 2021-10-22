#pragma once
#include "../include.hpp"
#include <vector>
#include <math.h>
#include <numeric>
#include <iostream>
using namespace std;

class Odometry{
private:
	double P_Left = 0, P_Right = 0, P_Aux = 0, P_Theta = 0;
	vector<vector<double>> Sim_Coords;
	
protected:
	static double Base_Radius, Wheel_Radius, Aux_Offset;
	static double Global_Theta, Global_X, Global_Y;

public:
	Odometry();


	/**
	 * @brief Construct a new Odometry object
	 * 
	 * @param Base_R 
	 * @param Wheel_R 
	 * @param Aux_O 
	 */
	Odometry(float Base_R, float Wheel_R, float Aux_O) { // Constructor 
		Base_Radius = Base_R, Wheel_Radius = Wheel_R, Aux_Offset = Aux_O;
	};

	void Calculate_3W(vector<vector<double>> Wheel_Info);

	vector<vector<double>> Get_Global_Test();
	vector<double> Get_Global();
};

