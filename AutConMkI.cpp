#include <iostream>
#include "AutoControl.h"
#include <chrono>

int main(){
    SSModel testmodel;

    auto start_time = std::chrono::system_clock::now();
    
    float x[12] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    float r[12] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    for(int i = 0; i<=0;i++){

        testmodel.AssignX(x);
        testmodel.AssignR(r);
        testmodel.CalculateError();
        float roll_com = testmodel.CalculateRoll();
        float pitch_com = testmodel.CalculatePitch();
        float Vx_com = testmodel.CalculateVx();
        
        }

    auto end_time = std::chrono::system_clock::now();
    std::chrono::duration<double> samp_time = end_time-start_time;
    std::cout<<samp_time.count();
   
    return 0;
}