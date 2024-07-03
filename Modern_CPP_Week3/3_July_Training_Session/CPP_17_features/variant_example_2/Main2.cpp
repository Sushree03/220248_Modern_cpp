/*
     keeps data on the heap
     and use variant for "functional polymorphism"
*/
#include <iostream>
#include <variant>
#include "Employee.h"
#include "BusinessOwner.h"

/*
    A function which either accepts another function as a parameter 
    or returns a function is called "Higher-order function"
*/

using VrType = std::variant<BusinessOwner*, Employee*>;

void Display(const VrType& v) {
    std::visit( [](auto&& val){ std::cout << *val << "\n"; },  v   );
}
void ShowPFAmount ( const VrType& v ) {
    
    bool m_flag {false};
    if( std::holds_alternative<Employee*>(v) ) {  //if the variant v holds the altrenative of employee*
   
        Employee* e = std::get<1>(v);  //fetch the data from employee*
        m_flag = true;
        e->CalculateMonthPf();  //return e
    }
    if (!m_flag) {
        throw std::runtime_error("Not valid for Businessowner type data");
    }
      
}

//common behaviour can be executed using visit
void ShowTaxAmount (const VrType& v) {

     std::visit([](auto&& val){ val->CalculateTaxAmount(); },  v );
}

int main() {
    VrType v;

    v =  new BusinessOwner{"Sushree", 90000.0f};

    Display(v);

    v = new Employee{"Sushree", 8000.0f};

    Display(v);

    try
    {
        
        ShowPFAmount(v);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}