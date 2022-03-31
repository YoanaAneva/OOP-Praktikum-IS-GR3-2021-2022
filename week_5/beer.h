#ifndef BEER_H
#define BEER_H

#include <iostream>
#include <cstring>

class Beer{
private:
    char* brand;
    int mililiters;

    void copy(const Beer& other);
    void erase();
public:
    void setBrand(const char* brand);
    void setMililiters(int mililiters);

    const char* getBrand() const;
    int getMililiters() const;

    Beer();
    Beer(const char* brand, int mililiters);
    Beer(const Beer& other);
    ~Beer();

    void printBeer() const;
    void add(Beer& beer, int mililiters);
    bool checkIfMixed(const char* beer) const;   
};

#endif