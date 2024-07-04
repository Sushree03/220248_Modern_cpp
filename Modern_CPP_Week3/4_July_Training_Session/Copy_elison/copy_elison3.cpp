#include <iostream>

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


Data Creator() {
    return Data {100};   //rvalue
}

Data Absorber(Data d1) {
    std::cout << d1 << "\n";
    return d1;
}

int main() {
    Data obj = Absorber(  Data{100}  );

    std::cout << "Object is in main: " << obj << "\n";  //compiler directly takes to main and prints
}

