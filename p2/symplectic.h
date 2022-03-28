#ifndef SYMPLECTIC_H_
#define SYMPLECTIC_H_

#include "integrator.h"
class Model;			// Forward declaration

class Symplectic : public Integrator
{
public:
  Symplectic(double dt, const Model &model); // constructor
  ~Symplectic();				// destructor

  int Step(double t, double *x);
  
private:
  const double dt_; 		// timestep
  const Model &model_;		// functor to evaluate f(x,t)
  const int dimen_;		// dimension of state x

  double *fx_;			// will point to temporary scratch
				// space to hold f(x,t)
};

#endif  // SYMPLECTIC_H
