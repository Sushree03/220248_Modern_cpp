#include <iostream>
#include <vector>
#include <variant>

//variants: are categorical types which allows "either or" principle of
//typing

int main() {
    int32_t n1 {100};
    std::string s1 {"Sushree"};
    std::variant<int32_t, std::string> vr;

    vr =n1 ; //n1 is assigned to the variant.

    std::cout << "Variant is working\n";

    vr = s1;

    vr = 41.45f;

}

//variant - abstract data type

/*
    vr = n1
       int32_t    std::string         index_variable
    [    10      |   xxxxx          |   0         ]  //24 byte  //only one slot becomes active

    vr = s1
       int32_t    std::string         index_variable
    [    10      |   {Sushree}      |   1         ]  //24 byte   the slot which is active, we can read data from that slot

*/

//bad variant access - exception , if we try to access invalid location in variant