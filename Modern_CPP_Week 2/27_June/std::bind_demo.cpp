/*
    std::bind allows us to "refactor"/"repurpose"/"remodel" an existing function
    to create "partially-implemented" functions
*/

/*
    cp   -r   source    destination

    strcpy(destination, source)

    in bind: first goes to first, second goes to third, third goes to second and fourth goes to fourth

    g(x) is a partial function implemented on f(x,y) where y is 4
*/

#include <iostream>
#include <functional>


void formula(int x, int y, int z) {
    std::cout << ( (x + y) - z);
}

int main() {

    //formula(10, 20, 30);  ///0
    //formula(20, 30, 10) ;//40

    auto partial_formula = std::bind(&formula, 100, std::placeholders::_1, 
    std::placeholders::_2);

    partial_formula(10, 90);  //formula(100,10,90)

    auto swapped_formula = std::bind(&formula, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);

    swapped_formula(10,20,30); //formula(20,10,30)

    auto weirdly_mapped_formula = std::bind(&formula, 100, 200, std::placeholders::_2);

    weirdly_mapped_formula(99, 10);  //99 discareded because _2 was not used
}