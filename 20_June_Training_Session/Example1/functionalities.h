#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H


#include "Engine.h"
#include <vector>
#include "NoValidEngineFoundException.h"
#include "IdNotFound.h"

using Container=std::vector <Engine*>;

void CreateEngines(Container& engines);     //to do any operation we need to access

int AverageHorsePower(const Container& engines);  //passing parameters by reference

float FindToqueById(const Container& engines, unsigned int id);

int FindMinTorqueEngineHorsepower(const Container& engines);

#endif // FUNCTIONALITIES_H
