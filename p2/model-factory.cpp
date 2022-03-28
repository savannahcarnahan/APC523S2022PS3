#include <iostream>
#include <string>
#include "model-factory.h"
#include "model.h"
#include "udo.h"

using namespace std;

FactoryModel::FactoryModel() {}

FactoryModel::~FactoryModel() {}


/* Add if/else statement here to add another type */
std::unique_ptr<Model> FactoryModel::createModel
        (string model_type, double *params)
{
      if(model_type.compare("udo")==0) return std::make_unique<UDOscillator>(params);
      else {cout<<"invalid model type"<<endl; return NULL;}
    
}

