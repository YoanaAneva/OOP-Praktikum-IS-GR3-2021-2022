#include "Fitness.h"

void Fitness::copy(const Fitness& other){
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->size = other.size;
    this->capacity = other.capacity;
    for(int i = 0; i < this->size; i++){
        this->clients[i] = other.clients[i];
    }
}

void Fitness::erase(){
    delete[] this->name;
    delete[] this->clients;
}

void Fitness::resize(){
    this->capacity *= 2;
    Client* bigger = new Client[this->capacity];
    for(int i = 0; i < this->size; i++){
        bigger[i] = this->clients[i];
    }

    delete[] this->clients;
    this->clients = bigger;
}

Fitness::Fitness(){
    this->name = new char[1];
    this->name[0] = '\0';
    this->capacity = 8;
    this->clients = new Client[this->capacity];
    this->size = 0;
}

Fitness::Fitness(const char* name){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->capacity = 8;
    this->size = 0;
    this->clients = new Client[this->capacity];
}

Fitness::Fitness(const Fitness& other){
    this->copy(other);
}

Fitness& Fitness::operator=(const Fitness& other){
    if(this != &other){
        this->erase();
        this->copy(other);
    }
    return *this;
}

Fitness::~Fitness(){
    this->erase();
}

const char* Fitness::getName() const { return this->name;}
int Fitness::getSize() const { return this->size;}

void Fitness::addClient(const Client& newClient){
    if(this->size >= this->capacity)
        this->resize();

    this->clients[size] = newClient;
    this->size++;
}

void Fitness::removeClient(const char* name){
    for(int i = 0; i < this->size; i++){
        if(strcmp(clients[i].getName(), name) == 0){
            for(int j = i; j < this->size - 1; j++){
                clients[j] = clients[j + 1];
            }
            this->size--;
        }
    }
}

void Fitness::updateClientsWeight(const char* name, float newWeight){
    for(int i = 0; i < this->size; i++){
        if(strcmp(clients[i].getName(), name) == 0){
            clients[i].setWeight(newWeight);
        }
    }
}

void Fitness::writeInBinary(){
    char* fileName = new char[strlen(this->name) + 9];
    strcpy(fileName, this->name);
    strcat(fileName, ".dat.bin");

    std::ofstream outf(fileName, std::ios::binary);

    outf.write(reinterpret_cast<const char*>(&this->size), sizeof(this->size));
    
    size_t name_len = strlen(this->name) + 1;
    outf.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
    outf.write(this->name, name_len);

    for(int i = 0; i < this->size; i++){
        this->clients[i].writeInBin(outf);
    }
    outf.close();
    delete[] fileName;
}

Fitness Fitness::readFromBinary(){
    char* fileName = new char[strlen(this->name) + 9];
    strcpy(fileName, this->name);
    strcat(fileName, ".dat.bin");

    std::ifstream inf(fileName, std::ios::binary);

    int size;
    inf.read(reinterpret_cast<char*>(&size), sizeof(size));

    size_t name_len;
    inf.read(reinterpret_cast<char*>(&name_len), sizeof(name_len));
    char* name = new char[name_len];
    inf.read(name, name_len);

    Fitness fitness(name);

    for(int i = 0; i < size; i++){
        Client client = Client::readFromBin(inf);
        fitness.addClient(client);
    }
    inf.close();
    delete[] fileName;

    return fitness;
}

void Fitness::writeInTxtFile(){
    char* fileName = new char[strlen(this->name) + 5];
    strcpy(fileName, this->name);
    strcat(fileName, ".txt");

    std::ofstream outf(fileName);
    outf << this->name << '\n';
    for(int i = 0; i < size; i++){
        outf << '[' << clients[i].getName() << '|' << clients[i].getAge() << '|' << clients[i].getWeight() << "]\n";
    }
    outf << '\n';
    outf.close();
    delete[] fileName;
}

void Fitness::print() const{
    std::cout << name << std::endl;
    for(int i = 0; i < size; i++){
        clients[i].print();
    }
}