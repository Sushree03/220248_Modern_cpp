#include "Functionalities.h"
#include <unordered_set>



std::function< bool(const VehicleSptr&, const VehicleSPtr&)> comparison_fn = [](const VehicleSptr& v1, const VehicleSPtr& v2){
    return v1->vehicleMultimedia_Type() == v2->vehicleMultimedia_Type();
};

void CreateObjects(DataContainer &data)
{
    data.emplace_back(std::make_shared<Vehicle>(VehicleType::COMMERCIAL,
                                                VehicleFuelType::ALTERNATE_FUEL, VehicleStandardType::BS4,
                                                VehicleEngineType::HYBRID, VehicleMultimedia::ANALOG, 9000.0f));

    data.emplace_back(std::make_shared<Vehicle>(VehicleType::PRIVATE,
                                                VehicleFuelType::ICE, VehicleStandardType::BS6,
                                                VehicleEngineType::NA, VehicleMultimedia::ANDROID_SMART, 8000.0f));

    data.emplace_back(std::make_shared<Vehicle>(VehicleType::RENTAL,
                                                VehicleFuelType::OTHER, VehicleStandardType::BS6_2,
                                                VehicleEngineType::REGULAR, VehicleMultimedia::APPLE_ANDROID_SMART, 4500.0f));

    data.emplace_back(std::make_shared<Vehicle>(VehicleType::PRIVATE,
                                                VehicleFuelType::ALTERNATE_FUEL, VehicleStandardType::BS6_2,
                                                VehicleEngineType::HYBRID, VehicleMultimedia::APPLE_SMART, 8000.0f));

    data.emplace_back(std::make_shared<Vehicle>(VehicleType::COMMERCIAL,
                                                VehicleFuelType::ICE, VehicleStandardType::OTHER,
                                                VehicleEngineType::REGULAR, VehicleMultimedia::ANALOG, 6700.0f));
}

PriorityQ PrioritizeVehicles(const DataContainer & data)
{
return PriorityQ();
}

std::optional<std::size_t> CountMatchingEngineTypeVehicle(const DataContainer &data, const VehicleEngineType engine_type)
{
    std::optional<std::size_t> result{std::nullopt}; // result is nullopt assume

    if (data.empty()) // if vehicle empty
    {
        std::cerr << "No data found in input\n";
    }

    else
    {
        result = std::count_if( // do count_if
            data.begin(),
            data.end(),
            [&](const VehicleSPtr &v)
            { return v->vehicleEngine_Type() == engine_type; });
    }

    return result;
}

std::optional<DataContainer> ReturnMatchingVehivles(const DataContainer &data, const Predicate fn)
{
    std::optional<DataContainer> result{std::nullopt};

    if (data.empty()) // if vehicle empty
    {
        std::cerr << "No data found in input\n";
    }

    else
    {
        DataContainer values{};

        std::copy_if(
            data.begin(),
            data.end(),
            std::inserter(values, values.begin()),
            fn);

        if (!values.empty())
        { // while copying prdeicate may not satisfy the result
            result = values;
        }
    }

    return result;

    // if data is having all the null pointers then while creating objects itself
    // applies some condition to remove these values
}

bool AreAllVehiclesPriceAbove90k(const DataContainer &data)
{
    bool flag{false};

    // if you provide empty container we will get false
    if (data.empty())
    {
        std::cerr << "No data found in input\n";
    }

    else
    {
        flag = std::all_of(
            data.begin(),
            data.end(),
            [](const VehicleSPtr &v)
            { return v->vehiclePrice() > 90000.0f; });
    }
    return flag;
}

float AverageRegistraitionCost(const DataContainer &data)
{
    return 0.0f;
}

std::optional<DataContainer> LastNVehicles(const DataContainer &data, unsigned int N)
{
    std::optional<DataContainer> result{std::nullopt};

    if (data.empty())
    {
        std::cerr << "No data found in input\n";
    }

    if(N > data.size()) {
        std::cerr << "N is invalid as it is more than size\n";
    }

    else {
        DataContainer values{};

        std::copy_n(
            data.rbegin(),
            N,
            std::inserter(values, values.begin())
        );

        result = values;
    }

    return result;
}

std::optional<UniqueVehicles> FindUniqueVehicles(const DataContainer &vehicles)
{
    std::optional<UniqueVehicles> result {std::nullopt };

    if( vehicles.empty() ) {
        std::cerr << " No data found in input\n";
    }

    else{
        UniqueVehicles values { vehicles.begin(), vehicles.end(), vehicles.size(), hash_logic, comparison_fn};
        result = values;
    }
    return result;
}
