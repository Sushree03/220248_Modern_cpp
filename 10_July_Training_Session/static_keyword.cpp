/*
    1) static storage variable
    2) static 
    3) 
*/





#include<iostream>
 
 
void Increment (){
    static int n1 {1};
    std::cout<<n1++<<"\n";
}

class EmployeeData {  //static data member not initialized in the constructor
    private:
        static long long m_company_landline_number;
        std::string m_employee_name;
    public:
        EmployeeData(std::string name) : m_employee_name{name} {}

        static long long companyLandlineNumber() { return EmployeeData::m_company_landline_number; }  //only static member are allowed to create static member of class
};

long long EmployeeData::m_company_landline_number = 26541638; //declaration to be done in cpp file
 
int main(){
    Increment();  //created n1 in static data segment, initial 1. print
    Increment();

    EmployeeData e1 {"Sushree"};

    std::cout << EmployeeData::companyLandlineNumber() << "\n";
}

//static members are called via name of class and not via name of object