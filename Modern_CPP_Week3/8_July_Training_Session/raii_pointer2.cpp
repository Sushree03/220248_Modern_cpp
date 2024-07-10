#include <iostream>
#include <list>
#include <memory>

void CreateData(std::shared_ptr<int[]> data) {
    data[0]=10;
    data[1]=20;
}

void CalculateTotal(std::shared_ptr<int[]> data, int size) {
    

    float total {0.0f};

    for(int i = 0; i < size; i++) {
        total+=data[i];
    }

    std::cout << "Total is: " << total << "\n";
}


void PrintFirstElement(std::shared_ptr<int[]> data, int size) {

    std::cout << data[0];
}

int main() {
   

    std::shared_ptr<int[]> arr {new int[2]} ;

    CreateData(arr);
    CalculateTotal(arr, 2);
    PrintFirstElement(arr, 2);
}