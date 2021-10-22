#include "Odometry.hpp"
using namespace std;

double Odometry::Base_Radius = 6.25, Odometry::Wheel_Radius = 3.125, Odometry::Aux_Offset = 6.25;
double Odometry::Global_Theta = 0, Odometry::Global_X = 0, Odometry::Global_Y = 0;

Odometry::Odometry(){}

void Odometry::Calculate_3W(vector<vector<double>> Wheel_Info) {

	// Stores travel distance for each wheel for simulation testing
	vector<double> Left_Wheel_Distance_List = Wheel_Info[0]; 
	vector<double> Right_Wheel_Distance_List = Wheel_Info[1];
	vector<double> Aux_Wheel_Distance_List = Wheel_Info[2];

	LOGL("Left Wheel Distance List: ", Left_Wheel_Distance_List);
	LOGL("Right Wheel Distance List: ", Right_Wheel_Distance_List);
	LOGL("Aux Wheel Distance List: ", Aux_Wheel_Distance_List);

	Global_Theta = 0, Global_X = 0, Global_Y = 0;
	double Delta_Left = 0, Delta_Right = 0, Delta_Aux = 0, Delta_Theta = 0;
	vector<double> Local_Translation_Vector = { 0, 0 }, Global_Translation_Vector = { 0,0 };

	for (int i = 0; i < Left_Wheel_Distance_List.size(); i++) {

		LOGE("Iteration: ", i);
		Delta_Left = Left_Wheel_Distance_List[i] - P_Left;
		Delta_Right = Right_Wheel_Distance_List[i] - P_Right;
		Delta_Aux = Aux_Wheel_Distance_List[i] - P_Aux;

		Delta_Theta = (Delta_Right - Delta_Left) / (2 * Base_Radius);
		LOGE("Delta Theta: ", Delta_Theta);
		LOGE("Delta Left: ", Delta_Left);
		LOGE("Delta Right: ", Delta_Right);
		LOGE("Delta Aux: ", Delta_Aux);
		Global_Theta += Delta_Theta;

		double Average_Orientation = P_Theta + (Delta_Theta / 2);

		if (abs(Delta_Left - Delta_Right) <= .01) {
			Local_Translation_Vector[0] = Delta_Right;
			Local_Translation_Vector[1] = Delta_Aux;
		}
		else {
			Local_Translation_Vector[0] = 2 * sin(Delta_Theta / 2) * ((Delta_Right / Delta_Theta) - Base_Radius); // cord length x
			Local_Translation_Vector[1] = 2 * sin(Delta_Theta / 2) * ((Delta_Aux / Delta_Theta) + Aux_Offset); //cord length y
		}

		Global_Translation_Vector[0] = Local_Translation_Vector[0] * cos(Average_Orientation) + Local_Translation_Vector[1] * -sin(Average_Orientation);
		Global_Translation_Vector[1] = Local_Translation_Vector[0] * sin(Average_Orientation) + Local_Translation_Vector[1] * cos(Average_Orientation);

		Global_X += Global_Translation_Vector[0];
		Global_Y += Global_Translation_Vector[1];

		P_Left = Left_Wheel_Distance_List[i];
		P_Right = Right_Wheel_Distance_List[i];
		P_Aux = Aux_Wheel_Distance_List[i];
		P_Theta += Delta_Theta;


		LOGE("Global X: ", Global_X);
		LOGE("Global Y: ", Global_Y);
		LOGE("Global Theta: ", Global_Theta);
		LOG("\n");
	}
}


vector<vector<double>> Odometry::Get_Global_Test() {
	//std::vector<double> temp = { Global_X, Global_Y, Global_Theta };
	return Sim_Coords;
	
	/**
	*
	*	@returns vector<vector<double>> Global list X, Y, Z respectively 
	*
	*/
} 

vector<double> Odometry::Get_Global() {
	vector<double> temp = { Global_X, Global_Y, Global_Theta };
	return temp;
}

