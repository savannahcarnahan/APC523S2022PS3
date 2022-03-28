#include "udo.h"

#include <cmath>  
using namespace std; 

UDOscillator::UDOscillator() : omega_F_(5.0),
			       Fm_(1.0),
                               omega_(.1)
{}
UDOscillator::UDOscillator(double *params) : omega_F_(params[0]),
					     Fm_(params[1]),
					     omega_(params[2])
					   
{}				// Empty constructor body
				// (constructor's only job for this
				// class is to initialize some const
				// members, and const members must be
				// initialized in the initializer
				// list)

// Empty destructor (no extra memory/objects to free/delete)
UDOscillator::~UDOscillator() {}

// rhs()
int UDOscillator::rhs(double t, const double *x, double *fx) const
{
  fx[0] = x[1];
  fx[1] = Fm_*cos(omega_F_*t) - (omega_*omega_)*x[0] ;

  return 0;
}

