#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>

using VrType = std::variant<BusinessOwner, Employee>;

void Display(const VrType& v) {
   
  std::visit( []( auto&& val ) { std::cout << val <<"\n"; }, v ); //print the data inside the variant on the variant v

}

int main() {
    std::variant<BusinessOwner, Employee> vr;

    Employee e1 {"Harshit", 9000.0f};
    BusinessOwner b1 {"Harshit", 89000.0f};

    vr = e1;

    Display(vr);

    vr = b1; //changed vr to take BusinessOwner

    Display(vr);


}

//hold value of 1 of defined type
//no abstraction