#include "Linear.hpp"

Linear::Linear(double Dis, double MS){
    Total_Distance = Dis;
    Max_Speed = MS;
    this->set_Position(Total_Distance, Max_Speed);
}