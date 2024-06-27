#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include "DebitCard.h"
#include "BankAccountType.h"

class BankAccount
{
private:
    long m_accountNumber{0};
    std::string m_accountHolderName{""};
    float m_accountBalance{0};
    BankAccountType m_accountType{BankAccountType::SAVINGS};
    DebitCard* m_attached_card; //pointer;
public:
    BankAccount(long number, std::string name, float balance, BankAccountType accountType, DebitCard* card );
    
    ~BankAccount();

    long accountNumber() const { return m_accountNumber; }

    DebitCard* attachedCard() const { return m_attached_card; }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);

};

#endif // BANKACCOUNT_H