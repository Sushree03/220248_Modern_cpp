#ifndef EMPLOYEE_H
#define EMPLOYEE_H
 
#include<iostream>
 
 
class Employee
{
private:
    /* data */
    unsigned int m_id{0};
    std::string m_name{""};
    float m_salary{0.0f};
    unsigned int m_age{0};
    float m_experience{0.0f};
public:
    Employee(unsigned int id, std::string name, float salary, unsigned int age, float exeprience): m_id{id}, m_name{name}, m_salary{salary}, m_age{age}, m_experience{exeprience}{}
 
    Employee ()= default;
    ~Employee() = default;
 
    Employee(const Employee&) = default;
    Employee& operator = (const Employee&) = default;
 
    Employee(Employee&&) = default;
    Employee operator = (Employee&&) = delete;
 
    unsigned int id() const { return m_id; }
 
    std::string name() const { return m_name; }
 
    float salary() const { return m_salary; }
 
    unsigned int age() const { return m_age; }
 
    float experience() const { return m_experience; }
 
    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_name: " << rhs.m_name
           << " m_salary: " << rhs.m_salary
           << " m_age: " << rhs.m_age
           << " m_experience: " << rhs.m_experience;
        return os;
    }
 
 
    //check applicable tax
 
    void checkApplicableTax(){
        if(m_salary>0 && m_salary <=500000.0f){
            std::cout<<"tax amount will be"<<0.1f * m_salary;
        }
        else if(m_salary > 500000.0f  &&  m_salary <= 15000000.0f){
            std::cout<<"tax amount will be"<<0.2f * m_salary;
        }else{
            std::cout<<"tax amount will be "<<0.3f * m_salary;
        }
    }
};
 
#endif // EMPLOYEE_H