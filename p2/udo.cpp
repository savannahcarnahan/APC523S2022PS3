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

int UDOscillator::solution(double t, const double *x, double *fx) const // specifically for x(0)=v(0)=0 
{
    if(omega_F_==omega_) return specialSolution(t, x, fx);
    fx[0]=Fm_/(omega_F_*omega_F_-omega_*omega_)*(cos(omega_F_*t)-cos(omega_*t));
    fx[1]=Fm_/(omega_F_*omega_F_-omega_*omega_)*(-omega_*sin(omega_F_*t)+omega_F_*sin(omega_*t));
    return 0;
}

int UDOscillator::specialSolution(t, x, fx) // when omega_F_=omega_
{
    if(omega_ != omega_F_)
    {
        cout<<"Calling nonspecial case because the forced frequency is not equal to the natural frequency"<<endl;
	return solution(t, x, fx);
    }
    fx[0]=Fm_*0.5/omega_*t*sin(omega_*t);
    return 0;
}

