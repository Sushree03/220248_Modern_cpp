#include "functionalities.h"
 
void CreateObjects(Engine **engines, unsigned int size)

{

    engines[0]=new Engine(1, 23, 20.0f);

    engines[1]= new Engine(2, 4, 9.0f);

    engines[2]= new Engine(3, 37, 8.0f);
 
}
 
int AverageHorsePower(Engine **engines, unsigned int size)
 
{

    if(size==0){

        return 0;

    }

    int total= 0;

    int counter =0;

    bool isvalidptr=true;

    for(int i=0; i<size; i++){

        if(engines[i]){

            isvalidptr=true;

            total=total+engines[i]->horsepower();

            counter++;

        }

    }

    if(isvalidptr){

        return total/counter;

    }

    return 0;

}
 
float FindTorqueById(Engine **engines, unsigned int size,unsigned int id)

{

    if(size==0){

        return 0.0f;

    }

    for(int i=0; i<size;i++){

        if(engines[i] && engines[i]->id()==id){

            return engines[i]->torque();

        }

    }

    return 0.0f;

}
 
int FindMinTorqueEngineHorsepower(Engine** engines, unsigned size)
{

    if(size==0){

        return 0;

    }

    int min=engines[0]->torque();

    bool validptr=true;

    for(int i=0; i<size;i++){

        if(engines[i]->torque()<min){

    min= engines[i]->torque();

        }

    }

    if(validptr){

        return min;

    }
 
    return 0;
}
