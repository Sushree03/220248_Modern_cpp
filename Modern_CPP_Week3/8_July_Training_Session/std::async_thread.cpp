/*
   a)  execute tasks in asynchronus mode

   b) It is a thread that can also catch a return value so could be used in CPP
   to execute value returning functions in a separate thread as well
*/

#include <iostream>
#include <future> //cpp 11   

int64_t Magic(int32_t number) {
    return number * number;
}

int main() {
    std::future<int64_t> ans = std::async(  &Magic,  10  );   //whatever answer produced i can track or extract it and catch the return value in future

    //get fetches the answer from the async thread.. if thread is still executing,
    //main will get blocked at this line till completion of magic function.
    std::cout << ans.get() << "\n";  
}

//async is a thread but can only capture thereturn value







//WANT TO RUN FUNCTION IN THREAD, use async thread, 