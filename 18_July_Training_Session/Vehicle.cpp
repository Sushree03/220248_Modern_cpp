#include "Vehicle.h"

Vehicle::Vehicle(VehicleType Type, VehicleFuelType FuelType, VehicleStandardType StandadrdType, VehicleEngineType EngineType, VehicleMultimedia MultimediaType, float price)
    : m_Vehicle_Type{Type}, m_Vehicle_Fuel_Type{FuelType}, m_Vehicle_Standard_Type{StandadrdType}, m_Vehicle_Engine_Type{EngineType}, m_Vehicle_Multimedia_Type{MultimediaType}, m_Vehicle_price{price} 
    {
        if(m_Vehicle_Fuel_Type == VehicleFuelType::ALTERNATE_FUEL) {
            m_Vehicle_Engine_Type = VehicleEngineType::NA;
        }
    }

float Vehicle::CalculateRegistrationCost()const
{
    float ans {0.0f};

    if (m_Vehicle_Fuel_Type == VehicleFuelType::ALTERNATE_FUEL || m_Vehicle_Fuel_Type == VehicleFuelType::ICE)
    {
        ans = 0.1f * m_Vehicle_price;
    }
    else
    {
        ans = 0.2f * m_Vehicle_price;
    }
    return ans;
}