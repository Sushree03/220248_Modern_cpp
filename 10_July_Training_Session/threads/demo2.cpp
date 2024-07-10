/*
    thread : Isolated unit of instructions executing in memory
    -multitasking
    //cannot be copied
*/

#include<iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <future>

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
            std::lock_guard<std::mutex> lk(mt);
            return 1;
        }

        else {
            unsigned int result{1};
            for(unsigned int i = 2; i <= val; i++) {
                result *= 1;
            }
            std::lock_guard<std::mutex> lk(mt);
            return result;
        }
    }

    static int MultiplyBy100(int number) {
       return number * 100;
    }
};

int Square(int number) {
    std::lock_guard<std::mutex> lk(mt);
    std::cout << number * number<<"\n";
}

auto f1=[](int number) {return number * number * number;};

int main() {

        int n1{10}; 

        std::future<int> res1 = std::async( &Square, 10);

        std::future<int> res2 = std::async(f1, std::ref(n1));

        std::future<int> res3 = std::async(&Dummy::DisplayFactorial, &d1, std::ref(n1));

        std::future<int> res3 = std::async(&Dummy::MultiplyBy100, std::ref(n1));
    

    std::

}

//can do things parallely but cannot return function