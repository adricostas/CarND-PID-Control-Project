#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
  
	i_error = 0.0; // integral cte
 	p_error = numeric_limits<double>::max(); // previous cte
	d_error = 0.0; // differential cte
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error =  cte;
	i_error += cte;

}

double PID::TotalError() {
	total_error += p_error * p_error;
	return total_error;
}

