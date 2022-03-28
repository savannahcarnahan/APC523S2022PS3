#include <iostream>
#include <string>
#include "integrator-factory.h"
#include "integrator.h"
#include "model.h"
#include "euler.h"
#include "symplectic.h"
#include "rk4.h"
using namespace std;

FactoryIntegrator::FactoryIntegrator() {}

FactoryIntegrator::~FactoryIntegrator() {}


/* Add if statement here to add another type */
std::unique_ptr<Integrator> FactoryIntegrator::createIntegrator
        (string integrator_type, double dt, const Model &model)
{
      if(integrator_type.compare("euler")==0) return make_unique<Euler>(dt, model);
      if(integrator_type.compare("symplectic")==0) return make_unique<Symplectic>(dt, model);
      if(integrator_type.compare("rk4")==0) return make_unique<RK4>(dt, model);
      else {cout<<"Invalid integrator type"<<endl; return NULL;}
}

