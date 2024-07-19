#include <iostream>
#include <unordered_set>
#include "Employee.h"

int main(){

    auto hash_fn = [](const Employee& e){ return std::hash<unsigned int>()(e.id());};
    auto eq_fn = [](const Employee &e1, const Employee& e2) {return e1.id() == e2.id();};
    
    std::unordered_set<Employee, decltype(hash_fn), decltype(eq_fn)> s{3, hash_fn, eq_fn};
    
    s.emplace(101, "Sushree", 9000.0f, 22, 5.0f);
    s.emplace(102, "Shruti", 7000.0f, 24, 7.0f);
    s.emplace(103, "Sukanya", 8900.0f, 25, 8.0f);

    
    
    for(const Employee& e : s) {
        std::cout << e << "\n";
    }
    
    }
