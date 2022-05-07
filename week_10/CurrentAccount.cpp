#include "CurrentAccount.h"

void CurrentAccount::copy(const CurrentAccount& other){
    this->creditLimit = other.creditLimit;
    this->draftTax = other.draftTax;
    this->size = other.size;
    this->capacity = other.capacity;
    this->drafts = new DraftInfo[capacity];
    for(int i = 0; i < this->size; i++){
        this->drafts[i] = other.drafts[i];
    }
}

void CurrentAccount::erase(){
    delete[] this->drafts;
}

void CurrentAccount::resize(){
    this->capacity *= 2;
    DraftInfo* bigger = new DraftInfo[capacity];
    for(int i = 0; i < this->size; i++){
        bigger[i] = drafts[i];
    }

    this->erase();
    this->drafts = bigger;
}

CurrentAccount::CurrentAccount() : BankAccount::BankAccount(), creditLimit(0), draftTax(0), size(0), capacity(8) {
    this->drafts = new DraftInfo[capacity];
}

CurrentAccount::CurrentAccount(const Person& person, double balance, int number, double creditLimit, double draftTax, const DraftInfo* drafts, int size) : BankAccount(person, balance, number),
creditLimit(creditLimit), draftTax(draftTax), size(size){
    this->capacity = this->size + 8;
    this->drafts = new DraftInfo[capacity];
    for(int i = 0; i < this->size; i++)
        this->drafts[i] = drafts[i];
}

CurrentAccount::CurrentAccount(const CurrentAccount& other) : BankAccount(other){
    this->copy(other);
}

CurrentAccount& CurrentAccount::operator=(const CurrentAccount& other){
    if(this != &other){
        this->erase();
        this->copy(other);
        BankAccount::operator=(other);
    }
    return *this;
}

CurrentAccount::~CurrentAccount(){
    this->erase();
}

double CurrentAccount::ownerProfit(){
    return draftTax * size * -1;
}

void CurrentAccount::print() const{
    std::cout << "Current balance: " << getBalance() << " Number: " << getNumber() << " Credit limit: " << creditLimit << " Draft tax: " << draftTax << std::endl; 
}

