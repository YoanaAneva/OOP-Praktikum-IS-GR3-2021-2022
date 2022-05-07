#include "BankAccount.h"

BankAccount::BankAccount(const Person& _owner, double _balance, int _number) : owner(_owner), balance(_balance), number(_number) {}

BankAccount::BankAccount(){
    this->balance = 0;
    this->number = 0;
}

void BankAccount::withdraw(double amount) {
    balance -= amount;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::setOwner(const Person& owner) {
    this->owner = owner;
}

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

const Person& BankAccount::getOwner() const {
    return this->owner;
}

double BankAccount::getBalance() const {
    return this->balance;
}

int BankAccount::getNumber() const{
    return this->number;
}