#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    /* data */
    unsigned int m_id;
    std::string m_name;
    float m_salary;
    unsigned int m_age;
    float m_experience_years;
public:
    Employee() = delete;
    ~Employee() = default;
    Employee(const Employee&) = default;
    Employee(Employee&&) = delete;
    Employee& operator=(const Employee&) = delete;
    Employee& operator=(Employee&&) = delete;

    //check applicable tax

    void CheckApplicableTax()
    {
        if (m_salary > 0 && m_salary <= 500000.0f) {
            std::cout << "Tax amount will be: " <<0.1f * m_salary;
        }
        else if(m_salary > 500000.0f && m_salary <= 1500000.0f) {
            std::cout << "Tax amount will be: " << 0.2f * m_salary;
        }
        else{
            std::cout << "Tax amount will be: " << 0.3f * m_salary;
        }
    }

    //parametrized constructor
    Employee(unsigned int id, std::string name, float salary, unsigned int age, float years)
            : m_id{id}, m_name{name}, m_salary{salary}, m_experience_years{years}, m_age{age} {}
 
    unsigned int id() const { return m_id; }

    
    float salary() const { return m_salary; }

    unsigned int age() const { return m_age; }

    float experienceYears() const { return m_experience_years; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_name: " << rhs.m_name
           << " m_salary: " << rhs.m_salary
           << " m_age: " << rhs.m_age
           << " m_experience_years: " << rhs.m_experience_years;
        return os;
    }



};









#endif // EMPLOYEE_H
