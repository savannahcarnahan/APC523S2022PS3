#include "symplectic.h"
#include "model.h"

// Euler objects should be initialized with a timestep and a Model
Symplectic::Symplectic(double dt, const Model &model)
  : dt_(dt), model_(model), dimen_(model.dimen()) // Initialization
						  // list
{
  // Constructor pre-allocates heap space for rhs() results
  fx_ = new double[dimen_];
}

// Destructor housekeeping -- free space used for rhs() results
Symplectic::~Symplectic()
{
  delete [] fx_;
}

// if slow reconfigure to do two calcs instead of four
int Symplectic::Step(double t, double *x)
{
  model_.rhs(t, x, fx_);
  
  x[1] += dt_ * fx_[1];
  
  model_.rhs(t, x, fx_);

  x[0] += dt_ * fx_[0];
  
  return 0;
}
