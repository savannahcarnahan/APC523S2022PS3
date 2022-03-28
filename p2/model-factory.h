#ifndef MODEL_FACTORY_H
#define MODEL_FACTORY_H

#include <iostream>
#include <memory>
#include <string>
#include "model.h"

using namespace std;

class FactoryModel
{
public:

  FactoryModel();
  virtual ~FactoryModel();
  
  static std::unique_ptr<Model> createModel
	  (string model_type); 
};





#endif
