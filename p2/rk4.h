#ifndef RK4_H_
#define RK4_H_

#include "integrator.h"
class Model;			// Forward declaration

class RK4 : public Integrator
{
public:
  RK4(double dt, const Model &model); // constructor
  ~RK4();				// destructor

  int Step(double t, double *x);
  
private:
  const double dt_; 		// timestep
  const Model &model_;		// functor to evaluate f(x,t)
  const int dimen_;		// dimension of state x

  double *fx_;			// will point to temporary scratch
				// space to hold f(x,t)
  double *temp;
  double *x1_;
  double *x2_;
  double *x3_;
  double *x4_;
};

#endif  // RK4_H
