#include <iostream>
#include <functional>

using Predicate = std::function<bool(int32_t)>;         //Predicate is alternate name for datatype. std function is a wrapper or function  


/*
    std::function<T> is a wrapper that can be used to represent a callable
    of  a certain signature T
    Since this entire data declaration is lengthy, we can create an alias for it with "using" keyword

    [](int32_t number ) { return number %2 == 0; } //lambda

    I want to put it in a wrapper

    So type T (signature): bool(int32_t)

    So wrapper is: std::function<bool(int32_t)>

    Now create an alias called "predicate"

    using Predicate = std::function<bool(int32_t)>;


*/
void Adaptor(  Predicate fn, int32_t* arr, unsigned int size  ) {

    /*
        for every index "i" in the range of size of arr,
        call fn by passing arr[i] (ith position value in the array)
    */
    for(int32_t i = 0; i < size; i++)
    {
        if( fn( arr[i] ) ) {
            std::cout << arr[i] << "\t";         //print only the even numbers
        }
    }
}

int main() {
    auto fn = [](int32_t number) { return number  %2 == 0;  }   ;
    int32_t arr[3] = {11, 18, 21};
    Adaptor( fn,  arr, 3);

}

/*
    
    11        18       21

    |
    1st iteration

*/