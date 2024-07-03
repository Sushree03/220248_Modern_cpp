

#include <iostream>
#include <functional>

int main() {
    auto fn = [](int32_t number, int32_t factor) { return number * factor;};

    //while binding lambda funtions, don't use & symbol for function name
    auto partially_implemented_fn = std::bind(fn, 100, std::placeholders::_1);

    partially_implemented_fn(20);  //fn(100,20)

    partially_implemented_fn(20, 1,2,3,4,5,6);  //fn(100,20);  //all other inputs are discarded

}