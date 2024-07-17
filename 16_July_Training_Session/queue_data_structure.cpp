/*
    10 20 30 40

    I would like to store data continuously / I want to access previous and next element of 
    a certain element in the fastest time.

    API- mechanism to access features of database.
*/


#include "Employee.h"
#include <queue>
#include <memory>

using EmployeePtr = std::shared_ptr<Employee>;
using DataContainer = std::queue<EmployeePtr>;

void CreateEntriesForQueue(DataContainer& data) {
    data.emplace( std::make_shared<Employee>(101, "Sushree", 9000.0f, 22, 4.0f));
    data.emplace( std::make_shared<Employee>(102, "Sukanya", 5000.0f, 25, 6.0f));
    data.emplace( std::make_shared<Employee>(103, "Shruti", 8000.0f, 27, 7.0f));
    data.emplace( std::make_shared<Employee>(104, "Shru", 4500.0f, 28, 9.0f));
}



/*

                                  101, "Sushree", 9000.0f, 22, 4.0f
                                    ^       
                                    |                                102, "Sukanya", 5000.0f, 25, 6.0f
                                    |                                 ^
                                    |                                 |                                   103, "Shruti", 8000.0f, 27, 7.0f  
<-----extract items from here    [     [   0x800H ]  ]           [  [ 0x296H ] ]                                        
                 queue front                                                 queue back

*/




int main() {
    DataContainer employees{};
    CreateEntriesForQueue(employees);

    /*
        queue is a  FIFO data structure
        Insertion of items at one end and retrieval from the other
    */

   std::cout << *employees.front() << "\n";

   /*
    we can check size
   */

  std::cout << employees.size() << "\n";

  /*
    Can only read/fetch the data at the end of the queue
  */

  std::cout << employees.back() << "\n";
}


//data accepted first must be retrieved first