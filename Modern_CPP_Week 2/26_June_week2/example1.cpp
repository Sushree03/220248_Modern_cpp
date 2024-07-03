/*
    More about lambdas:

    1) WHAT ARE THEY EXACTLY

    2) WHAT IS [] USED FOR
        if we want to access objects/variables created in the enclosing function of lambda, 
        we use [] i.e. capture clause (capture things outside the lambda in the enclosing function and used by lambda)

    3)SOME WEIRD THINGS TO KNOW ABOUT LAMBDAS
*/

#include <iostream>
#include <functional>

void add(int32_t n1, int32_t n2) {
    std::cout << n1 + n2 << "\n";
}



int main() {                   //main is the enclosing function for lambda
    int data = 20;
    int value = 200;
    /*
        lambda object is bound to fn variable in the scope of main function (lambda will be destroyed at the end of function)
    */
   auto fn = [data, value] (int32_t n1, int32_t n2) { std::cout << n1 + n2  + data << "\n"; };

   fn(10,20); //overloaded() operator of a class created in the background
}

//lambda is used as an anonymous class in the background
//lambda has its own scope, anything outside lambda is not accessible by lambda function


/*
    capture clause

    int n1 = 10;
    int n2 = 20;
    int n3 = 30;

example 1: use of no captured variables
    auto fn = [](){  std::cout << "hello world";};
    fn();

example 2: use of no captured variables but passed parameters

    auto fn = [](int n1, int n2) {std::cout << n1 + n2; };
    fn(n1,n2);

example 3: use n1 as captured variable, n1 should be copied into the lambda

    auto fn = [n1] (int n2) { std::cout << n1 + n2; };
    fn(n2); //only n2 is passed as n1 is already captured

example 4: use n1 as captured variable. n1 should be refrred into the lambda

    auto fn = [&n1] (int n2) { std::cout << n1 + n2; };
    fn(n2); //only n2 is passed as n1 is already captured by reference

example 5: capture all variables from the surrounding (make them all accessible
in the lambda), (copied everything into the lambda when they are accessed in the body of the lambda)

    auto fn = [=] () { std::cout << n1 + n2 + n3; };
    fn(); //all variables were copied by capture into the lambda

example 6: capture all variables from the surrounding (make them all accessible
in the lambda), (refer everything into the lambda when they are accessed in the body of the lambda)

    auto fn = [&] () { std::cout << n1 + n2 + n3; };
    fn(); //all variables were captured by refernce into the lambda


*/