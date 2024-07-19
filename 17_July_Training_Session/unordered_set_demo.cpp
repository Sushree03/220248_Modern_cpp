#include <iostream>
#include <unordered_set>

/*
    1,1,1,4,5,6,7,8,9
*/

int main() {
    std::string data{};
    std::cin >> data;

    std::unordered_set<char> s{ data.begin(), data.end(), data.size() };

    for(char c : s) { std::cout << c << "\t"; }

    std::cout << "\n";
}

/*
       fn(h) ---> hv1,
0
1
2
3
4
5
6

*/

//anything that goes in a set cannot be duplicate