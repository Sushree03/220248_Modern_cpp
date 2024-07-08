#include <iostream>
#include <functional>

void add(int32_t n1, int32_t n2){
    std::cout<< n1+n2 << "\n";
}

int main() {
    int data = 20;
    int value = 200;

    auto fn  = [](int32_t n1, int32_t n2){std::cout << n1+n2 << "\n";};
    fn(10,20);
}