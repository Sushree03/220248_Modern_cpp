#include "Operations.h"

int main() {
    //step 1: make objects

    Operations::CreateCarsAndBikes();

    //step 2 : Execute parallel functions
    Operations::MapThreads();
    Operations::JoinThreads();

    //step 3: serial functions

    std::optional<unsigned int> result1 = Operations::FindSeatCountForGivenId("c101");

    if( result1.has_value() ) {
        std::cout << "Seat count for id is: " << result1.value()<<"\n";
    }

    std::optional<VrType> result2 = Operations::ReturnMatchingInstance("c101");

    if( result2.has_value() ) {
        std::cout << "Matching instance found: "<<"\n"; 

        std::visit( [](auto&& val){ std::cout << *val << "\n"; }, result2.value() ); 
    }

}