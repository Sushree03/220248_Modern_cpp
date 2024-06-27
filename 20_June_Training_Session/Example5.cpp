#include<iostream>
 
// void Magic(int& data){//lvalue
//     // .......
// }
 
// void Magic(const int& data){//Accepts both values
//     // .......
// }
 
//void Magic(int&& data){//rvalue
    // .......
// }
 
// void Magic(int data){//Accepts both values
//     // .......
// }

//void Magic(const.int&& data) {       r value accepted but can't be changed

//}
 
int main(){
    Magic(10);
    int n1 = 10;
    Magic(n1);
}