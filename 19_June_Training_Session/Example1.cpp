#include<iostream>
#include<vector>

enum class Rating {
    _4_STAR,
    _3_STAR,
    _2_STAR,
    _1_STAR,
    _NO_RATING
};
class Car
{
private:
    unsigned int m_id {0};
    float m_price {0.0f};
    Rating m_safetyRating {Rating::_NO_RATING};
public:
    Car(unsigned int id, float price)
    : m_id{id}, m_price{price} {

    }

    Car(unsigned int id, float price, Rating rating)
    : Car(id,price) {
        m_safetyRating = rating;
    }
    /*
        Constructor delegation //avoid us to write id and price again and again
    */

    Car() = delete;
    Car(const Car&) = default;
    Car& operator=(const Car&) = delete;
    Car& operator=(Car&&) = delete;
    Car(Car&&) = delete;
    ~Car() = default;
};

int main()
{
    Car c1(101, 10000.0f, Rating::_4_STAR);
    Car c2(102, 10000.0f, Rating::_3_STAR); 

    //To remove error: option 1) Enable copy constructor
    //option 2: Moving Cars (not applicable in this context)

    std::vector<Car> cars {c1,c2};
    cars.emplace_back(101, 10000.0f, Rating::_4_STAR);
    cars.emplace_back(102, 10000.0f, Rating::_3_STAR);

    //cars.size()    //return value:size_t // unsigned long value

    std::cout << "Number of elements in the vector currently: " << cars.size()<<"\n";


    










   // int32_t n1 = 10; //32 bits/4 bytes memory for integer
   //int16_t n2 = 20; //16 bit/2 bytes memory for integer
}