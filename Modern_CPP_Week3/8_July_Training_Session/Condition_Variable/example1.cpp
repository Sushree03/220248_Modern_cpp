/*
   Use case 1)  calculate square for 10 numbers

    10 std::thread object to complete square of 10 number of each

    Use case 2)

    5 operations are to be performed. all are independent 
    (order of execution is not important).Execute all 5 parallely

        a) one std::thread for each operation
        b) one async thread for each operation
        c) mix of std::thread  are std::async

        (all functions reaturning a value need to be executed via std::async,
        others via std::thread)

    Use case 3)

        [producer-consumer problem] - one party produces data and the other consumes

        f1(producer)----> data will be generated

        f2(consumer) -----> processing data only after data is required


        example : sensor detects collision and deployment of airbags!

        program to call emergency ()
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>


int32_t value {0};
std::condition_variable cv;
std:: mutex mt;
 bool m_inputReceived {false};


void Producer() {
    while(!m_inputReceived) {
        std::cin >> value;
        if (value > 5) {
            m_inputReceived = true;
        }
    }

    //data is produced when
      //  a) user input has been accepted
      //  b) input must be above 5
    
    //send a signal !

    std::lock_guard<std::mutex> lk(mt);   //when signalling is happening no other threads are active
    cv.notify_one(); //send a signal
}

void Consumer() {
    /*
        scenario 1: consumer starts. consumer checks for condition
        if condition is false, I cannot exit the function. cannot use lockguard coz it will delete at the end of scope
        lockguard is a wrapper class that will delete at the end of the scope 
        unique lock releases at the end of scope or else if the condition is comnpletely false(in middle of function)
    */
    //waiting for signal!
    std::unique_lock<std::mutex> ul {mt};  //

    cv.wait(  ul  , []() { return m_inputReceived; } );
    //this value cannot be computed before producer gives a signal!
    std::cout << "Value squared is: " << value * value << "\n";
}


int main() {  //main function is a thread!

    //will launch producer
    std::thread t1{&Producer};  //first line to be executed, controlling with handle t1, producer to be seprately from main

    //will launch consumer
    std::thread t2{&Consumer}; //make consumer a separate function, t2 is handle of thread

    std::cout << "Main continuous chilling! asks for 15 crore to fire employees advice!\n";  //prints 2 statements
    std::cout << "Main can do anything\n";

    t1.join();  //after they are done with 
    t2.join();

    std::cout << "That's all. Goodbye!";  //Main is completely independent, you can do a 3rd activity in main
}


//daemon : background task
/*
     3 perspectives

     Main function
     ------------
     a) I created t1 thread (producer)
     b)I created t2 thread (consumer)
     c) first cout
     d) second cout 
     e) t1 join
     f) t2 join
     g) good bye cout
     h) terminate app

     Producer percpective:

     a) Executed a loop. In the loop till m_input_received is true:
        a1) took a input
        a2) checked if input is greater > 5, make flag true

    b) acquire a mutex so that nobody disturbs
    c) send a signal via notify_one()

    Consumer Perspective :

    a) I am waiting for signal
*/