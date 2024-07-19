#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "Vehicle.h"
#include <memory>

using VehicleSptr = std::shared_ptr<Vehicle>;

struct Comparator {
    bool operator()(const VehicleSptr& v1, const VehicleSptr& v2) {
        return v1->vehiclePrice() < v2->vehiclePrice();
    }      

    Comparator() = default;

    ~Comparator() = default;
};

#endif // COMPARATOR_H
