#include "../PID/PID.hpp"
#include "../include.hpp"
#include <iostream>

class Linear : public PID{
private:
    double Total_Distance, Max_Speed;



public:

    /**
     * @brief Construct a new Linear object
     * 
     * @param Dis
     * @param MS 
     */
    Linear(double Dis, double MS);
    Linear();

};