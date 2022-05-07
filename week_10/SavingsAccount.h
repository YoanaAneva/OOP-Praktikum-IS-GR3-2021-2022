#ifndef SAVINGS_H_INCLUDED
#define SAVINGS_H_INCLUDED

#include "Person.h"
#include "BankAccount.h"
#include <iostream>

class SavingsAccount : public BankAccount{
private:
    double interest;
    double monthlyFee;

    void copy(const SavingsAccount& other);
public:
    SavingsAccount();
    SavingsAccount(const Person& person, double balance, int number, double interest, double monthlyFee);
    SavingsAccount(const SavingsAccount& other);
    SavingsAccount& operator=(const SavingsAccount& other);

    double ownerProfit();
    void print() const;
};

#endif