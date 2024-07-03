#include <iostream>
#include <optional>


//Factorial takes 1 int16_t by value and optionally returns a 
//size_t (sometimes, not always)
  //or
//Factorial function MAY OR MAY NOT RETURN A VALUE
std::optional<size_t> Factorial(int16_t val) {

    if (val < 0) {
        return std::nullopt; //symbolic data value to indicate "NULL"
    }

    else if (val == 0 || val == 1) {
        return 1;
    }

    else {
        size_t total {1};
        for(size_t i = 2; i <= val; i++) {
            total += i;
        }

        return total;

    }
    
}

int main() {
    
    if(std::optional<size_t> result = Factorial(-5); result.has_value() ) {
        std::cout << "Factorial is: " << result.value();
    }

    else {
        std::cerr << "Factorial did not return a value\n";
    }
}  


/*
    16 binary bits can generate a total of 2^16 = = <65536

        -32768 ....            0 .......    32768

*/


/*
    define a function which takes a value

    if value is negative , I have nothing to return, use an alternate symbol to
        indicate"nothing"   (nullopt is nothing)

    else if value is 0 or 1, I should return 1

    else {
    do a product of 2 ... value. Return the total
    }
    
    ///////////////////////////////

    main code is :

    call the function with a value. we get a "surprise" box!

    if surprise box has a value, print the value

    else {
    show a error message showing "I got nothing in the surprise box"
    }
*/