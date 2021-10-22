#include "NonLinear.hpp"

//(const vector<double> End_Point, const int points, bool standard = true, vector<double> one = {0, 0}, vector<double> two = {0, 0}, vector<double> three = {0, 0}){

NonLinear::NonLinear(vector<double> End_Point, int points, bool standard, 
                     vector<double> one, vector<double> two, vector<double> three)
{
    if (standard == true)
    {

        P_One_Point = {0.0, 0.0};
        P_Two_Point = {End_Point[0] / 2, 0};
        P_Three_Point = {End_Point[0] / 2, End_Point[1]};
        P_Four_Point = {End_Point[0], End_Point[1]};

        /**
            P_One_Point = { 0.0, 0.0 };
            P_Two_Point = { 0.0, End_Point[1] / 2 };
            P_Three_Point = { End_Point[0], End_Point[1] / 2 };
            P_Four_Point = { End_Point[0], End_Point[1] };
            */
    }
    else
    {
        P_One_Point = one;
        P_Two_Point = two;
        P_Three_Point = three;
        P_Four_Point = {End_Point[0], End_Point[1]};
    }
    this->Path_Generation(points, P_One_Point, P_Two_Point, P_Three_Point, P_Four_Point);
}

NonLinear::NonLinear(){}    

void NonLinear::Path_Generation(int Points, vector<double> P1, vector<double> P2, vector<double> P3, vector<double> P4){
    vector<double> x_Points;
    vector<double> y_Points;

    if ((Points % 2) == 0){
        Points++;
    }
    // Points generated must be an odd number for arch grouping to occur correctly
    int i = 0;
    for (double t = 0; t <= 1.00000001; t += (1.00 / (Points - 1.0))){
        //Beizer curve uses values from 0 to 1 in generating the path. 0 <= t <=1
        if (t > 1)
        {
            t = 1;
        } // Prevents t being > 1

        // Creation of x point of the beizer curve relative to t increments
        double x = this->Beizer_Formula(t, 'x');

        // Creation of y point of the beizer curve relative to t increments
        double y = this->Beizer_Formula(t, 'y');

        // Stores the coordinates into a list
        x_Points.push_back(x);
        y_Points.push_back(y);

        cout << "Point " << i << ": "
             << "(" << x_Points[i] << "," << y_Points[i] << ")"
             << "\n";
        // Prints the point in the Beizer formula given t
        i += 1;
    }
    int rows = (Points - 1) / 2; // Determines the number archs in path
    int columns = 3;             // Points will grouped in 3 to generate an arch

    vector<vector<double>> temp_X(rows, vector<double>(columns, 0)),
        temp_Y(rows, vector<double>(columns, 0));
    this->set_Points_Grouped(temp_X, temp_Y); //Creates the dimensions of the groupings

    // Groups the points of set 3 while the last point will be the first of the following group
    int x = 0, y = 0;
    for (int row = 0; row < rows; row++){
        for (int colum = 0; colum < columns; colum++)
        {
            Points_Grouped_X[row][colum] = x_Points[x + colum - y];
            Points_Grouped_Y[row][colum] = y_Points[x + colum - y];
        }
        x += 3;
        y += 1;
    }
    // Print Points Grouped
    for (int row = 0; row < rows; row++){
        for (int colum = 0; colum < columns; colum++)
        {
            //cout << Points_Grouped_X[row][colum] << " ";
        }
        //cout << endl;
    }
    // Generates archs for the path
    this->Arch_Generation(Points_Grouped_X, Points_Grouped_Y, true);
}


