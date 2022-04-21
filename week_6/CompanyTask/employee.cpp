#include "employee.h"

void Employee::copy(const Employee& other){
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->age = other.age;
    this->salary = other.salary;
}

void Employee::erase(){
    delete[] this->name;
}

Employee::Employee(){
    setName("a");
    setAge(18);
    setSalary(500);
}

Employee::Employee(const char* name, int age, float salary){
    setName(name);
    setAge(age);
    setSalary(salary);
}

Employee::Employee(const Employee& other){
    this->copy(other);
}

Employee::~Employee(){
    this->erase();
}

Employee& Employee::operator=(const Employee& other){
    if(this != &other){
        this->erase();
        this->copy(other);
    }
    return *this;
}

void Employee::setName(const char* name){
    try{
        for (int i = 0; i < strlen(name); i++){
            if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z')){
                throw "Invalid name!";
            }
        }
    }
    catch(const char* msg){
            std::cout << msg << std::endl;
        }
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Employee::setAge(int age){
    try{
        if(age <= 0){
            throw "Invalid age!";
        }
    }
    catch(const char* msg){
        std::cout << msg << std::endl;
    }
    this->age = age;
}
void Employee::setSalary(float salary){
    try{
        if(salary < 0){
            throw "Invalid salary!";
        }
    }
    catch(const char* msg){
        std::cout << msg << std::endl;
    }
    this->salary = salary;
}

const char* Employee::getName() const{
    return this->name;
}
int Employee::getAge() const{
    return this->age;;
}
float Employee::getSalary() const{
    return this->salary;
}

void Employee::writeInBin(std::ofstream& outf){
    if(!outf.is_open())
        std::cout << "Cannot open file for writing!" << std::endl;
    if(!outf)
        std::cout << "Stream is not in a good condition!" << std::endl;
    
    size_t name_len = strlen(this->name) + 1;
    outf.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
    outf.write(name, name_len);
    outf.write(reinterpret_cast<const char*>(&age), sizeof(age));
    outf.write(reinterpret_cast<const char*>(&salary), sizeof(salary));
}

Employee Employee::readFromBin(std::ifstream& inf){
    if(!inf.is_open())
        std::cout << "Cannot open file for reading!" << std::endl;
    if(!inf)
        std::cout << "Stream is not in a good condition!" << std::endl;

    size_t name_len;
    inf.read(reinterpret_cast<char*>(&name_len), sizeof(name_len));
    char *name = new char[name_len];
    inf.read(name, name_len);

    int age;
    inf.read(reinterpret_cast<char*>(&age), sizeof(age));
    float salary;
    inf.read(reinterpret_cast<char*>(&salary), sizeof(salary));

    Employee employee;
    employee.name = name;
    employee.age = age;
    employee.salary = salary;

    return employee;
}
