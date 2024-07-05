#include <iostream>
#include <thread>

void Formula(int& val, float factor, const std::string& name) {
    std::cout << "Absolutely important work";
}

int main() {
    int n1 {10};
    std::thread t1 {&Formula, std::ref(n1), 10.21f, "Sushree"};
}

// threads cannot be passed by refrence, anything sent to thread that get copied, pass by values, std::ref will help to pass by refrence
// whatever sent to thread doesn't go directly, perfrect forwarding rule does that
// undefined reference to pthread_create - missed -lpthready
// error - static assertion failed must be invocable after conversion to rvalues - parameters are wrong
// non static member function - first parameter is object.
// & no & rul, objects no objects 