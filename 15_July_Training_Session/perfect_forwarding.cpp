#include <iostream>
#include <memory>
#include "Employee.h"

template <typename T>
void Destination(T&& arg) {
    std::cout << 
}

template<typename I, typename... Args>
void Forward(Args&&...n1) {
     return std::std::forward<Args>(n1)...);
}

int main(){
    //Forward
    Forward<int>(10);  //rvalue of type int
    std::shared_ptr<Employee> sptr = std::make_shared<Employee>( 103, "Shruti", 6700.0f, 26, 6.0f );

                                                              
}

/*
                                                                 //int,  const char, float, int, float
    std::shared_ptr<Employee> sptr = std::make_shared<Employee>( 103, "Shruti", 6700.0f, 26, 6.0f );  //take 5 parameters, convert into given type employee, object must be on heap, where object is created it will be stored in shared pointer 
}
    1) This is an assignment operation: RHS HAS TO BE ASSIGNED TO LHS!
        RHS IS EXECUTED FIRST

    2) RHS IS A FUNCTION. FUNCTIONS ARE CALLED WITH PARAMETERS!   5 parameters have been provided
*/


/*
    what is a forwarding function?

    A forwarding function is a template function that accepts parameters
    to call function F.

    It will always be a variadic template

    It will always use the built in tool called std::forward

    All parameters received in the dunction shall be of type "Something" with the symbol

    <function-name>(Something&&....values)

    i.e. The function shall receive one or more template parameters using ..
    with &&

    make shared function doesn't store , it forwards.
*/

/*
    void magic(int&& data);
    ///////////////////////////////////
    template<typename T>
    void magic(T&& data);   //T&& does not mean- rvalue of type T, it means a forwarded function
*/