void NonLinear::Arch_Generation(vector<vector<double>> Points_X, vector<vector<double>> Points_Y, bool Full_Path = false)
{
    vector<double> curCirPoint, Mid_Point;
    vector<double> Arch_Degree_List;
    vector<double> Radius_List;
    vector<double> Distance_List;
    double Total_Distance;
    char Turn_Direction;

    for (int i = 0; i < Points_X.size(); i++){
        double x1 = Points_X[i][0], y1 = Points_Y[i][0],
               x2 = Points_X[i][1], y2 = Points_Y[i][1],
               x3 = Points_X[i][2], y3 = Points_Y[i][2];
        double Mid_Distance, Arch_Degree, Circumference;

        // Formula to find the radius of a circle with 3 given points
        double A = x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - x3 * y2;
        double B = (pow(x1, 2) + pow(y1, 2)) * (y3 - y2) + (pow(x2, 2) + pow(y2, 2)) * (y1 - y3) + (pow(x3, 2) + pow(y3, 2)) * (y2 - y1);
        double C = (pow(x1, 2) + pow(y1, 2)) * (x2 - x3) + (pow(x2, 2) + pow(y2, 2)) * (x3 - x1) + (pow(x3, 2) + pow(y3, 2)) * (x1 - x2);
        double D = (pow(x1, 2) + pow(y1, 2)) * (x3 * y2 - x2 * y3) + (pow(x2, 2) + pow(y2, 2)) * (x1 * y3 - x3 * y1) + (pow(x3, 2) + pow(y3, 2)) * (x2 * y1 - x1 * y2);

        double radius = sqrt(((pow(B, 2) + pow(C, 2) - 4 * A * D) / (4 * pow(A, 2))));

        if (radius == INFINITY)
        {
            radius = 200;
        }
        Mid_Point = {(x1 + x3) / 2, (y1 + y3) / 2};
        curCirPoint = {-(B / (2 * A)), -(C / (2 * A))};
        if ((curCirPoint[0] == abs(INFINITY)) || (curCirPoint[1] == abs(INFINITY)))
        {
            curCirPoint[0] = -10000;
            curCirPoint[1] = 10000;
        }

        Mid_Distance = sqrt(pow((curCirPoint[0] - Mid_Point[0]), 2) + pow((curCirPoint[1] - Mid_Point[1]), 2));
        if (Mid_Distance > radius)
        {
            Mid_Distance = radius - .00000001;
        }
        // Prevents acos(Mid_Distance / radius) from Arch_Degree to have domain error
        // .0018 difference creates the closest approximated value of Arch_Degree without having domain error

        Arch_Degree = acos(Mid_Distance / radius) * (180 / PI) * 2;
        if (Arch_Degree < .01)
        {
            Arch_Degree = 0;
        }
        Circumference = (2.0 * PI * radius) * (Arch_Degree / 360.0);

        Distance_List.push_back(Circumference);
        Radius_List.push_back(radius);

        if (curCirPoint[0] < x2)
        {
            Turn_Direction = 'L';
            Arch_Degree_List.push_back(Arch_Degree);
        }
        else
        {
            Turn_Direction = 'R';
            Arch_Degree_List.push_back(-Arch_Degree);
        }
        //LOGE("Turn Direction: ", Turn_Direction);
    }

    Total_Distance = accumulate(Distance_List.begin(), Distance_List.end(), 0.0);

    if (Full_Path == true){
        Full_Path_Info.Arch_Degree_List = Arch_Degree_List;
        Full_Path_Info.Radius_List = Radius_List;
        Full_Path_Info.Arch_Distance_List = Distance_List;
        Full_Path_Info.Total_Distance = Total_Distance;
        LOGE("Total Distance: ", Total_Distance);
        LOG("\n");
    }
    else{
        Temp_Path_Info.Arch_Degree_List = Arch_Degree_List;
        Temp_Path_Info.Radius_List = Radius_List;
        Temp_Path_Info.Arch_Distance_List = Distance_List;
        Temp_Path_Info.Total_Distance = Total_Distance;
    }
}



void NonLinear::Absolute_Positioning(vector<double> Coord){
    Global_Coord = Coord;
}


double NonLinear::Beizer_Formula(double t, char coord)
{
    if (coord == 'x')
    {
        // Creation of x point of the beizer curve relative to t increments
        double x = ((pow((1.0 - t), 3)) * P_One_Point[0]) + (3 * (pow((1.0 - t), 2)) * t * P_Two_Point[0]) + (3 * (1.0 - t) * pow(t, 2) * P_Three_Point[0]) + (pow(t, 3) * P_Four_Point[0]);
        return x;
    }
    else
    {
        // Creation of y point of the beizer curve relative to t increments
        double y = ((pow((1.0 - t), 3)) * P_One_Point[1]) + (3 * (pow((1.0 - t), 2)) * t * P_Two_Point[1]) + (3 * (1.0 - t) * pow(t, 2) * P_Three_Point[1]) + (pow(t, 3) * P_Four_Point[1]);
        return y;
    }
}


