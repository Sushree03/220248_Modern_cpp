/*
    3 styles of programming
        - structure oriented  - lots of coding
        - object oriented - data modelled with relationship
        - functional - user dependent, what operations are to be performed on which data



        Rules for functional programming

        a) Treat functions as if they are objects
        b) If possible, maintain purity of function  - send data by value, do not give references, give inputs
        c) Functions have categories based on what they do

            example 1: a function that transforms x1, x2, x3
            into y1, y2, y3 based on a transformation logic
            is called a "Map function"

            e.g: data = [1, 2, 3, 4, 5]
                 fn = (n) -> n * n

                result : 1, 4, 9, 16, 25

                In map function application, number of inputs
                and outputs in same

                [101 27000  ]   [102 90000  ]  [103  88000 ]

                fn = (e)-> salary * 0.1f //as tax

                result = 2700, 9000, 8800

            example 2: a function that "removes/identifies" from the input, a select 
            number of values based on a criteria [ Filter function ]

                e.g: data = [1, 2, 3, 4, 5]
                     fn = n-> n % 2 == 0
                     result = [2,4] //only 2 input values satisfy the condition(prdicate)

            example 3: a function thatr accumulates/gathers/aggregates multiple input values into one, final,
            singular output value [reduce/accumulates functions]

                e.g : data = [1,2,3,4,5]
                      fn = (x,y)-> x+y

                      result : 15

                    total     1   2    3      4       5
                        0     |   |
                        |     |   |
                           1      |
                           |      |    
                                3      |
                                |      |
                                  6          4
                                  |          |
                                  
    
*/

// Lambda function

#include <iostream>
#include <functional>

using Operation = std::function<int32_t(int32_t)>;    //whatever in bracket always input and outside bracket is always output

auto Adaptor(Operation fn, int32_t value) -> void {

    std::cout << fn(value);
}


int main() {
    //takes one input of type int32_t by value and returns an int32_t value
    //the function should multiply input number by 100

    auto fn = [](int32_t n) -> int32_t {  return n* 100; };   //objects creates a class in the background

    //create a block in the current block lambda's life icreases
    //can capture things from surroundings 

    int n1 = 100;
    auto demo_fn = [n1] (int32_t num) mutable { n1 = 99;return num* n1; }; //capture by value, not modifiable but if we use mutable we can modify the lambda
     // capture by reference

    Adaptor(fn, 10);



}