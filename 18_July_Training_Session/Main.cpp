#include "Functionalities.h"

int main() {

    DataContainer data{};

    CreateObjects(data);

    auto result= [](const VehicleSPtr v) {return v->vehicleEngine_Type() == VehicleEngineType::HYBRID;};

    CountMatching (data, result);
}