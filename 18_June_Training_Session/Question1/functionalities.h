#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
 
#include "Engine.h"
void CreateObjects(Engine** engines, unsigned int size);
int AverageHorsePower(Engine** engines, unsigned int size);
float FindTorqueBYId(Engine** engines, unsigned int size,unsigned int id);
int FindMinTorqueEngineHorsepower(Engine** engines, unsigned size);
 
#endif // FUNCTIONALITIES_H