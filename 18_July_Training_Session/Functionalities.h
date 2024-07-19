#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <vector>
#include <optional>
#include "Vehicle.h"
#include <queue>
#include <memory>
#include <algorithm>
#include <list>
#include <functional>
#include "Comparator.h"
#include <unordered_set>


using VehicleSPtr = std::shared_ptr<Vehicle>;
using DataContainer = std::vector<VehicleSPtr>;
using Predicate = std::function<bool(const VehicleSPtr)>;
using PriorityQ = std::priority_queue<VehicleSPtr, DataContainer, Comparator>;



/*
    This function creates data for demonstration purposes in a vector using shared pointer
*/
void CreateObjects(DataContainer& data);

/*
    This function uses comparator type(a struct with overloaded() operator) to compare and prioritize 
    VehicleSptr type values in the input data
*/

PriorityQ PrioritizeVehicles(const DataContainer& data);

/*
    Returns the count of vehicle whose type matches with caller's type
*/

std::optional<std::size_t> CountMatchingEngineTypeVehicle(const DataContainer& data, const VehicleEngineType engine_type);

/*
    Return a container of all Vehicle smart pointers that satisfy the input predicate
*/

std::optional<DataContainer> ReturnMatchingVehivles(const DataContainer& data, const Predicate& fn);

/*
    Return true or false to indicate whether all vehicles have price above 90k
*/

bool AreAllVehiclesPriceAbove90k(const DataContainer& data);

/*
    Return the average of CalculateRegistrationCost function called
*/

float AverageRegistraitionCost(const DataContainer& data);

/*
    Return a container of last N vehicles from the input data
*/

std::optional<DataContainer> LastNVehicles(const DataContainer& data, unsigned int N);

/*
    function for applying hash on input value for unordered set
*/

std::size_t hash_logic(const VehicleSPtr& v) {
    return std::hash<VehicleMultimedia>() ( v->vehicleMultimedia_Type() );  //one bracket to make objects, one bracket to call overloadde()
}

/*
    we are creating a new variable "comparison_fn"
*/

//extern is extrenal initialization
extern std::function< bool(const VehicleSptr&, const VehicleSPtr&)> comparison_fn;
//can't use auto coz it requires a rhs value which is not here and the fn is not initialized here.

using UniqueVehicles = std::unordered_set< VehicleSPtr, std::function<std::size_t(const VehicleSPtr& v)>, decltype(comparison_fn) >;

/*
    This function creates and returns an unordered_set of unique
    multimedia type objetcs from my input
*/

std::optional<UniqueVehicles> FindUniqueVehicles(const DataContainer& vehicles);

//multiple initialization - inline


#endif // FUNCTIONALITIES_H
