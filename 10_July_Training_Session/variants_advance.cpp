#include <iostream>
#include <variant>


using vrType =  std::variant<int, std::string>;

//possible on all types for the variant
void DisplayValue(vrType& v){
     std::visit( [](auto&& val) { std::cout << val << "\n"; }, v);  //if we open the variant we will find something called val
             //auto&&- forward references

}

void ConvertToUpperCase(vrType& v){
    if(std::holds_alternative<std::string>(v)) {   //if v variants holds alternative type 
        //access the string from its slot
        std::string temp = std::get<1>(v);
        for(char & c : temp) {
            std::cout << char( (int)c - 32);
        }
    }
   

}

int main(){  
}


