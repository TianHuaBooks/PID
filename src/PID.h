#ifndef PID_H
#define PID_H

#include <random>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double _Kp;
  double _Ki;
  double _Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  * Return error 
  */
  double UpdateError(double cte, double dt);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
    
    
private:
    std::random_device _rd;
    std::mt19937 _gen{_rd()};
    double _prev_cte{0.0};
    double _total_cte{0.0};
};

#endif /* PID_H */
