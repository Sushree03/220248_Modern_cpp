/*
    problems with regular enums
*/


#include <iostream>

enum  Gear {
    FIRST,
    SECOND
};

enum  Rank{
    FIRST,
    SECOND
};

void Magic(int n1){
    std::cout << n1* 100;
}

int main()
{
    FIRST; //problem 1: Not mandatory to prefix enum name(confusion)

    Gear g1 = Gear::FIRST;
    Rank r1 = Rank:: FIRST;

    if(g1 == r1) {   //problem 2: enums of 2 different categories get compared on basis of integer values
        std::cout << "OOOH NO!!!\n";
    }
    Magic(r1); //problem 3: auto conversion of enum to integer without consent!!

}