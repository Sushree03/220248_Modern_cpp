#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <mutex> //ordinary binary semaphore

std::mutex mt;

using Operatoion = std::function<void(int number)>;

void Adaptor(Operatoion fn, const std::vector<int>& data) {
    for(int val : data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        fn(val); // apply function on a single item. Repeat this in a loop
    }
}


void Square(int number) {

    mt.lock(); //ask for the permission to access cout
    std::cout << number * number << "\n";  //critical section
    mt.unlock();  //release the lock when done
}


int main() {
    auto cube_fn = [](int number) {
        mt.lock(); 
        std::cout << number * number * number << "\n"; 
        mt.unlock();
    };
    //to execute adaptor function by using Square function and vector of values
    //as it parameters
    std::thread t1{ &Adaptor, &Square, std::vector<int>{1,2,3,4,5} };
    std::thread t2{ &Adaptor, cube_fn, std::vector<int>{1,2,3,4,5} };

    t1.join();  //main cannot proceed beyond line 52 unless t1 is terminated/completed
    t2.join();  //main cannot proceed beyond line 53 unless t2 is terminated/completed

}


// starvation- if one or more of your parties cannot use the resourse is called starvation
//Semaphores need to ask for the thread

//Binary semaphore or mutex can be either 0 or 1
//Counting Semaphore

/*t1
  ------>   request access -----> if denied 
                           -----> if allowed  [send to buffer]
  t2
  ------>   no activity   ------>t2 mt.lock
*/
 //we can have only one mutex
 //slower than a program not using mutex , the more you use mutex it will become as slower and do not apply mutex for long durations
 //Mutex prevents the race condition
 //since you are running things paraallely there is no guarantee in which sequence we will get the output