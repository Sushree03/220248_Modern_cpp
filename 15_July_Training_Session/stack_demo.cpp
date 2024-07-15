#include <stack>
#include <iostream>
#include "Employee.h"


/*
    A stack is never used for accessing all items together
    //no looping operations
*/
int main() {
    std::stack<Employee> s{};

    s.emplace( 101, "Sushree", 9000.0f, 22, 5.0f ); //push operation in the stack
    s.emplace( 102, "Sukanya", 4500.0f, 25, 11.0f ); //push operation in the stack
    s.emplace( 103, "Shruti", 6700.0f, 26, 6.0f ); //push operation in the stack


    //Display top item and then pop
    std::cout << s.top() << "\n";
    //pop

    s.pop();

    //s.push() // don't do as we have to enable copy or move

    //check size
    std::cout << s.size() << "\n";

    //check empty
    std::cout << "Checking for empty: " << std::boolalpha << s.empty() << "\n";

}