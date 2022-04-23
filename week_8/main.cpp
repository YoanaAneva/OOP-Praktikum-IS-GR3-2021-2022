#include "Fitness.h"

int main(){
    Client c1("Gosho", 34, 89);
    Client c2("Pesho", 21, 76.9);
    Client c3("Ivan", 29, 103.7);

    Fitness fitness("Batka31");
    fitness.addClient(c1);
    fitness.addClient(c2);
    fitness.addClient(c3);

    fitness.writeInBinary();
    Fitness fitness1 = fitness.readFromBinary();

    fitness1.print();
    fitness1.writeInTxtFile();
    return 0;
}