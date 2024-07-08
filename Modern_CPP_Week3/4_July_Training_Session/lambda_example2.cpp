#include <iostream>
#include <functional>

void Demo(void(*ptr)(int n1, int n2) ) {
    ptr(10,20);
}

int main() {
    auto fn = [](int n1, int n2){std::cout << n1+n2 << "\n";};
    Demo(+fn);
}