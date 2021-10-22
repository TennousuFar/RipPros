#include "../PID/PID.hpp"
#include "../include.hpp"
#include <vector>
#include <math.h>
#include <numeric>
#include <iostream>

class NonLinear :  public PID{
private:
    vector<double> End_Point;
    vector<double> P_One_Point, P_Two_Point, P_Three_Point, P_Four_Point;
    vector<vector<double>> Points_Grouped_X, Points_Grouped_Y;

    //Global Position
    vector<double> Global_Coord;

    /**
     * @brief 
     * 
     * @param Points 
     * @param P1 
     * @param P2 
     * @param P3 
     * @param P4 
     */
    void Path_Generation(int Points, std::vector<double> P1, std::vector<double> P2, std::vector<double> P3, std::vector<double> P4);

    /**
     * @brief Given a 2 dimensional vector with n rows and 3 columns, it calculates information for
     *        all the archs in the full path or a specific set of points in path information
     * 
     * @param Points 
     * @param Points_Y 
     * @param Full_Path 
     * 
     *   Values below located at struct Path_Info
     *   -double Total_Distance
     *   -vector <double> Radius_List;
     *   -vector <double> Arch_Degree_List;
     *   -vector <double> Arch_Distance_List;
     */
    void Arch_Generation(std::vector<std::vector<double>> Points, std::vector<std::vector<double>> Points_Y, bool Full_Path);

    /**
     * @brief Set the Points Grouped object
     * 
     * @param X 
     * @param Y 
     */
    void set_Points_Grouped(std::vector<std::vector<double>> X, std::vector<std::vector<double>> Y)
    {
        Points_Grouped_X = X;
        Points_Grouped_Y = Y;
    };

    /**
     * @brief 
     * 
     * @param t 
     * @param coord 
     * @return double (Returns either x or y from the object's original control points)
     */
    double Beizer_Formula(double t, char coord);

    /**
     * @brief 
     * 
     */
    struct Path_Info
    {
        double Total_Distance = 0;
        std::vector<double> Radius_List;
        std::vector<double> Arch_Degree_List;
        std::vector<double> Arch_Distance_List;
    };
    Path_Info Full_Path_Info;
    Path_Info Temp_Path_Info;

protected:
    /**
     * @brief 
     * 
     * @param Coord 
     */
    void Absolute_Positioning(vector<double> Coord);

public:

    vector<vector<double>> Wheel_Movement_Info;
    
    /**
     * @brief Construct a new Non Linear object
     * 
     * @param End_Point 
     * @param points 
     * @param standard 
     * @param one 
     * @param two 
     * @param three 
     */
    NonLinear(vector<double> End_Point, int points, bool standard = true, vector<double> one = {0, 0}, vector<double> two = {0, 0}, vector<double> three = {0, 0});
    /**
     * @brief Construct a new Non Linear object
     * 
     */
    NonLinear();

    /**
     * @brief 
     * 
     * @param Speed 
     */
    void Run_Sim_2(double Speed, vector<vector<double>>);

    /**
     * @brief 
     * 
     */
    void Run_Sim();
};