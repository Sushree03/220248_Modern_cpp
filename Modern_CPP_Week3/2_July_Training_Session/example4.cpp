#include <iostream>
#include <thread>
#include <list>
#include <mutex>

using ThreadContainer = std::list<std::thread>;

class BankOperations
{
private:
    int32_t m_amount{1000};
    std::mutex mt;

public:
    void Deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount += 10;
            mt.unlock();
        }
    }

    void Withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            mt.lock();
            m_amount -= 10;
            mt.unlock();
        }
    }

    BankOperations() = default;
    BankOperations(const BankOperations &) = delete;
    BankOperations(BankOperations &&) = delete;
    BankOperations &operator=(const BankOperations &) = delete;
    BankOperations &operator=(BankOperations &&) = delete;
    ~BankOperations() = default;
    BankOperations(int32_t val) : m_amount{val} {}

    int32_t amount() const { return m_amount; }
};

void CreateThreads(ThreadContainer &threads, BankOperations &b1)
{
    threads.emplace_back(&BankOperations::Deposit, &b1);
    threads.emplace_back(&BankOperations::Withdraw, &b1);
}

void JoinThreads(ThreadContainer &threads)
{
    for (std::thread &th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}

void DisplayFinalAmount(BankOperations &b1)
{
    std::cout << "Final answer is: " << b1.amount() << "\n";
}

int main()
{
    BankOperations b1{5000};

    ThreadContainer threads{}; // blank list if threads
    CreateThreads(threads, b1);

    JoinThreads(threads);

    DisplayFinalAmount(b1);
}

/*first 4
alias declaration - std:: is lengthy
bank operation class - deposit, withdraw
Top level functions - create
main function - creating, joining threads
*/
