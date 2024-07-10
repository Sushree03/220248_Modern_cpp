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
            std::lock_guard<std::mutex> lk(mt);
            std::cout << 1 << "\n";
        }

        else {
            unsigned int result{1};
            for(unsigned int i = 2; i <= val; i++) {
                result *= 1;
            }
            std::lock_guard<std::mutex> lk(mt);
            std::cout << result << "\n";
        }
    }

    static void MultiplyBy100(int number) {
        std::lock_guard<std::mutex> lk(mt);
        std::cout << number * 100 <<"\n";
    }
};

void Square(int number) {
    std::lock_guard<std::mutex> lk(mt);
    std::cout << number * number<<"\n";
}

auto f1=[](int number) {std::lock_guard<std::mutex> lk(mt); std::cout << number * number * number;};

void MapThreads(std::vector<std::thread>& threads){
    threads[0] = std::thread(&Square, 10);  //regular
    threads[1] = std::thread(f1, 10); //not using &f1 coz we need the function not the address  static
    threads[2] = std::thread(Dummy::MultiplyBy100,10); //non static
    Dummy d1{};
    threads[3] = std::thread(&Dummy::DisplayFactorial, &d1, 10);
}

void JoinThreads(std::vector<std::thread>& threads){
    for(std::thread& th : threads) {   //& is used as thread cannot be copied
        if(th. joinable()) {
            th.join();
        }
    }

}

int main() {
    std::vector<std::thread> threads{4};
    MapThreads(threads);
    JoinThreads(threads);
    

}

//can do things parallely but cannot return function