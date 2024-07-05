/*
    1) CreateCarsAndOperationss
    2) FindAverageCostOfVehicles : print the average price of all vehicles in our databases
    3) ReturnMatchingInstANCE : RETURN THE FIRST VEHICLE WHOSE ID matches with the id parameter received
    4) Deallocate : release heap allocation if any!
    5) DisplayInsuranceAmount : show output of InsuranceAmount function for each instance
    6) FindSeatCountForGivenId : fetches vehicle based on ID and returns corresponding seat_count

*/

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <variant>
#include <optional>
#include <list>
#include <iostream>
#include "Bike.h"
#include "Car.h"
#include <thread>
#include <mutex>

using VrType = std::variant<Car*, Bike*>;
using DataContainer = std::list<VrType>;
using THreadContainer = std::list<std::thread>;

class Operations
{
private:
    static std::mutex mt;
    static DataContainer m_data;
    static THreadContainer m_threads;
    
public:
    Operations() = delete;
    Operations(const Operations&) = delete;
    Operations(Operations&&) = delete;
    Operations& operator=(const Operations&) = delete;
    Operations& operator=(Operations&&) = delete;
    ~Operations() = default;

   static void CreateCarsAndBikes();

    /*
        FindAverageCost : Use visit function to do this. Both Car and Bike have a m_price attribute.
        WE can use their getter function to calculate total.
    */

   static void FindAverageCost();
   /*
        ReturnMatchingInstance : Variant whose ID matches with the Id passed
   */

    static std::optional<VrType> ReturnMatchingInstance(std::string id);

    static void Deallocate();

    static void DisplayInsuranceAmount();

    /*
        scenario 1: id found, matches with a Car, seat count returned
        scenario  2: id found, matches with a Bike ----> nullopt
        scenario  3: id not found, nullopt

    */

    static std::optional<unsigned int> FindSeatCountForGivenId(std::string id);

    /*
        MapThreads : Attach a thread to a functionality
    */
   static void MapThreads();
    /*
        JoinThreads : Blocking  main for 
    */
   static void JoinThreads();


};

#endif // OPERATIONS_H


//it'll store in binary, executable size will increase