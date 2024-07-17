#include <memory>
#include "Employee.h"
#include <list>
#include <iostream>
#include <algorithm>

using StackMemoryEmployees = std::list<Employee>;
using RawPOintersHeapEmployees = std::list<Employee *>;
using EmployeePtr = std::shared_ptr<Employee>;
using SmartPointerHeapEmployees = std::list<EmployeePtr>;

void CreateObjects(StackMemoryEmployees &stackemployees)
{
    stackemployees.emplace_back(101, "nimisha", 9000.0f, 22, 1.1f);
    stackemployees.emplace_back(102, "nimi", 5600.0f, 21, 8.0f);
    stackemployees.emplace_back(103, "Prateek", 1230.0f, 23, 43.1f);
}

void CreateObjects(RawPOintersHeapEmployees &rawpointeremployees)
{
    rawpointeremployees.emplace_back(new Employee(101, "nimisha", 9000.0f, 22, 41.1f));
    rawpointeremployees.emplace_back(new Employee(102, "nimi", 5600.0f, 21, 12.1f));
    rawpointeremployees.emplace_back(new Employee(103, "Prateek", 1230.0f, 23, 43.1f));
}

void CreateObjects(SmartPointerHeapEmployees &smartptremployees)
{
    smartptremployees.emplace_back(std::make_shared<Employee>(101, "nimisha", 9000.0f, 22, 11.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(102, "nimi", 5600.0f, 21, 12.1f));
    smartptremployees.emplace_back(std::make_shared<Employee>(103, "Prateek", 1230.0f, 23, 43.1f));
}

int main()
{
    StackMemoryEmployees stackemployees{};
    RawPOintersHeapEmployees rawpointeremployees{};
    SmartPointerHeapEmployees smartptremployees{};

    CreateObjects(stackemployees);
    CreateObjects(rawpointeremployees);
    CreateObjects(smartptremployees);

    auto result1 = std::count_if(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee &e1)
        {
            return e1.experienceYears() > 8.0f;
        });

    std::cout << "count of employees:" << result1 << "\n";

    auto result2 = std::count_if(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        [](const Employee *e1)
        {
            return e1->experienceYears() > 8.0f;
        });

    std::cout << "count of employees  :" << result2 << "\n";

    auto result3 = std::count_if(
        smartptremployees.begin(),
        smartptremployees.end(),
        [](const EmployeePtr &e1)
        {
            return e1->experienceYears() > 8.0f;
        });

    std::cout << "count of employees  :" << result3 << "\n";
}