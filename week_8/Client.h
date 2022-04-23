#ifndef Client_H_INCLUDED
#define Client_H_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstddef>

class Client{
private:
    char* name;
    int age;
    float weight;
    void copy(const Client& other);
public:
    Client();
    Client(const char* name, int age, float weight);
    Client(const Client& other);

    Client& operator=(const Client& other);

    ~Client();

    void setName(const char* name);
    void setAge(int age);
    void setWeight(float weight);

    const char* getName() const;
    int getAge() const;
    float getWeight() const;
    void writeInBin(std::ofstream& outf);
    static Client readFromBin(std::ifstream& inf);
    void print() const;
};

#endif