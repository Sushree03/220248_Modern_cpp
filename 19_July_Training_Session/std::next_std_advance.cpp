#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


int main(){
    std::vector<int> data{1,2,3};

    auto itr = data.begin(); //random access

    auto ans = itr + 1; //valid
    

    //vectors arrays are random access so can do + - but not with lists

    std::list<int> {1,2,3,4,5,6,7};

    std::list<int> result(3);

    //desired output : result {5,6,7} using copy

    /*
        take iterator to brgin

        1,2,3,4,5,6,7
        ^
        |
        itr

        move its size - 3 positions forward

        1 2 3 4 5 6 7
                ^
                |
                itr

        //objective: want to move iterator on containers which don't support random access 
        without manually writing for loops
    */

   std::list<int> data{1,2,3,4,5,6,7};

   auto itr = data.begin();

   auto new_itr = std::next(itr, data.size() - 3);  

   std::advance(itr, data.size() - 3); //itr will be modified to new position
         //no new variable created


   //next will give a new ptr together and advance will modify
}

/*
    Input Output
    \\\ ////
    Forward
    \\\///
    Bidirectional  - list, set
    Random access  - vector, 
*/