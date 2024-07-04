/*



*/



#include <thread>
#include <list>
#include <iostream>
#include <functional>
#include <mutex>

std::mutex mt;

using ThreadContainer = std::list<std::thread>;
using DataContainer = std::list<int32_t>;

using FnWrapper = std::function<void(int32_t)>;

void MapThreads( ThreadContainer& threads, const DataContainer& data, FnWrapper fn)
{
    
    for( int32_t n : data ) {
        threads.emplace_back( fn, n );  //values given to thread are passed to emplace back
    }  

}

void JoinThread( ThreadContainer& threads ) {
    for(std::thread& th: threads) {
        if (th.joinable()) {
            th.join();
        }
    }
}

int main() {
    ThreadContainer threads{};
    DataContainer data {10,20,30,40};

    auto f1 = [](int32_t number) { 
        mt.lock();
        std::cout << number * number << "\n";
        mt.unlock();
    };

    MapThreads(threads, data, f1);

    JoinThread(threads);
}

/*
- alias as input
- map threads
- 
*/