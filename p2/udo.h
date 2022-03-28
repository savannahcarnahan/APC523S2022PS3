#ifndef UDO_H_
#define UDO_H_

#include "model.h"

// Undamped-Driven Oscillator (UDOscillator):
//   \dot x = v
//   \dot v = (F/m) cos(omega_F t) - omega^2 x
class UDOscillator : public Model
{
public:
  UDOscillator();
  // Constructor (initialize with params)
  //
  // `params[]` should be an array of length 3, holding the following
  // parameters in order:
  // omega_F_ --> frequency of harmonic forcing
  // Fm_ --> magnitude/mass
  // omega_ --> natural frequency (sqrt(k/m))
  UDOscillator(double *params);
  ~UDOscillator();
  
  int rhs(double t, const double *x, double *fx) const;

  // Functions *defined* in the header are automatically `inline`-d --
  // `dimen() is so simple that we want to help the compiler figure
  // out that it could (should?)  inline it
  int dimen() const
  {
    return dimen_;
  }
private:
  // Parameters of the driver
  const double omega_F_;
  const double Fm_;

  // Parameters of oscillator itself
  const double omega_;


  // Dimension of state (`static` --> shared by all DDO instances)
  static const int dimen_ = 2;
};

#endif  // UDO_H_
