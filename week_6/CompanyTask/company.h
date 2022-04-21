#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"
#include <fstream>

class Company{
private:
    Employee* employees;
    int size;
    int capacity;

    void copy(const Company& other);
    void erase();
    void resize();
public:
    Company();
    Company(const Company& other);
    Company& operator=(const Company& other);
    ~Company();

    void addEmployee(const Employee& newEmployee);
    const Employee& getMostPaid() const;
    void saveWorkers(const char* fileName);
    void printCompany() const;

    void writeInBinary(const char* path);
    static Company readFromBinary(const char* path);
};


#endif