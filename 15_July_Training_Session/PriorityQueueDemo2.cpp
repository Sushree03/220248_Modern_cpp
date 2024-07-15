#include "Employee.h"
#include <queue>



int main() {
   
   //priority is reverse of comparator operator : > means min heap, < means max heap
   //comparators~
    auto fn = [](const Employee& e1, const Employee& e2) {return e1.experienceYears() > e2.experienceYears();}; //givrn 2 employees both accepted as l value reference

    std::priority_queue<Employee,std::vector<Employee>, decltype(fn) > pq { fn };   //storing employees by creating a container in background, comparison will be done by fn

    pq.emplace( 101, "Sushree", 9000.0f, 22, 5.0f );
    pq.emplace( 101, "Sukanya", 4500.0f, 24, 7.0f );
    pq.emplace( 101, "Shruti", 6000.0f, 25, 8.0f );

    //who is the employee with the "HIGHEST PRIORITY"?

    std::cout << pq.top();


}
