/*

        Magic                                     Heap
                                                  Employee
        ptr[0x100H]---------------------->[   101 | Sushree]



        void Magic() {

            Wrapper wr { new Employee(101, "Sushree", 9000.0f); };


            if(condition) {
                std::cout << wr.get() << "\n";
            }

            else {
               
                throw MyException("Something went wrong!");   //exit from here!
            }    
        } //exit from here after if!

        int main() {
            Magic();
            int n1 = 10;
        }


*/

//They allow to delete the code automatically without manually deallocation
//desturctor gets called, we keep the resources inside the wrapper class
//In raii principle, we aquire a resource while constructing a warpper object, while initializing the owner, put in a wrapper class 
//By writing something in owner while destruction, destructor gets applied automatically

/* Shared pointer class - keeps a count- how many people using the resource, when counter becomes 0 every owner who wants to 
access they wont use, when counter is 0 it will be deleted, the compiler needs to wait till 0 
active owners, counter becomes 0 then it will be delete
*/


/*

#include <iostream>
#include <list>

void CreateData(std::list<int>& data) {
    data.emplace_back(10);
    data.emplace_back(20);
}

void CalculateTotal(std::list<int>& data) {
    if (data.empty()) {
        throw std::invalid_argument("empty data");
    }

    float total {0.0f};

    for(int val : data) {
        total+=val;
    }

    std::cout << "Total is: " << total << "\n";

}

void PrintFirstElement(std::list<int>&data) {
    if (data.empty()) {
        throw std::invalid_argument("empty data");
    }

    std::cout << data.front();
}

int main() {
    std::list<int> data{};
    CreateData(data);
    CalculateTotal(data);
    PrintFirstElement(data);
    //we will exit from the main function
}

//we used list here and function gets auto deleted

*/


#include <iostream>
#include <list>

void CreateData(int* data) {
    data[0]=10;
    data[1]=20;
}

void CalculateTotal(int* data, int size) {
    

    float total {0.0f};

    for(int i = 0; i < size; i++) {
        total+=data[i];
    }

    std::cout << "Total is: " << total << "\n";

}


void PrintFirstElement(int* data, int size) {

    std::cout << data[0];
}

int main() {
    int* arr = new int[2];

    CreateData(arr);
    CalculateTotal(arr, 2);
    PrintFirstElement(arr, 2);
    //we will exit from the main function
    /* we have to use array, raw pointers, raw memory and we can't 
    delete automatically. So we can't use any stl containers, to replace raw pointer 
    //replace raw pointers with smart pointers
    */
}