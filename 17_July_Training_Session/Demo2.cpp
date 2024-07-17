#include<memory>
#include "Employee.h"
#include<list>
#include<iostream>
#include<algorithm>
 
using StackMemoryEmployees=std::list<Employee>;
using RawPOintersHeapEmployees=std::list<Employee*>;
using EmployeePtr=std::shared_ptr<Employee>;
using SmartPointerHeapEmployees=std::list<EmployeePtr>;
 
void CreateObjects(StackMemoryEmployees& stackemployees)
{
    stackemployees.emplace_back(101,"nimisha",9000.0f,22,1.1f);
    stackemployees.emplace_back(102,"nimi",5600.0f,21,8.0f);
    stackemployees.emplace_back(103,"Prateek",1230.0f,23,43.1f);
 
}
 
void CreateObjects(RawPOintersHeapEmployees& rawpointeremployees)
{
    rawpointeremployees.emplace_back(new Employee(101,"nimisha",9000.0f,22,41.1f));
    rawpointeremployees.emplace_back(new Employee(102,"nimi",5600.0f,21,12.1f));
    rawpointeremployees.emplace_back(new Employee(103,"Prateek",1230.0f,23,43.1f));
}
 
void CreateObjects(SmartPointerHeapEmployees& smartptremployees)
{
    smartptremployees.emplace_back(std::make_shared<Employee>(101,"nimisha",9000.0f,22,11.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(102,"nimi",5600.0f,21,12.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(103,"Prateek",1230.0f,23,43.1f));
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

    std::vector<Employee> result{};

    //create a inserter pointer, if space is not allocated, do it automatically
    std::copy_if(
        stackemployees.begin(),
        stackemployees.end(),
        std::inserter( result, result.begin() ),
        [](const Employee& e) { return e.age() > 27.0f; }
    );

    //example 2
    std::vector<Employee> n_result_container{};

    std::copy_n(
       stackemployees.begin(),
       2,
       std::inserter( n_result_container, n_result_container.begin() )
    );

    //example 3 : copy all items from rawpointeremployees into a destination
    std::vector<Employee*> result_pointers{ rawpointeremployees.size() };

    std::copy(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        result_pointers.begin()
    );

    /*
    
    rawpointeremployees
    [  0x997H  |  0x123H   |    0x699H   ]
    
    result_pointers
    [   0x997H    0x123H        0x699H      ]
    
    <-------------24 bytes---------------->
    */
}

/*
    22 21 23
    e1 e2 e3
*/

//Three ways to copy
//copy everything, copy conditionally, copy_n

/*

all_of
any_of
none_of
min_element 
max_element
3 members of copy families (limited number of copy, copy everything, regular copy)
count_if
*/
