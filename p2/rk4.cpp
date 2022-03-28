#include "rk4.h"
#include "model.h"

// RK4 objects should be initialized with a timestep and a Model
RK4::RK4(double dt, const Model &model)
  : dt_(dt), model_(model), dimen_(model.dimen()) // Initialization
						  // list
{
  // Constructor pre-allocates heap space for rhs() results
  fx_ = new double[dimen_];

  temp = new double[dimen_];
  x1_ = new double [dimen_];
  x2_ = new double [dimen_];
  x3_ = new double [dimen_];
  x4_ = new double [dimen_];
}

// Destructor housekeeping -- free space used for rhs() results
RK4::~RK4()
{
  delete [] x4_;
  delete [] x3_;
  delete [] x2_;
  delete [] x1_;
  delete [] temp;
  delete [] fx_;
}


int RK4::Step(double t, double *x)
{
  model_.rhs(t, x, fx_);

  int i;
  for(i=0; i<dimen_; i++) //k1
  {
     x1_[i]=x[i]; // k1/dt for x
  }
  
  for(i=0; i<dimen_; i++) //k2
  {
     x2_[i]=x[i]+fx_[i]*dt_/2; // k2/dt for x
     temp[i]=x2_[i];
  }


  model_.rhs(t, temp, fx_);

  for(i=0; i<dimen_; i++) //k3
  {
    x3_[i]=x[i]+fx_[i]*dt_/2.0;
    temp[i]=x3_[i];
  }
  
  model_.rhs(t, temp, fx_);

  for(i=0; i<dimen_; i++) //k4
  {
    x4_[i]=x[i]+fx_[i]*dt_;
    temp[i]=x1_[i]+2*x2_[i]+2*x3_[i]+x4_[i];
  }

  model_.rhs(t, temp, fx_);

  for(i=0; i<dimen_; i++)
  {
    x[i]+=fx_[i]*dt_/6.0;
    temp[i]=0;
  }


/*  for (int i = 0; i < dimen_; ++i)
  {
    x[i] += dt_ * fx_[i];
  }*/
  
  return 0;
}
