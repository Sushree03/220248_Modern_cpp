/*
    Employee
        -int id, string name, string designation, catrgorical Department, 
        float salary

    
*/

#include<iostream>
#include "Department.h"

class Employee
{
private:
    unsigned int m_id{0}; //default value
    std::string m_name{""}; //default value for m_name
    std::string m_designation{"executive"}; //default value for m_department
    Department m_dept {Department::IT};
    float m_salary {0.0f};
public:
    Employee() = default; //enable the default constructor
    ~Employee() = default; //destructor is enabled
    Employee(const Employee& other) = delete; //disable copy constructor   //my rule is employee cannot be copied
    Employee(Employee&& other) = delete; //move constructor
    Employee& operator=(Employee&& other) = delete;

    Employee(unsigned int id, std::string name, std::string des, Department dept, 
    float salary) : m_id {id}, m_name {name}, m_salary {salary}, m_designation {des}, m_dept {dept} ////members,{}, parameter  // this is member list initialization 
    {

    }
 
};

int main()
{
    Employee*ptr = nullptr; //declaration of a pointer ptr of type Employee

    ptr = new Employee();

    ptr = new Employee(101, "Sushree", "Professional", Department::IT, 9000.0f); //parameterized constructor in heap

    int n1{10};
    int* ptr {nullptr};
    int arr[3] {1,2,3};
    Employee e1 {};
    Employee e2 {102, "SER", "technical head", Department::HR, 3456.0f}; //stack objects
    //std::list<int> data {1,2,3,4,5}
}