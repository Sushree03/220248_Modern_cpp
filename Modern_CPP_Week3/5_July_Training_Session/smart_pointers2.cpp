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

/*
    resource 1 : 4 bytes of memory on the heap used by the data object with value 100
*/
void Magic(std::unique_ptr<Data> temp) {

}

int main()
{

    std::unique_ptr<Data> ptr4{ new Data{100} };    //unique style to store ptr of an object

   // std::unique_ptr<Data> ptr5 {ptr4};

   Magic(std::move(ptr4));

   //can I use ptr4 after moving?

   ptr4.reset(new Data{99});

}


/*
    std::unique_ptr<Data> ReturnFirstObject(DataContainer& data) - no
*/

//unique pointer cannot be copied in any way 