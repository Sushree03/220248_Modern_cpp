/*
    Reverse a string with no library functions
    with the help of a stack
*/

#include <stack>
#include <iostream>
#include <optional>


std::optional<std::string> StackReverseString(std::string& data){
        std::stack<char> reversed_characters{};

        for(const char c : data) {
            reversed_characters.push(c);
        }

        std::string result {};

        while(!reversed_characters.empty()) {
            result = result  + reversed_characters.top();
            reversed_characters.pop();
        }

        if (result.empty()) {
            return std::nullopt;
        }

        return result;
    }

    void TakeInput(std::string& data) {
        std::cin >> data;
    }

    int main() {
        std::abort
        if(auto result=StackReverseString(data);result.has_value)
        {

        }
        
    }

