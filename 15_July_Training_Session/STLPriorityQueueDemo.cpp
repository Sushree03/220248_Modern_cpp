#include "Employee.h"
#include <queue>

/*
    1) what kind of data goes into the priority queue?
    2) what is the backend implementation of the queue to store the data?  //vector is default coz index is involved
    3) what is the comparison logic? or (comparator)?  
    //for lesser comparison it is max heap
*/

int main() {
    std::vector<Employee> employees {};
    employees.emplace_back( 101, "Sushree", 9000.0f, 22, 5.0f ); //push operation in the stack
    employees.emplace_back( 102, "Sukanya", 4500.0f, 25, 11.0f ); //push operation in the stack
    employees.emplace_back( 103, "Shruti", 6700.0f, 26, 6.0f ); //push operation in the stack


    //all employees which are in the vector must be inserted into the heap using heapify()

    //comparators
    auto fn = [](const Employee& e1, const Employee& e2) {return e1.experienceYears() > e2.experienceYears();}; //givrn 2 employees both accepted as l value reference

    std::priority_queue<Employee,std::vector<Employee>, decltype(fn) > pq { employees.begin(), employees.end(), fn };
}

/*
    [CPP is a strongly & statically typed language]
   1)  CPP :  everything has a type, including functional!

   2) a lambda in c++ is an object that behaves like a function

   3) Lambda is always implemented by the compiler by creating a class during 
   compilation, name of the class is unknown to us

   4) So, my requirement is compiler should create fn lambda. Its type will be 
   known to the compiler.

   The declared data type for fn is what I obtain from the compiler
    
*/