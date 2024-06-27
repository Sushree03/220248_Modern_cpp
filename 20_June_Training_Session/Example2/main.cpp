#include "Functionalities.h"

int main() {
    std::vector<BankAccount*> accounts;
    CreateObjects(accounts,1);
    CountVISACards(accounts);
    DeallocateMemory(accounts);

}