void NonLinear::Run_Sim()
{
    // Current distance left, right, and aux wheels
    double Left_Wheel_Distance_C = 0, Right_Wheel_Distance_C = 0, Aux_Wheel_Distance_C = 0;
    std::vector<double> Left_Wheel_Distance_C_List, Right_Wheel_Distance_C_List, Aux_Wheel_Distance_C_List;
    double Global_Path_Theta = 0;
    for (int i = 0; i < Full_Path_Info.Arch_Degree_List.size(); i++)
    {
        Global_Path_Theta += Full_Path_Info.Arch_Degree_List[i];
        if (abs(Global_Path_Theta) < .001)
        {
            Global_Path_Theta = 0;
        }

        double Left_Wheel_Distance_L, Right_Wheel_Distance_L, Aux_Wheel_Distance_L;

        if (Full_Path_Info.Arch_Degree_List[i] < 0)
        { // Right Turn
            Left_Wheel_Distance_L = (abs(Full_Path_Info.Arch_Degree_List[i] / 360)) * (Full_Path_Info.Radius_List[i] + Base_Radius) * 2 * PI;
            Right_Wheel_Distance_L = (abs(Full_Path_Info.Arch_Degree_List[i] / 360)) * (Full_Path_Info.Radius_List[i] - Base_Radius) * 2 * PI;
        }
        else
        { // Left Turn
            Left_Wheel_Distance_L = (abs(Full_Path_Info.Arch_Degree_List[i] / 360)) * (Full_Path_Info.Radius_List[i] - Base_Radius) * 2 * PI;
            Right_Wheel_Distance_L = (abs(Full_Path_Info.Arch_Degree_List[i] / 360)) * (Full_Path_Info.Radius_List[i] + Base_Radius) * 2 * PI;
        }

        Aux_Wheel_Distance_L = -(Full_Path_Info.Arch_Degree_List[i] * (PI / 180)) * Aux_Offset;
        Aux_Wheel_Distance_C += Aux_Wheel_Distance_L;
        if (abs(Aux_Wheel_Distance_C) < .001)
        {
            Aux_Wheel_Distance_C = 0;
        }

        // Integrates distance traveled given each iteration
        Left_Wheel_Distance_C += Left_Wheel_Distance_L;
        Right_Wheel_Distance_C += Right_Wheel_Distance_L;

        Left_Wheel_Distance_C_List.push_back(Left_Wheel_Distance_C);
        Right_Wheel_Distance_C_List.push_back(Right_Wheel_Distance_C);
        Aux_Wheel_Distance_C_List.push_back(Aux_Wheel_Distance_C);

        LOGE("Iteration ", i);
        LOGE("Left Wheel Distance L: ", Left_Wheel_Distance_L);
        LOGE("Right Wheel Distance L: ", Right_Wheel_Distance_L);
        LOGE("Aux Wheel Distance L: ", Aux_Wheel_Distance_L);

        LOGE("Left Wheel Current Distance: ", Left_Wheel_Distance_C);
        LOGE("Right Wheel Current Distance: ", Right_Wheel_Distance_C);
        LOGE("Aux Wheel Current Distance: ", Aux_Wheel_Distance_C);
        LOG("\n");
    }
    Wheel_Movement_Info = {Left_Wheel_Distance_C_List, Right_Wheel_Distance_C_List, Aux_Wheel_Distance_C_List};
}
/**
*
*/

void NonLinear::Run_Sim_2(double Speed, std::vector<std::vector<double>> Global_Positions)
{
    Global_X = Global_Coord[0], Global_Y = Global_Coord[1], Global_Theta = Global_Coord[0];
    LOG("HI");
}
/**
*
*/
