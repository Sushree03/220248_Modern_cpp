#include"functionalities.h"
#include<iostream>

int main()

/*{
    Engine* engines[3];
    CreateEngines(engines, 3);
    AverageHorsePower(engines, 3);
    std::cout<<"the average power is "<<AverageHorsePower(engines,3)<<"\n";
    std::cout<<FindToqueById(engines, 3, 1)<<"\n";
    std::cout<<FindMinTorqueEngineHorsepower(engines, 3)<<"\n";
}
*/

{
    std::vector<Engine*> engines;
    CreateEngines(engines);

    try{
        AverageHorsePower(engines);
    } catch(NoValidEngineFoundException& ex) {
        //////// your handlig logic goes here
    }

    try{
        FindToqueById(engines, 101);
    }catch (NoValidEngineFoundException& ex){
        //////
    }catch (IdNotFound& ex) {
        ///////
    }
}