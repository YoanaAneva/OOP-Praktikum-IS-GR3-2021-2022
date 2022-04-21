#include "company.h"

void Company::copy(const Company& other){
    if(employees != nullptr)
        this->erase();

    this->size = other.size;
    this->capacity = other.capacity;

    this->employees = new Employee[other.capacity];
    for(int i = 0; i < this->size; i++){
        this->employees[i] = other.employees[i];
    }
}

void Company::erase(){
    delete[] this->employees;
}

void Company::resize(){
    this->capacity *= 2;

    Employee* bigger = new Employee[this->capacity];
    for(int i = 0; i < this->size; i++){
        bigger[i] = this->employees[i];
    }
    this->erase();
    this->employees = bigger;
}

Company::Company(){
    this->size = 0;
    this->capacity = 8;
    this->employees = new Employee[this->capacity];
}

Company::Company(const Company& other){
    this->copy(other);
}

Company& Company::operator=(const Company& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

Company::~Company(){
    this->erase();
}

void Company::addEmployee(const Employee& newEmployee){
    if(this->size >= this->capacity)
        this->resize();
    this->employees[size] = newEmployee;
    this->size++;
}

const Employee& Company::getMostPaid() const{
    Employee mostPaid = this->employees[0];
    int index;
    for(int i = 1; i < this->size; i++){
        if(this->employees[i].getSalary() > mostPaid.getSalary()){
            mostPaid = this->employees[i];
            index = i;
        }
    }
    return employees[index];
}

void Company::saveWorkers(const char* fileName){
    std::ofstream fout(fileName);
    if(!fout.is_open())
        std::cout << "Cannot open file for writing!" << std::endl;
    if(!fout)
        std::cout << "Stream is not in a good condition!" << std::endl;
    
    fout << this->size << '\n';
    for(int i = 0; i < this->size; i++){
        fout << '{' << employees[i].getName() << '|' << employees[i].getAge() << '|' << employees[i].getSalary() << "}\n";
    }
}

void Company::printCompany() const{
    std::cout << size << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << employees[i].getName() << " " << employees[i].getAge() << " " << employees[i].getSalary() << std::endl;
    }
}


void Company::writeInBinary(const char* path){
    std::ofstream outf(path, std::ios::binary);
    if(!outf.is_open())
        std::cout << "Cannot open file for writing!" << std::endl;
    if(!outf)
        std::cout << "Stream is not in a good condition!" << std::endl;

    outf.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for(int i = 0; i < this->size; i++){
        employees[i].writeInBin(outf);
    }
}

Company Company::readFromBinary(const char* path){
    std::ifstream inf(path, std::ios::binary);
    if(!inf.is_open())
        std::cout << "Cannot open file for reading!" << std::endl;
    if(!inf)
        std::cout << "Stream is not in a good condition!" << std::endl;
    
    int size;
    inf.read(reinterpret_cast<char*>(&size), sizeof(size));

    Company result;
    for(int i = 0; i < size; i++){
        Employee newEmployee = Employee::readFromBin(inf);
        result.addEmployee(newEmployee);
    }
    return result;
}

int main(){
    Employee e1("Gosho", 32, 1220);
    Employee e2("Tasho", 25, 9000);
    Employee e3("Ivanka", 33, 8394.34);

    Company company;
    company.addEmployee(e1);
    company.addEmployee(e2);
    company.addEmployee(e3);
    company.printCompany();
    std::cout << "-----------------------------------------" << std::endl << std::endl;

    company.writeInBinary("Company.bin");

    Company test = Company::readFromBinary("Company.bin");
    test.printCompany();
}