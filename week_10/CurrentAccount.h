#ifndef CURRENT_ACCOUNT_H_INCLUDED
#define CURRENT_ACCOUNT_H_INCLUDED

#include "Person.h"
#include "BankAccount.h"

struct DraftInfo{
    double draftAmount;
    char date[12];

    DraftInfo() : draftAmount(0), date(""){}

    DraftInfo(double draftAmount_, const char* date_){
        draftAmount = draftAmount_;
        strcpy(date, date_);
    }
};

class CurrentAccount : public BankAccount{
private:
    double creditLimit;
    double draftTax;
    DraftInfo *drafts;
    int size;
    int capacity;

    void copy(const CurrentAccount& other);
    void resize();
    void erase();
public:
    CurrentAccount();
    CurrentAccount(const Person& person, double balance, int number, double creditLimit, double draftTax, const DraftInfo* drafts, int size);
    CurrentAccount(const CurrentAccount& other);

    CurrentAccount& operator=(const CurrentAccount& other);

    ~CurrentAccount();

    double ownerProfit();
    void print() const;
};

#endif