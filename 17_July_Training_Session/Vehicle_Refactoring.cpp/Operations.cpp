#include "Operations.h"

DataContainer Operations::m_data {};
THreadContainer Operations::m_threads {};
std::mutex Operations::mt {};

void Operations::CreateCarsAndBikes()
{
    m_data.emplace_back(  new Car("c101", 9000.0f, 4) );
    m_data.emplace_back(  new Car("b101", 8000.0f, 4) );
    m_data.emplace_back(  new Bike("b103", 5000.0f) );
    m_data.emplace_back(  new Car("c104", 2000.0f, 4) );
    m_data.emplace_back(  new Bike("b105", 3000.0f) );
}

void Operations::FindAverageCost()
{
    if (m_data.empty()) {
        mt.lock();
        std::cerr << "Empty data container\n";
        mt.unlock();
    }
    float total {0.0f};

    for(const VrType v : m_data) {
        std::visit( [&] (auto&& val) { total += val->price();}, v ); //for every variant in my datacontainer i'll visitm
    }

    if(!m_data.empty()) {
        mt.lock();
        std::cout << "Average cost is: " << total/m_data.size() << "\n";
        mt.unlock();
    }
}

std::optional<VrType> Operations::ReturnMatchingInstance(std::string id)
{
    if(m_data.empty()) {
        std::cerr << "Empty data container\n";
    }

    std::optional<VrType> result{std::nullopt};

    bool m_id_found {false};
    for(const VrType v : m_data) {
        std::visit(
            [&] (auto&& val) { if(val->id() == id) { result = v; m_id_found = true; } }, v);

            if (m_id_found) {
                break;   //after each variant visited did we find the id? true break from the loop
            }
    }
    return result;
}

void Operations::Deallocate()
{
    if (m_data.empty()) {
        std::cerr << "Empty data container\n";
    }

    for(const VrType v : m_data) {
        std::visit([](auto&& val) { delete val; }, v);
    }
}

void Operations::DisplayInsuranceAmount()
{
    if (m_data.empty()) {
        mt.lock();
        std::cerr << "empty data container\n";
        mt.unlock();
    }
    for(const VrType v : m_data){
        std::visit([](auto&& val) { mt.lock(); std::cout << val->InsuranceAmount()<<"\n"; mt.unlock(); }, v );
    }
}

std::optional<unsigned int> Operations::FindSeatCountForGivenId(std::string id)
{
    if (m_data.empty()) {
        std::cerr << "Empty data container\n";
    }

    std::optional<unsigned int> result {std::nullopt};
    bool matchFound{false};

    for(const VrType v : m_data) {
        if(std::holds_alternative<Car*>(v)) {
            CarPtr temp = std::get<0>(v);

            if(temp->id() == id) {
                matchFound = true;
                result = temp->seatCount();
            }
        }
    }

    if(!matchFound && !m_data.empty()){
        std::cerr <<"id not found\n";
    }
    return result;
}

void Operations::MapThreads(const DataContainer& vehicles)
{
    m_threads.emplace_back( FindAverageCost, std::ref(vehicles));
    m_threads.emplace_back( DisplayInsuranceAmount, std::ref(vehicles));
}
void JoinThreads()
{
    for(std::thread& th : m_threads) {
        if (th.joinable()) {
            th.join();
        }
    }
}

//create an object, emplace back,whatever material required to make 1 new object in my container I will put that in emplace back
