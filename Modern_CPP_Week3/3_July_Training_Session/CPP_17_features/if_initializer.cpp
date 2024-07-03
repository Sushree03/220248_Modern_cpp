/*
    bool definition fn() {
    ////
    }

    main() {

    bool flag fn();

    if(flag) {
    ////
    }

    else {
    ////
    }  ///flag should be erased at the end of the line!

    ///// flag is gone
 }
*/

#include <iostream>

bool CheckDivisibilityBy3(int32_t number) {
    return number % 3 == 0;
}

int main() {
    int32_t n1 {10};
    //if flag variable is initialized and the flag is also true
    if(  bool flag = CheckDivisibilityBy3(n1); flag  ){
        std::cout << "number is divisible by 3";
    }

    else {
        std::cerr << "Flag is set at: "<<std::boolalpha<< flag << "Number not divisible\n";
    }

    // std::cout << "Cannot access flag row: " << flag;
}

