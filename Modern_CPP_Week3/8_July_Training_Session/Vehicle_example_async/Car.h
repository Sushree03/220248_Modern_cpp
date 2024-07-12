#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
private:
    /* data */
    std::string m_id {""};
    float m_price {0.0f};
    unsigned int SeatCount{0};
public:
    Car(std::string id,float price,unsigned int count):m_id{id},m_price{price},SeatCount{count}{}
 
    Car()=default;
    ~Car()=default;
    Car(const Car&)=delete;
    Car(Car&&)=delete;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
 
    float InsuranceAmount();   //user defined member function
 
    std::string id() const { return m_id; }
 
    float price() const { return m_price; }

    unsigned int seatCount() const { return SeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
        
};

#endif // CAR_H
