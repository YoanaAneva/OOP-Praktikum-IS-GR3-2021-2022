#include "beer.h"

void Beer:: copy(const Beer& other){
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);
    this->mililiters = other.mililiters;
}
void Beer::erase(){
    delete[] this->brand;
}

void Beer::setBrand(const char* brand){
    delete[] this->brand;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}
void Beer::setMililiters(int mililiters){
    this->mililiters = mililiters;
}

const char*Beer::getBrand() const{
    return this->brand;
}
int Beer::getMililiters() const{
    return this->mililiters;
}

Beer::Beer(){
    setBrand("");
    setMililiters(-1);
}
Beer::Beer(const char* brand, int mililiters){
    setBrand(brand);
    setMililiters(mililiters);
}
Beer::Beer(const Beer& other){
    this->erase();
    this->copy(other);
}
Beer::~Beer(){
    this->erase();
}

void Beer::printBeer() const{
    std::cout << this->brand << std::endl;
    std::cout << this->mililiters << std::endl;
}
void Beer::add(Beer& beer, int mililiters){
    // try{
    //     if(mililiters > beer.mililiters){
    //         throw "Cannot poor that much!";
    //     }
    // }
    // catch(const char msg){
    //     std::cout << msg << std::endl;
    //     return;
    // }
    int size = strlen(this->brand);
    char copy[size + 1];
    strcpy(copy, this->brand);
    this->erase();
    this->brand = new char[size + strlen(beer.brand) + 2];

    for(int i = 0; i < size; i++)
        this->brand[i] = copy[i];
    this->brand[size] = '&';
    for(int i = size + 1; i < size + strlen(beer.brand) + 2; i++)
        this->brand[i] = beer.brand[i - size - 1];
    
    this->mililiters += mililiters;
}
bool Beer::checkIfMixed(const char* beer) const{
    for(int i = 0; i < strlen(this->brand); i++){
        if(this->brand[i] == beer[i]){
            for(int j = i; j < strlen(beer); j++){
                if(this->brand[j] != beer[j])
                    return false;
            }
        }
    }
    return true;
}

int main(){
    Beer b1("Pirinsko", 500);
    Beer b2("Burgasko", 500);
    b1.printBeer();
    b1.add(b2, 300);
    b1.printBeer();
    std::cout << b1.checkIfMixed("Burgasko") << std::endl;
}