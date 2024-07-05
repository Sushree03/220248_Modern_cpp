#include <iostream>

void Display(char grade) {
    std::cout << grade << "\n";
}

void Demo(int n1, std::string name) {
    std::cout << n1 << name << "\n";
}

void Temp(float n1, int* ptr, std::string name, char&& grade, const bool& flag) {
    std::cout << n1 << "\t" << *ptr << "\t" << name << "\t" << grade << "\t" << flag;
}

int main() {
   // Display("A"); //const char[1] - "" is not used for char
    Display('A');

   // Demo("abc", 10); - the sequence of parameter should be same as declared
    Demo(10, "abc");  //Demo function where we are passing an non const int as value and non const string as value and returns void

    std::string val {"abc"};
    bool flag {true};
    Temp(10.21f, new int(10), "abc", 'A', flag);  // int*ptr-ptr is a non-const pointer to non-const int
    /*
    - char &&grade - non const r value reference to  a __cpp_unicode_character
    a solid datatype &&- r value reference to a datatype
    - const bool &flag - will accept l and r values but non modifiable (const l value refrence of boolean)
        & - will not take reference
    l value- reference
    r value - initialization
    */
}


//argument is real thing we are passing and int is expected (line 19), tally the declaration and what we are passing