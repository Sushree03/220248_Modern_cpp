#include <iostream>
#include <functional>


void formula(int& x, int y, int z) {
    std::cout << x + y + z << "\n";
}


int main() {
    int a = 10;
    auto binded_formula = std::bind(&formula, std::ref(a), 100, std::placeholders::_1);

    binded_formula(99);   //formula(a, 100, 99)

    //called formula (by copying x, assigning 100 to y and assigning 99 to z)
    
    //create a reference wrapper for a variable to be passed in place of x
}

//std::ref takes a lvalue and immediately converts into a reference wrapper


//cannot use reference in binds, it is to be kept in a wrapper, or else bind will take it as a value and not reference.
