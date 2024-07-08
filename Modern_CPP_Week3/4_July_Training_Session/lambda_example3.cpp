#include <iostream>
#include <vector>
#include <functional>

void Magic(int& data) {
    std::cout << data;
}

int main() {
    int n1 = 10;
    std::reference_wrapper<int> ref = n1;

    Magic(n1);

    std::reference_wrapper<int> arr[1] {ref};;

    std::vector<std::reference_wrapper<int>> v1;

    
}