#pragma once
#include "person.h"


class BankAccount{
private:
    Person owner;
    double balance;
    int number;

public:
    BankAccount();
    BankAccount(const Person& owner, double balance, int number);

    void withdraw(double amount);
    void deposit(double amount);

    void setOwner(const Person& owner);
    void setBalance(double balance);

    const Person& getOwner() const;
    double getBalance() const;
    int getNumber() const;
};