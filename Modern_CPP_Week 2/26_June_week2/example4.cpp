/*
    std::reference wrapper<T> :
    This is a wrapper class to "hold"
    reference of type T

*/

#include <iostream>
#include <vector>
#include <functional>

void Magic(int& data) {           //lhs   //data and ref has no memories
    std::cout << data; //get the actual value from the wrapper
}

int main() {
    int n1 = 10;
    std::reference_wrapper<int> ref = n1;  //ref is a reference to n1

    //ref is an alternate name for n1 in main function

    Magic(n1);  // int& data = n1;     //  std::reference_wrapper<int> data = n1;

    std::reference_wrapper<int> arr[1] {ref};           //reference wrapper- address of original thing

    // int& arr[1] {ref};

    //std::vector<int&> v1 {ref};

    std::vector<std::reference_wrapper<int>> v1;

    std::cout << v1[0].get();  //get the value inside the wrapper in 0 position of vector
}
