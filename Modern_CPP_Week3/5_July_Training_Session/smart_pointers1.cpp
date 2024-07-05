#include <iostream>
#include <memory>

class Data
{
private:
    /* data */
    int m_value {};
public:
    Data() = default;
    Data(const Data&) = delete;
    Data(Data&&) = default;
    Data& operator=(const Data&) = delete;
    Data& operator=(Data&&) = delete;
    ~Data() = default;
    explicit Data(int val) : m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

};

int main()
{
    int32_t x{10};
    char Grade{'A'};
    //int *ptr = (int *)malloc(4);
    //char *ptr2 = (char *)malloc(1); // actual 4 byte is stored in heap and address in stack, jump over the address and work with memory

    std::unique_ptr<int> ptr1 { (int*)malloc(4) };
    std::unique_ptr<int> ptr2 { new int() };
    std::unique_ptr<char> ptr3 { (char*)malloc(1) };

    std::unique_ptr<Data> ptr4{ new Data{100} };    //unique style to store ptr of an object

}
/*
stack main function


    0x108H ptr1 0x242117H
    0x104H   grade    'A'
    0X100H     x     10

*/

/*
    void CalculateResult(input value){

        //allocate something on heap
        ptr = heap memory address

        if (value == condition) {

            do something with ptr
            //action to do

            if (condition1){

            take action
            }
        }
        else if (condition2) {
            throw exception
        }

        else {
            do something!
        }

        else {
            delete ptr;
            throw exception
        }
    }

*/


/*
We can manually deallocate but pointers to deallocate are:
    1. Unique pointer
    2. Shared pointer
*/