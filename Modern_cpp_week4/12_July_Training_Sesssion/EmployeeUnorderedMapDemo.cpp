#include <unordered_map>
#include <iostream>
#include "Employee.h"
#include <functional>

using Container = std::unordered_map<unsigned int, Employee>;
using Predicate = std::function<bool(const std::pair<const unsigned int, Employee> &)>;

// c++ 17
void DisplayMapUsingStructureBinding(const Container &data)
{
    for (auto &[k, v] : data)
    { // syntactic sugar
        std::cout << "Key is: " << k << " and value is: " << v << "\n";
    }
}

void CreateEmployeeObjects(Container &data)
{
    data.emplace(                                                // there is no front and back in hashing as we are not feeding data manually
        std::piecewise_construct,                                // construct considering by 2 pieces
        std::forward_as_tuple(101),                              // first piece is a tuple pf 1 key
        std::forward_as_tuple(101, "Sushree", 9000.0f, 22, 5.0f) // second piece is a tuple of 5 items
    );

    data.emplace(                                              // there is no front and back in hashing as we are not feeding data manually
        std::piecewise_construct,                              // construct considering by 2 pieces
        std::forward_as_tuple(102),                            // first piece is a tuple pf 1 key
        std::forward_as_tuple(102, "Rohan", 5000.0f, 32, 6.0f) // second piece is a tuple of 5 items
    );

    data.emplace(                                              // there is no front and back in hashing as we are not feeding data manually
        std::piecewise_construct,                              // construct considering by 2 pieces
        std::forward_as_tuple(101),                            // first piece is a tuple pf 1 key
        std::forward_as_tuple(101, "Ajay", 12000.0f, 42, 8.0f) // second piece is a tuple of 5 items
    );
}

void FindAverageSalary(const Container &data)
{
    /*
        for every pair key and value

        go to value section and use the getter to fetch salary

        Add salary to total

        At the end of for loop, divide total by size of hash table
    */

    float total{0.0f};
    for (auto &[k, v] : data)
    {
        total += v.salary();
    }

    std::cout << total / data.size() << "\n";
}

void FindEmployeeById(const Container &data, unsigned int key)
{
    auto itr = data.find(key);

    // if key is not found, we get iterator to end position()
    if (itr == data.end())
    {
        std::cerr << "Employee with given key: " << key << " is not found\n";
    }

    else
    {
        std::cout << itr->second << "\n";
    }
}

void FilterEmployeeByPredicate(const Container &data, Predicate fn)
{
    /*
        do not apply filter on key, condition is based on object's value
    */

    // Note : while extracting pairs from an unordered map,
    // the key part shall always be constant
    for (const std::pair<const unsigned int, Employee> &p : data)
    {
        if (fn(p))
        {
            std::cout << p.second << "\n";
            ////
        }
    }
}

int main()
{
    Container data;
    CreateEmployeeObjects(data);
    DisplayMapUsingStructureBinding(data);

    FilterEmployeeByPredicate(
        data,
        [](const std::pair<const unsigned int, Employee> &p)
        {
            return p.second.age() > 25;
        }
    );
}
