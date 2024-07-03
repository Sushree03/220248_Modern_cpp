//week 2 :Modern CPP stats

/*

    software to be built
    -----> diagnostics of a car at workshop
*/
/*
    objective: I want to write an "Adaptor" function
    which will accept
    a) vector of integer 32 bit numbers
    b) a function that accepts a single integer 32 value and returns void.

    Adaptor should "map" function provided onto the data provided.
    
*/

#include<iostream>
#include<vector>

void Square(int32_t number) {
    std::cout << number * number << "\n";
}

void Cube(int32_t number) {
    std::cout << number * number * number << "\n";
}

void Adaptor(  void (*fn)(int32_t number),std::vector<int32_t>& data )    //takes 2 parameters   //user control to change vector of values and check logic  //no other things can be
{
    //for each number in data, run the function with the number
    for(int32_t val : data) {
        (*fn)(val);
    }
}


int main() {


    std::vector<int32_t> data {1,2,3,4,5};
    Adaptor(&Cube, data);
    Adaptor(&Square, data);


    //if user wants they can design their own function and use it
    //logic to process "data"


    //int n1 = 10;
    //int* ptr = &n1;

    //function ka pointer ---> address of a function

   // void (*ptr)(int32_t) = &Square;

    // void (*temp) (int32_t number) = &Cube;

   // (*temp)(10);  //call Cube function as CUBE 10
    //(*ptr) (9);

}