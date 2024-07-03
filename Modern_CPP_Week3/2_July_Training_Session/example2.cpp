//Threads and Mutex


#include <iostream>
#include <thread>
#include <mutex>

class MathOperations
{
private:
    std::mutex mt{};
    int32_t m_value{0};
public:
    MathOperations(const MathOperations&) = delete;
    MathOperations(MathOperations&&) = delete;
    MathOperations& operator=(const MathOperations&) = delete;
    MathOperations& operator=(MathOperations&&) = delete;
    MathOperations() = default;
    MathOperations(int val) : m_value {val} {}
    ~MathOperations() = default;

    void square() {
        mt.lock();
        std::cout << "ID : of the thread square: " << std::this_thread::get_id() <<"\n";
        std::cout << "Square of " << m_value << " is: " << m_value *m_value << "\n";
        mt.unlock();
    }

    int32_t addition(int other) {
        mt.lock();
         std::cout << "ID : of the thread addition: " << std::this_thread::get_id() <<"\n";
        return m_value + other;
        mt.unlock();
        };

    //paren paren operator
    int64_t operator()(){
        mt.lock();
        std::cout << "ID : of the thread operator: " << std::this_thread::get_id() <<"\n";
        mt.unlock();
        return m_value * m_value * m_value;
    }
};

//an object that behaves like a function (can be invoked like a function)
//is called a "functor" object


int main() {
    MathOperations m1 {100};
    
    std::thread t1 { &MathOperations::square, &m1  };
    

    std::thread t2 {std::ref(m1) }; //thread created by a functor object //using an object of a class to call a function

    //you cannot capture return values from a function when executing
    //them via std::thread

    std:: thread t3 { &MathOperations::addition, &m1, 100 };

    t1.join();
    t2.join();
    t3.join();

    //Note: t2 & t3 outputswill get discarded. No way to capture it.
}

//ctrl forward slash(/) - uncomment

//error : static assertion failed: std::thread arguments must be invocable a fter conversion tp rvalues - 
//passing wrong arguments but no. of arguments is correct

//Note: all parameters passed to std::thread constructor are taken as "call by value"

//here as we enabled the copy constructor mutex is getting copied which shouldn't happen so we put reference wrapper so that mutex won't get copied

//copy and move are disabled
//parameterized constructor - mutex has no parameters , doesn't take any parameters
// square function - take object value and print square
//release mutex
//addition function- value + other
//operator overloaded- print id, mutex unlock
//std::this_thread::get_id - std is a namespace , we find get_id, 
//class MathOperations- class function is an object
//t2 thread will target object, when m1 passed we can call m1 
//t3 function takes addition and one val
//binary addition - object's data + (things in the function)

//threads will always try to copy the parameter, treat first parameter as callable function// threads cannot be capture return value
//global variables are bad