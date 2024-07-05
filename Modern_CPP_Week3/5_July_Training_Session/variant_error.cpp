#include <iostream>
#include <variant>
#include <list>

int main() {
    std::variant<int, std::string>  vr  {10};
    vr = {std::list<int>{1,2,3}};


}

//vr - variable 
//on left to vr it is data type of template class
//variant is a collection of possible type of objects
//variant can be either an integer or string at one time.
