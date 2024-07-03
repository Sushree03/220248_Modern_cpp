#include <iostream>
#include <functional>

void Demo(void(*ptr)(int n1, int n2) ) {                  //ptr to a function
    ptr(10,20);                
}

int main()
{
    auto fn = [] (int n1, int n2) {std::cout << n1 + n2; };
    // Demo(&fn);       //lambdas are objects but we are passing address of a function
    Demo(+fn);       //(+) symbol before a variable makes lambda to be used as a function pointer
}