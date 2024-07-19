#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "VehicleType.h"
#include "VehicleStandardType.h"
#include "VehicleMultimediaType.h"
#include "VehicleFuelType.h"
#include "VehicleEngineType.h"

class Vehicle
{
private:
    /* data */
    VehicleType m_Vehicle_Type {VehicleType::COMMERCIAL};
    VehicleFuelType m_Vehicle_Fuel_Type {VehicleFuelType::ALTERNATE_FUEL};
    VehicleStandardType m_Vehicle_Standard_Type {VehicleStandardType::BS4};
    VehicleEngineType m_Vehicle_Engine_Type {VehicleEngineType::HYBRID};
    VehicleMultimedia m_Vehicle_Multimedia_Type {VehicleMultimedia::ANALOG};
    float m_Vehicle_price{0.0f};

public:

    float CalculateRegistrationCost() const;

    Vehicle() = default;
    Vehicle(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle& operator=(Vehicle&&) = delete;
    ~Vehicle() = default;

    Vehicle(VehicleType Type, VehicleFuelType FuelType, VehicleStandardType StandadrdType, VehicleEngineType EngineType, VehicleMultimedia MultimediaType, float price );

    float vehiclePrice() const { return m_Vehicle_price; }

    VehicleType vehicleType() const { return m_Vehicle_Type; }

    VehicleFuelType vehicleFuel_Type() const { return m_Vehicle_Fuel_Type; }

    VehicleStandardType vehicleStandard_Type() const { return m_Vehicle_Standard_Type; }

    VehicleEngineType vehicleEngine_Type() const { return m_Vehicle_Engine_Type; }

    VehicleMultimedia vehicleMultimedia_Type() const { return m_Vehicle_Multimedia_Type; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
        os << "m_Vehicle_Type: " << (int)rhs.m_Vehicle_Type
           << " m_Vehicle_Fuel_Type: " << (int)rhs.m_Vehicle_Fuel_Type
           << " m_Vehicle_Standard_Type: " << (int)rhs.m_Vehicle_Standard_Type
           << " m_Vehicle_Engine_Type: " << (int)rhs.m_Vehicle_Engine_Type
           << " m_Vehicle_Multimedia_Type: " << (int)rhs.m_Vehicle_Multimedia_Type
           << " m_Vehicle_price: " << rhs.m_Vehicle_price;
        return os;
    }

    
};

#endif // VEHICLE_H
