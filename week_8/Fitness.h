#ifndef FITNESS_H_INCLUDED
#define FITNESS_H_INCLUDED

#include "Client.h" 

class Fitness{
private:
    char* name;
    Client* clients;
    
    int size;
    int capacity;

    void copy(const Fitness& other);
    void erase();
    void resize();
public:
    Fitness();
    Fitness(const char* name);
    Fitness(const Fitness& other);

    Fitness& operator=(const Fitness& other);

    ~Fitness();

    const char* getName() const;
    int getSize() const;

    void addClient(const Client& newClient);
    void removeClient(const char* name);
    void updateClientsWeight(const char* name, float weight);

    void writeInBinary();
    Fitness readFromBinary();
    void writeInTxtFile();

    void print() const;
};

#endif