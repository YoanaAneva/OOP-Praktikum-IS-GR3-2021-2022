#include <iostream>
#include <cstring>

struct Destination {
	char city[32];
	int kilometers; 
};

void create(Destination& destionation)
{
    std::cout << "Enter destination: " << std::endl;
    std::cout << "Enter name: " << std::endl;
    std::cin.getline(destionation.city, 32);
    std::cout << "Enter distance from Sofia: " << std::endl;
    std::cin >> destionation.kilometers;
}

void print(const Destination& destination){
    std::cout << destination.city << std::endl;
    std::cout << destination.kilometers << "km " << std::endl;
}

int main() {
    Destination d1 = {"Plovdiv", 144};
    Destination d2 = {"Burgas", 383};

    print(d1);
    std::cout << std::endl;
    print(d2);

    Destination destinations[30];
    for(int i = 0; i < 30; i++)
    {
        strcpy(destinations[i].city, '\0');
        destinations[i].kilometers = 0;
    }
}