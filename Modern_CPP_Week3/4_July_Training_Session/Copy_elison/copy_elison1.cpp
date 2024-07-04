/*
    elision : not do something, not perform something,
                ignore/avoid something

    Guaranteed Copy Elision : cpp17
*/


#include <iostream>
class Data
{
private:
    /* data */
    int m_value {};
public:
    Data() = default;
    Data(const Data&) = delete;
    Data(Data&&) = delete;
    Data& operator=(const Data&) = delete;
    Data& operator=(Data&&) = delete;
    ~Data() = default;
    explicit Data(int val) : m_value{val} {}

    friend std::ostream &operator<<(std::ostream &os, const Data &rhs) {
        os << "m_value: " << rhs.m_value;
        return os;
    }

    
};

void Magic(Data d1) {
    std::cout << d1 << "\n";

}

int main() {
    Data d1 {11};
    Magic(d1); //this will not work because copy is disabled
    Magic(99); //this will not work because conversion is disabled (explicit)
    

    Magic(  Data {100} );   //100 gets attached to d1 parameter i.e Data d1 { Data{100} } - Data d1{100}, 
                       //d1 gets initialized here  , initialization with parameterised constructor
                      //an rvalue of type Data is used to initialize an object of type Data.
                     //compiler simply refactors/modifies rhe code as Data d1{100}

}

//Magic{10} - integer as an input and gives object of data as output //implicit conversion (Parametrised constructor can be used here)
//explicit constructors cannot be used for type conversion
//copy is disabled so can't copy, we then enable the copy constructor