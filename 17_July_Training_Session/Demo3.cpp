#include<memory>
#include "Employee.h"
#include<list>
#include<iostream>
#include<algorithm>
#include <numeric>
 
using StackMemoryEmployees=std::list<Employee>;
using RawPOintersHeapEmployees=std::list<Employee*>;
using EmployeePtr=std::shared_ptr<Employee>;
using SmartPointerHeapEmployees=std::list<EmployeePtr>;
 
void CreateObjects(StackMemoryEmployees& stackemployees)
{
    stackemployees.emplace_back(101,"Sushree",9000.0f,22,1.1f);
    stackemployees.emplace_back(102,"Shruti",5600.0f,21,8.0f);
    stackemployees.emplace_back(103,"Sukanya",1230.0f,23,43.1f);
 
}
 
void CreateObjects(RawPOintersHeapEmployees& rawpointeremployees)
{
    rawpointeremployees.emplace_back(new Employee(101,"Sushree",9000.0f,22,41.1f));
    rawpointeremployees.emplace_back(new Employee(102,"Shruti",5600.0f,21,12.1f));
    rawpointeremployees.emplace_back(new Employee(103,"Sukanya",1230.0f,23,43.1f));
}
 
void CreateObjects(SmartPointerHeapEmployees& smartptremployees)
{
    smartptremployees.emplace_back(std::make_shared<Employee>(101,"Sushree",9000.0f,22,11.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(102,"Shruti",5600.0f,21,12.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(103,"Sukanya",1230.0f,23,43.1f));
}
 
int main()
{
    StackMemoryEmployees stackemployees{};
    RawPOintersHeapEmployees rawpointeremployees{};
    SmartPointerHeapEmployees smartptremployees{};
 
    CreateObjects(stackemployees);
    CreateObjects(rawpointeremployees);
    CreateObjects(smartptremployees);
    ////////////////////////////////////////////

    float total_salary = std::accumulate(    //fold operation
        stackemployees.begin(),
        stackemployees.end(),
        0.0f,
        []( float ans_upto_now , const Employee& e )  //previous step answer + one new employee in container
        {
            return ans_upto_now + e.salary();
        }
    );
    std::cout << "Total salary is: " << total_salary << "\n";
    
}

//copy operation in stack including vector - requires copy and move constructor both