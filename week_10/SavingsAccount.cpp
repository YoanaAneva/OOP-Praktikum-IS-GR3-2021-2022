#include "SavingsAccount.h"

void SavingsAccount::copy(const SavingsAccount& other){
    this->interest = other.interest;
    this->monthlyFee = other.monthlyFee;
}

SavingsAccount::SavingsAccount() : BankAccount(), interest(0), monthlyFee(0){}
SavingsAccount::SavingsAccount(const Person& person, double balance, int number, double interest, double monthlyFee) : BankAccount(person, balance, number){
    this->interest = interest;
    this->monthlyFee = monthlyFee;
}
SavingsAccount::SavingsAccount(const SavingsAccount& other):BankAccount(other){
    this->copy(other);
}
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other){
    if(this != &other){
        BankAccount::operator=(other);
        this->copy(other);
    }
    return *this;
}

double SavingsAccount::ownerProfit(){
    return interest * getBalance() - monthlyFee;
}

void SavingsAccount::print() const{
    std::cout << "Current balance: " << getBalance() << " Number: " << getNumber() << " Interest: " << interest << " Monthly fee: " << monthlyFee << std::endl;
}
