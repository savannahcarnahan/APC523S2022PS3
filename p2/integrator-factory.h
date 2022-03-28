#ifndef INTEGRATOR_FACTORY_H
#define INTEGRATOR_FACTORY_H

#include <iostream>
#include <memory>
#include <string>
#include "integrator.h"
#include "model.h"

using namespace std;

class FactoryIntegrator
{
public:
  //enum

  FactoryIntegrator();
  virtual ~FactoryIntegrator();
  static std::unique_ptr<Integrator> createIntegrator
	  (string integratorType, double dt, const Model &model); 
};





#endif
