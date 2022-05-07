#include "Employee.h"

void Employee::copy(const Employee& other){
    this->salary = other.salary;
    this->yearHiring = other.yearHiring;
    this->position = other.position;
    this->positionInfo = new char[strlen(other.positionInfo) + 1];
    strcpy(this->positionInfo, other.positionInfo);
}
void Employee::erase(){
    delete[] this->positionInfo;
}

Employee::Employee() : Person(), salary(0), yearHiring(0), position(dummy){
    this->positionInfo = new char[1];
    this->positionInfo[0] = '\0';
}

Employee::Employee(const Person& person, double salary, int yearHiring, const char* position) : Person(person), salary(salary), yearHiring(yearHiring){
    this->positionInfo = new char[strlen(position) + 1];
    strcpy(this->positionInfo, position);
}

Employee::Employee(const char* name, const char* id, double salary, int yearHiring, Position position, const char* positionInfo) : Person(name, id), salary(salary), yearHiring(yearHiring), position(position){
    this->positionInfo = new char[strlen(positionInfo) + 1];
    strcpy(this->positionInfo, positionInfo);
}

Employee::Employee(const Employee& other) : Person(other){
    this->copy(other);
}

Employee& Employee::operator=(const Employee& other){
    if(this != &other){
        this->erase();
        this->copy(other);
        Person::operator=(other);
    }
    return *this;
}

Employee::~Employee(){
    this->erase();
}

void Employee::setSalary(double salary){
    this->salary = salary;
}
void Employee::setYearHiring(int yearHiring){
    this->yearHiring = yearHiring;
}
void Employee::setPosition(Position position){
    this->position = position;
}
void Employee::setPositionInfo(const char* positionInfo){
    this->positionInfo = new char[strlen(positionInfo) + 1];
    strcpy(this->positionInfo, positionInfo);
}

double Employee::getSalary() const{ return this->salary;}
int Employee::getYearHiring() const{ return this->yearHiring;}
Position Employee::getPosition() const{ return this->position;}
const char* Employee::getPositionInfo() const{ return this->positionInfo;}