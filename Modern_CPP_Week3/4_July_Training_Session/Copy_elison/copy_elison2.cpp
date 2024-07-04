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

/*Data Magic(){
    return Data {100};
}

int main() {
    Data d1 = Magic(); //d1 object in the main function is a data type which is initialized in return type of magic function
}
*/

Data Magic(){
    Data obj {100};
    return obj;            //enable move constructor   //avoid copy based logic
}

int main() {
    Data d1 = Data {100};     
}

//initialization