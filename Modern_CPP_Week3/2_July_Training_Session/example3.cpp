/*
    amount = 1000;

   100  withdraw operations (10rs each)
   100 deposit operations (10rs each)

   after 200 transactions completed, what is the expected final amount
*/

#include <iostream>
#include <thread>
#include <mutex>


int32_t m_amount {1000};
std::mutex mt;

void Deposit() {
    for(int i = 0; i < 100; i++) {
        std::this_thread::sleep_for( std::chrono::milliseconds(5) );
        mt.lock();
        m_amount += 10;
        mt.unlock();
    }

}

void Withdraw() {
    for(int i = 0; i < 100; i++) {
        std::this_thread::sleep_for( std::chrono::milliseconds(5) );
        mt.lock();
        m_amount -= 10;
        mt.unlock();
    }
}

int main() {


    std::thread t1 { &Withdraw };
    std::thread t2 { &Deposit }; 

    t1.join();
    t2.join();

    std::cout << "Final amount is: " << m_amount << "\n";
}

// for((  i = 0; i < 50; i++  ));  do time ./app; done


//race condition - writing data is a problem reading is not