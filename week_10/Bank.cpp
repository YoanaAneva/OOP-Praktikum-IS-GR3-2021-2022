#include "Bank.h"

void Bank::copy(const Bank& other){
    this->capacity = other.capacity;

    this->savingsSize = other.savingsSize;
    this->savingsAccs = new SavingsAccount[capacity];
    for(int i = 0; i < savingsSize; i++)
        this->savingsAccs[i] = other.savingsAccs[i];
    
    this->creditSize = other.creditSize;
    this->creditAccs = new CurrentAccount[capacity];
    for(int i = 0; i < creditSize; i++)
        this->creditAccs[i] = other.creditAccs[i];
    
    this->employeeSize = other.employeeSize;
    this->employees = new Employee[capacity];
    for(int i = 0; i < employeeSize; i++)
        this->employees[i] = other.employees[i];
}

void Bank::resize(){
    this->capacity *= 2;
    SavingsAccount* biggerS = new SavingsAccount[capacity];
    CurrentAccount* biggerC = new CurrentAccount[capacity];
    Employee* biggerE = new Employee[capacity];

    for(int i = 0; i < savingsSize; i++)
        biggerS[i] = savingsAccs[i];
    for(int i = 0; i < creditSize; i++)
        biggerC[i] = creditAccs[i];
    for(int i = 0; i < employeeSize; i++)
        biggerE[i] = employees[i];

    this->erase();
    savingsAccs = biggerS;
    creditAccs = biggerC;
    employees = biggerE;
}

void Bank::erase(){
    delete[] savingsAccs;
    delete[] creditAccs;
    delete[] employees;
}

Bank::Bank(){
    this->capacity = 8;
    this->savingsSize = 0;
    this->creditSize = 0;
    this->employeeSize = 0;
    this->savingsAccs = new SavingsAccount[capacity];
    this->creditAccs = new CurrentAccount[capacity];
    this->employees = new Employee[capacity];
}

Bank::Bank(const Bank& other){
    this->copy(other);
}

Bank& Bank::operator=(const Bank& other){
    if(this != &other){
        this->erase();
        this->copy(other);
    }
    return *this;
}

Bank::~Bank(){
    this->erase();
}

void Bank::addSavingsAcc(const SavingsAccount& newAcc){
    if(savingsSize >= capacity)
        resize();

    savingsAccs[savingsSize] = newAcc;
    savingsSize++;
}

void Bank::addCreditAcc(const CurrentAccount& newAcc){
    if(creditSize >= capacity)
        resize();

    creditAccs[creditSize] = newAcc;
    creditSize++;
}

void Bank::addEmployee(const Employee& newEmployee){
    if(employeeSize >= capacity)
        resize();

    employees[employeeSize] = newEmployee;
    employeeSize++;
}


void Bank::makeDeposit(int accNumber, double sum){
    for(int i = 0; i < savingsSize; i++){
        if(savingsAccs[i].getNumber() == accNumber){
            savingsAccs[i].deposit(sum);
            return;
        }
    }
    for(int i = 0; i < creditSize; i++){
        if(creditAccs[i].getNumber() == accNumber){
            creditAccs[i].deposit(sum);
        }
    }
}

void Bank::makeWithdrawal(int accNumber, double sum){
    for(int i = 0; i < savingsSize; i++){
        if(savingsAccs[i].getNumber() == accNumber){
            savingsAccs[i].withdraw(sum);
            return;
        }
    }
    for(int i = 0; i < creditSize; i++){
        if(creditAccs[i].getNumber() == accNumber){
            creditAccs[i].withdraw(sum);
        }
    }
}

void Bank::removeAccount(int accNumber){
    for(int i = 0; i < savingsSize; i++){
        if(savingsAccs[i].getNumber() == accNumber){
            for(int j = i; j < savingsSize - 1; j++){
                savingsAccs[j] = savingsAccs[j + 1];
            }
            return;
        }
    }
    for(int i = 0; i < creditSize; i++){
        if(creditAccs[i].getNumber() == accNumber){
            for(int j = i; j < creditSize - 1; j++){
                creditAccs[j] = creditAccs[j + 1];
            }
            return;
        }
    }
    std::cout << "Could not find an account with this account number!" << std::endl;
}

void Bank::removeEmployee(const char* id){
    for(int i = 0; i < employeeSize; i++){
        if(strcmp(employees[i].getId(), id) == 0){
            for(int j = i; j < employeeSize - 1; j++){
                employees[j] = employees[j + 1];
            }
        }
    }
    this->employeeSize--;
}

void Bank::printAllAccounts(const char* id) const{
    for(int i = 0; i < savingsSize; i++){
        if(strcmp(savingsAccs[i].getOwner().getId(), id) == 0){
            savingsAccs[i].print();
        }
    }
    for(int i = 0; i < creditSize; i++){
        if(strcmp(creditAccs[i].getOwner().getId(), id) == 0){
            creditAccs[i].print();
        }
    }
}

void Bank::printAllEmployeesWithAcc() const{
    for(int i = 0; i < employeeSize; i++){
        for(int j = 0; j < savingsSize; j++){
            if(strcmp(employees[i].getName(), savingsAccs[j].getOwner().getName()) == 0)
                std::cout << employees[i].getName() << " | ";
        }
        for(int j = 0; j < creditSize; j++){
            if(strcmp(employees[i].getName(), creditAccs[j].getOwner().getName()) == 0)
                std::cout << employees[i].getName() << " | ";
        }
    }
    std::cout << std::endl;
}
