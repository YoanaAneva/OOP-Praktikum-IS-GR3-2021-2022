#include "Person.h"

#include <iostream>
#include <cstring>

enum Position{
    dummy,
    hygienist,
    secretary,
    consultant,
    supplier,
    manager
};

class Employee : public Person{
private:
    double salary;
    int yearHiring;
    Position position;
    char* positionInfo;

    void copy(const Employee& other);
    void erase();
public:
    Employee();
    Employee(const Person& person, double salary, int yearHiring, const char* position);
    Employee(const char* name, const char* id, double salary, int yearHiring, Position position, const char* positionInfo);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);

    ~Employee();

    void setSalary(double salary);
    void setYearHiring(int yearHiring);
    void setPosition(Position position);
    void setPositionInfo(const char* positionInfo);

    double getSalary() const;
    int getYearHiring() const;
    Position getPosition() const;
    const char* getPositionInfo() const;
};