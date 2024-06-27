#include "functionalities.h"



//whatever you write in emplace back, it should be "sufficient material"
//to make a new instance for the container of that specific type

//type : vector of Engine pointers-----> we need materials to make a new Engine*
//void CreateEngines(Engine **engines, unsigned int size)
//{
   /*
    engines[0] = new Engine{4, 45, 23.0f};
    engines[1] = new Engine{5, 33, 56.0f};
    engines[2] = new Engine{6, 37, 27.0f};
    */
// }

void CreateEngines(std::vector<Engine *> &engines)
{

   engines.emplace_back(new Engine (101, 540, 290.0f) );
   engines.emplace_back(new Engine (102, 340, 257.0f) );
   engines.emplace_back(new Engine (103, 640, 380.0f) );
   
}

int AverageHorsePower(const std::vector<Engine *> &engines)
{   
    float total {0.0f}; //
    std::size_t validPointerCount {0};


//range-based for loop (for -each loop)
/*
    for each const Engine pointer "called e" present in engines
*/
    for(const Engine* e: engines ) {
        if (e){
        total += e->horsepower();
        validPointerCount++;
    }
  } 
 
}

float FindToqueById(const std::vector<Engine *> &engines, unsigned int id)

{
    bool atleastOneValidPointerFound {false};

    for(const Engine* e : engines) {
        if(e) {
            atleastOneValidPointerFound = true;
            if (e->id() == id) {
                return e->torque();
            }
        }
    }
    if (!atleastOneValidPointerFound) {
        throw NoValidEngineFoundException("No valid engines present in Data");
    }
    throw IdNotFound("Match was not found");
}
/*    for(std::size_t i = 0; i <engines.size(); i++) {
        if (engines[i]) {
            validPointerCount++;
            total += engines[i]->horsepower();
        }
    }
    return total / validPointerCount;
}
*/

/*int AverageHorsePower(Engine **engines, unsigned int size)
{
    if(size==0)
    {
        return 0;
    }
    int total = 0;
    int counter = 0;
    bool isvalidptr = true;
    for(int i = 0; i < size; i++) {
        if(engines[i]) {
            isvalidptr=true;
            total=total+engines[i]->horsepower();
            counter++;
        }
    }
    if(isvalidptr){
        return total/counter;
    }
    return 0;
} */



/* float FindToqueById(Engine **engines, unsigned int size, unsigned int id)
{
         if(size==0){
        return 0.0f;
    }
    for(int i = 0; i < size; i++){
        if(engines[i] && engines[i]->id()==id){
            return engines[i]->torque();
        }
    }
    return 0.0f;
}*/

/*int FindMinTorqueEngineHorsepower(Engine **engines, unsigned int size)
{   
    if(size==0){
    return 0;
    }
    int min=engines[0]->torque();
    bool validptr=true;
    for(int i = 0; i < size; i++) {
        if(engines[i]->torque()<min) {
            validptr=true;
            min=engines[i]->torque();
        }
    }
    if(validptr){
        return min;
    }
    return 0;
} 
*/
int FindMinTorqueEngineHorsepower(const std::vector<Engine *> &engines)
{
    bool atleastOneValidPointerFound {false};

    float currentMinTorque { engines[0]->torque() };  //to calculate min and max and how to recognize the first valid data

    std::size_t indexOfMinTorque (-1);
    std::size_t k = 0;

    for(const Engine* e : engines) {
        if (e) {
            atleastOneValidPointerFound = true;

            if(e->torque() < currentMinTorque ) {
                currentMinTorque = e->torque();
                indexOfMinTorque = k;
            }
        }
        k++;
    }
    return 0;
}




/*
    Think about input to a function

    Think about 1 sure-shot way of completing the function and getting a valid output

    Now start thinking of all possible ways, functions may not be completed based on inputs
    provided and system situations.
*/

//ctrl+shift+l
