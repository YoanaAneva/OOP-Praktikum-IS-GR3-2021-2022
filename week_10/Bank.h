#include "Employee.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"

class Bank{
private:
    SavingsAccount* savingsAccs;
    CurrentAccount* creditAccs;
    Employee* employees;

    int savingsSize;
    int creditSize;
    int employeeSize;

    int capacity;

    void copy(const Bank& other);
    void resize();
    void erase();
public:
    Bank();
    Bank(const Bank& other);
    Bank& operator=(const Bank& other);

    ~Bank();

    void addSavingsAcc(const SavingsAccount& newAcc);
    void addCreditAcc(const CurrentAccount& newAcc);
    void addEmployee(const Employee& newEmployee);

    void removeEmployee(const char* id);
    void removeAccount(int accNumber);

    void makeDeposit(int accNumber, double sum);
    void makeWithdrawal(int accNumber, double sum);

    void printAllAccounts(const char* id) const;
    void printAllEmployeesWithAcc() const;
};

