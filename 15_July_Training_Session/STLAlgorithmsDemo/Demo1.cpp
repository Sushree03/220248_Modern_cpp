//all of the conditions


#include <memory>
#include <list>
#include <algorithm>
#include "../Employee.h"



/*

    ModernCPP
        -
        -
        -----> 15JulySession
            ------>STLAlgorithmDemo
                -   --->Demo1.cpp****
            ------->Employee.h
*/

using StackMemoryEmployees = std::list<Employee>;  //creating alias

using RawPointerHeapEmployees = std::list<Employee*>;

using Employeeptr = std::shared_ptr<Employee>;

using SmartPointerHeapEmployees = std::list<Employeeptr>;


void CreateObjects(StackMemoryEmployees& stackEmployees){
    stackEmployees.emplace_back(101, "Sushree", 9000.0f, 22, 2.0f);
    stackEmployees.emplace_back(102, "Sukanya", 4500.0f, 24, 5.0f);
    stackEmployees.emplace_back(103, "Shruti", 7800.0f, 25, 8.0f);
}

void CreateObjects(RawPointerHeapEmployees& rawpointeremployees) {
    rawpointeremployees.emplace_back(new Employee (101, "Sushree", 9000.0f, 22, 2.0f));
    rawpointeremployees.emplace_back(new Employee (102, "Sukanya", 4500.0f, 24, 5.0f));
    rawpointeremployees.emplace_back(new Employee (103, "Shruti", 7800.0f, 25, 8.0f));
}

void CreateObjects(SmartPointerHeapEmployees& smartptremployees) {
    smartptremployees.emplace_back(std::make_shared<Employee>(101, "Sushree", 9000.0f, 22, 2.0f));
    smartptremployees.emplace_back(std::make_shared<Employee>(102, "Sukanya", 4500.0f, 24, 5.0f));
    smartptremployees.emplace_back(std::make_shared<Employee>(103, "Shruti", 7800.0f, 25, 8.0f));
}

int main(){
    StackMemoryEmployees stackemployees{};
    RawPointerHeapEmployees rawpointeremployees{};
    SmartPointerHeapEmployees smartptremployees{};

    CreateObjects(stackemployees);
    CreateObjects(rawpointeremployees);
    CreateObjects(smartptremployees);


    //check if all employees have age above 25

    //check all items from begin to end of my container

    bool result1 = std::all_of(
        stackemployees.begin(),
        stackemployees.end(),
        [](const Employee& e) {return e.age() > 25; }
    );

    bool result2 = std::all_of(
        rawpointeremployees.begin(),
        rawpointeremployees.end(),
        [](const Employee* e) {return e->age() > 25; }
    );

    bool result3 = std::all_of(                //result3 variable will be equal to result of all_of
        smartptremployees.begin(),
        smartptremployees.end(),
        [](const Employeeptr& e) {return e->age() > 25; }
    );

    std::cout << result1 << "\n";
    std::cout << result2 << "\n";
    std::cout << result3 << "\n";


}