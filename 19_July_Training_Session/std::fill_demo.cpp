/*
    If I have memory locations already allocated upto a certain size, I can "fill" all locations
    with "some" value using this algorithm

    for e.g: std::vector<int> data {5}; //size 5 vector

    std::fill(data.begin(), data.end(), 11);

    result: data: {11,11,11,11,11}

    for e.g: std::array<int, 5> arr{}; //array of 5 locations

    std::fill(arr. begin(), arr.end(), 11);

    result: arr: {11,11,11,11,11}
*/




#include<memory>
#include "Employee.h"
#include <vector>
#include<iostream>
#include<algorithm>
 
 
using StackMemoryEmployees=std::vector<Employee>;
using RawPOintersHeapEmployees=std::vector<Employee*>;
using EmployeePtr=std::shared_ptr<Employee>;
using SmartPointerHeapEmployees=std::vector<EmployeePtr>;
 
int main()
{
    StackMemoryEmployees stackemployees{5};
    RawPOintersHeapEmployees rawpointeremployees{5};
    SmartPointerHeapEmployees smartptremployees{5};


    std::fill(
        stackemployees.begin(),
        stackemployees.end(),
        Employee{}
    );

     std::fill(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        new Employee{}
    );

     std::fill(
        smartptremployees.begin(),
        smartptremployees.end(),
        std::make_shared<Employee>()
    );
 
}