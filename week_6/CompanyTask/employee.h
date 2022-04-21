#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstddef>

class Employee{
private:
    char *name;
    int age;
    float salary;

    void copy(const Employee&);
    void erase();

public:
    Employee(const char*, int, float);
    Employee();
    Employee(const Employee&);
    ~Employee();
    Employee& operator=(const Employee&);

    void setName(const char* name);
    void setAge(int age);
    void setSalary(float salary);

    const char* getName() const;
    int getAge() const;
    float getSalary() const;
    void writeInBin(std::ofstream& outf);
    static Employee readFromBin(std::ifstream& inf);
};


#endif