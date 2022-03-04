#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Prisoner{
    char name[32];
    int ID;
    int serveTime;
    
    void create(){
        cout << "Enter name: ";
        cin.getline(name, 32);
        cout << "Enter ID: ";
        cin >> ID;
        cout << "Enter time left to serve: ";
        cin >> serveTime;
        cin.ignore();
    };

    void print() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Time left to serve: " << serveTime << endl;
        cout << endl;
    };
};


struct Prison{
    Prisoner prisoners[5];
    char prisonName[32];

    void sortPrison(){
        for(int i = 0; i < 5; i++){
            for(int j = i + 1; j < 5; j++){
                if(prisoners[i].serveTime > prisoners[j].serveTime){
                    Prisoner temp = prisoners[i];
                    prisoners[i] = prisoners[j];
                    prisoners[j] = temp;
                    }
            }
        }
    }
};

void printPrison(const Prison& prison, int numberOfPrisoners){
    cout << prison.prisonName << endl;
    for(int i = 0; i < numberOfPrisoners; i++)
        prison.prisoners[i].print();
}

int main(){
    Prison prison;
    for(int i = 0; i < 5; i++){
        prison.prisoners[i].create();
    }

    prison.sortPrison();
    printPrison(prison, 5);
}