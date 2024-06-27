#include<iostream>

class Vehicle
{
private:
    std::string m_id{""};
    std::string m_modelName{""};
public:
    Vehicle() = delete;
    ~Vehicle() = default;
    /*
        Vehicle constructor that takes one const lvalue 
        reference to a Vehicle as a parameter
    */
   Vehicle(const Vehicle& other) = delete;   //copy constructor is disabled

    Vehicle(std::string id, std::string name)
        : m_id{id}, m_modelName{name} {}
};
int main() {
    Vehicle v1{"101", "Dzire"};

    //Vehicle v2{v1}; //v2[101|DZIRE]]

    int n1 = 10;
    int n2 = 20;  //copy assignment
    int n2 = n1; //copy n1 into n2 after  n2 was already initialized earlier

    //Vehicle v3{v1};   //construction occurs as v3 is constructed for the first time

    //Vehicle v3{}; //default
    //v3 = v1;
}