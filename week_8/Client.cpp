#include "Client.h"

void Client::copy(const Client& other){
    setName(other.name);
    setAge(other.age);
    setWeight(other.weight);
}

Client::Client() : age(0), weight(0){
    this->name = new char[1];
    this->name[0] = '\0';
}

Client::Client(const char* name, int age, float weight){
    try{
        setName(name);
        setAge(age);
        setWeight(weight);
    }
    catch(const char* msg){
        delete[] this->name;
        std::cout << msg << std::endl;
    }
}

Client::Client(const Client& other){
    this->copy(other);
}

Client& Client::operator=(const Client& other){
    if(this != &other){
        delete[] this->name;
        this->copy(other);
    }
    return *this;
}

Client::~Client(){
    delete[] this->name;
}

void Client::setName(const char* name){
    if(strlen(name) == 0 || name == nullptr)
        throw "Invalid name!";

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Client::setAge(int age){
    if(age < 5)
        throw "Invalid age!";
    this->age = age;
}
void Client::setWeight(float weight){
    if(weight < 10)
        throw "Invalid weight!";
    this->weight = weight;
}

const char* Client::getName() const{ return this->name;}
int Client::getAge() const{ return this->age;}
float Client::getWeight() const{ return this->weight;}

void Client::writeInBin(std::ofstream& outf){
    if(!outf.is_open())
        std::cout << "Cannot open file for writing!" << std::endl;
    if(!outf)
        std::cout << "Stream is not in a good condition!" << std::endl;

    size_t name_len = strlen(this->name) + 1;
    outf.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
    outf.write(this->name, name_len);
    outf.write(reinterpret_cast<const char*>(&this->age), sizeof(this->age));
    outf.write(reinterpret_cast<const char*>(&this->weight), sizeof(this->weight));
}

Client Client::readFromBin(std::ifstream& inf){
    if(!inf.is_open())
        std::cout << "Cannot open file for reading!" << std::endl;
    if(!inf)
        std::cout << "Stream is not in a good condition!" << std::endl;
    
    size_t name_len;
    inf.read(reinterpret_cast<char*>(&name_len), sizeof(name_len));
    char* name = new char[name_len];
    inf.read(name, name_len);

    int age;
    inf.read(reinterpret_cast<char*>(&age), sizeof(age));

    float weight;
    inf.read(reinterpret_cast<char*>(&weight), sizeof(weight));

    Client client(name, age, weight);

    return client;
}

void Client::print() const{
    std::cout << this->name << " " << this->age << " " << this->weight << "kg" << std::endl;
}