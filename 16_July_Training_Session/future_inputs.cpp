/*
    async has 2 use cases
    1) You can use std::asyncg to fetch data from e thread if the 
    function returns a vlaue

2)Providing inputs to execute threads,asynchironously,
out of order in "future"


future promise - make promise to provide inputs  to compiler in future
*/

#include <iostream>
#include <future>

int* AllocateSpace(){
    return (int*) new int(); //return the address of the new allocation
}


int* factorial(std::future<int>& number) {
    /*
        1. primary task : calculate factorial (dependent on input)
        2. make allocation on the heap where the answer will be stored
    */

   int* ans = AllocateSpace();     //completes the subtask

   /*
    .....actual answer calculation starts here!
   */
  //after the subtask is complete, input value is MANDATORY NOW!
  int number_value = number.get();  //factorial thtread will be blocked until user fulfils the promise

  int result = 1;

  for(int i = 2; i<=number_value; i++) {
    result *= i;
  }

  *ans = result; //copy the result on the heap in ans address location

  return ans;
}

int main() {
    
    std::promise<int> pr; //first,I make a promise to provide an "integer"

    std::future<int> ft = pr.get_future();

    std::future<int*> res = std::async( &factorial,  std::ref(ft) );

    int data{0};
    std::cin >> data;

    //fulfil promise. send a signal to future attached to this promise
    pr.set_value(data);

    std::cout << *res.get() << "\n";
}