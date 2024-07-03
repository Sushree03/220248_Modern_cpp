/*
    Terminologies

    1) CPU : Set of hardware responsible for executing tasks in a computing
    system

    2) System : Any computing device

    3) Processor : Hardware chip (made of sillicon) designed 
    for executing instructions given by the user of the computer

    e.g. intel i7-1265U

    4) Socket : Point on the motherboard where processor is connected

    5) Core : Every processor is divided internally into units called as 'Cores'

    Each core can execute instructions from one "process" at any given time.

    6) process : A running task on the system


*/

#include <iostream>
#include <vector>
#include <functional>
#include <thread>

using Operation = std::function<void(int number)>;

void Adaptor(Operation fn, const std::vector<int>& data) {
    for(int val : data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fn(val); // apply function on a single item. Repeat this in a loop
    }
}


void Square(int number) {
    std::cout << number * number << "\n";
}


int main() {
    auto cube_fn = [](int number) {std::cout << number * number * number << "\n"; };
    //to execute adaptor function by using Square function and vector of values
    //as it parameters
    std::thread t1{ &Adaptor, &Square, std::vector<int>{1,2,3,4,5} };
    std::thread t2{ &Adaptor, cube_fn, std::vector<int>{1,2,3,4,5} };

    t1.join();  //main cannot proceed beyond line 52 unless t1 is terminated/completed
    t2.join();  //main cannot proceed beyond line 53 unless t2 is terminated/completed

   // Adaptor(Square, std::vector<int> {1,2,3,4,5});
   // Adaptor(cube_fn, std::vector<int> {1,2,3,4,5});
}


// Signle thread synchronous execution  // race condition