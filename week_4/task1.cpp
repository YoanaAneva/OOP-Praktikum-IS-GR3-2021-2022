#include <iostream>
#include <fstream>
#include <cstring>


enum Type{
    dummy,
    Dog,
    Cat,
    Rabbit
};

class Animal{
    private:
    Type type;
    char name[24];
    int age;
    char gender;

    public:
    void setType(Type type) {
        this->type = type;
    }

    void setName(char* name) {
        strcpy(this->name, name);
    }

    void setAge(int age){
        this->age = age;
    }

    void setGender(char gender) {
        this->gender = gender;
    }

    const Type& getType() const {
        return this->type;
    }
    
    const char* getName() const {
        return this->name;
    }

    int getAge() const {
        return this->age;
    }

    char getGender() const {
        return this->gender;
    }

    Animal(){
        setType(dummy);
        setName("");
        setAge(0);
        setGender('0');
    }

    Animal (Type type, char* name, int age, char gender){
        setType(type);
        setName(name);
        setAge(age);
        setGender(gender);
    }

    void writeToFile(std::ofstream& outf){
        if(!outf.is_open()){
            std::cout << "Cannot open file!" << std::endl;
            return;
        }

        if(!outf){
            std::cout << "File is not in a good condition!" << std::endl;
        }

        outf.write((char*) &type, sizeof(type));
        outf.write((char*) &name, sizeof(name));
        outf.write((char*) &age, sizeof(age));
        outf.write((char*) &gender, sizeof(gender));
    }

    void readFromFile(std::ifstream& inf){
        if(!inf.is_open()){
            std::cout << "Cannot open file!" << std::endl;
            return;
        }

        if(!inf){
            std::cout << "File is not in a good condition!" << std::endl;
        }
        std::cout << std::endl;
        inf.read((char*) &type, sizeof(type));
        inf.read(name, sizeof(name));
        inf.read((char*) &age, sizeof(age));
        inf.read((char*) &gender, sizeof(gender));
    }

    void print(){
        std::cout << std::endl;
        std::cout << type << std::endl;
        std::cout << name << std::endl;
        std::cout << age << std::endl;
        std::cout << gender << std::endl;
    }
};

int main(){
    char name[24];
    int age;
    char gender;
    
    int userInput;
    std::cout << std::endl << "1.Dog\n2.Cat\n3.Rabbit\nChoose type of pet: ";
    std::cin >> userInput;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::cin.getline(name, 24);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter gender (m/f): ";
    std::cin >> gender;
    
    
    Animal animal((Type)(userInput), name, age, gender);
    Animal animalTest;

    std::ofstream out("animal.bin", std::ios::binary);

    animal.writeToFile(out);

    out.close();
    
    std::ifstream in("animal.bin", std::ios::binary);

    animalTest.readFromFile(in);

    in.close();

    animalTest.print();
}