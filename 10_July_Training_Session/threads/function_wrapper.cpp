/*
    thread : Isolated unit of instructions executing in memory
    -multitasking
    //cannot be copied
*/

#include<iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mt;

class Dummy
{
    
private:
    /* data */
    
public:
    Dummy(/* args */) {}
    ~Dummy() {}

    void DisplayFactorial(unsigned int val) {
        if (val == 1 || val == 0) {
            
            std::cout << 1 << "\n";
        }

        else {
            unsigned int result{1};
            for(unsigned int i = 2; i <= val; i++) {
                result *= 1;
            }
            
            std::cout << result << "\n";
        }
    }

    static void MultiplyBy100(int number) {
        
        std::cout << number * 100 <<"\n";
    }
};

void Square(int number) {
    
    std::cout << number * number<<"\n";
}

auto f1=[](int number) { std::cout << number * number * number;};


/*
    Here is a function, here is a data value compartible with inputs required by the function
    Please apply the function on the data AND
        a) transform it
        b) filter it
        c) reduce it

    Programmer : OKAY !! SURE
*/

#include <functional>

void Adaptor(std::function < bool(int)> fn, int data )  //filtering adaptor
{
    if (fn(data)) {
        std::cout << data << "\n";
    }
} 

void Adaptor(std::function < int(int)> fn, int data )  //mapping adaptor, maps functions
{
    std::cout << fn(data) << "\n";
}




int main() {
    std::vector<std::thread> threads{4};
   

}

//can do things parallely but cannot return function