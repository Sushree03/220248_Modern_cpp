#include "Car.h"
 
    std::ostream &operator<<(std::ostream &os, const Car &rhs) {
        os << "m_id: " << rhs.m_id
           << " m_price: " << rhs.m_price
           << " SeatCount: " << rhs.SeatCount;
        return os;
    }
 
    float Car::InsuranceAmount()
    {
        return 0.2f*m_price;
    }
 