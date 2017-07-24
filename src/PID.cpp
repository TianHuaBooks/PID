#include "PID.h"
#include <random>
#include <cmath>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() 
{
}

PID::~PID()
{
}

void PID::Init(double Kp, double Kd, double Ki) {
    _Kp = Kp;
    _Kd = Kd;
    _Ki = Ki;
}

double PID::UpdateError(double cte, double dt) {
    // proptional error
    p_error = -_Kp * cte;
    // differential error
    d_error = -_Kd * (cte - _prev_cte) /dt;
    // integral error
    i_error = -_Ki * cte + i_error;
    _prev_cte = cte;
    _total_cte += cte * dt;
    
    return p_error + d_error + i_error;
}

double PID::TotalError() {
    return p_error + d_error+ i_error;
}

