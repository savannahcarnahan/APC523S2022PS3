#include <iostream>
#include <memory>
#include <string>
#include "integrator-factory.h"
#include "model-factory.h"

using namespace std;

int printStep(double t, double *conds, int size);

int main(int argc, char *argv[])
{
    double dt = stod(argv[1]);
    string model_type=argv[2];
    string integrator_type=argv[3];
    int steps=atoi(argv[4]);
    double t=stod(argv[5]);
    double *conds;
    conds=(double*)calloc(2,sizeof(double));

    unique_ptr<Model> model = FactoryModel::createModel(model_type);
    unique_ptr<Integrator> integ = FactoryIntegrator::createIntegrator(integrator_type, dt, *model);
    printStep(t, conds, model->dimen());
    for(int i=0; i<steps; i++)
    {
        integ->Step(t, conds);
	t+=dt;
	printStep(t, conds, model->dimen());
    }

    
    return 0;
}


int printStep(double t, double *conds, int size)
{
  printf("%15.8f ", t);
  int i = 0;
  while(i<size)
  {
    printf("%15.8f", conds[i]);
    i++;
    if(i<size) printf(" ");
  }
  printf("\n");
  return 0;
}
