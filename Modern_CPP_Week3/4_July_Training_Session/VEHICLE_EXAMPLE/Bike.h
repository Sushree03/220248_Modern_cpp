#ifndef BIKE_H
#define BIKE_H

#include <iostream>

class Bike
{
private:
    /* data */
    std::string m_id {""};
    float m_price {0.0f};
public:

float InsuranceAmount();

    Bike() = delete;
    Bike(const Bike&) = delete;
    Bike(Bike&&) = delete;
    Bike& operator=(const Bike&) = delete;
    Bike& operator=(Bike&&) = delete;
    ~Bike() = default;

    Bike(std::string id, float price) : m_id {id}, m_price {price} {}

    float price() const { return m_price; }

    std::string id() const { return m_id; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);

};

#endif // BIKE_H
