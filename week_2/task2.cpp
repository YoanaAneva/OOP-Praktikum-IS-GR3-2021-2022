#include <iostream>
#include <cstring>
#include <fstream>

class Weapon{
    private:
    char name[24];
    int power;
    int durability;

    public:
    Weapon(){
        setName(" ");
        setPower(0);
        setDurability(0);
    }

    Weapon(const char* name, int power, int durability){
        setName(name);
        setPower(power);
        setDurability(durability);
    }

    void setName(const char* name){
        strcpy(this->name, name);
    }

    void setPower(int power){
        this->power = power;
    }

    void setDurability(int durability){
        this->durability = durability;
    }

    const char* getName() const {
        return name;
    }

    int getPower() const {
        return power;
    }

    int getDurability() const {
        return durability;
    }

    void use(int input){
        durability -= input;
    }

    void print(){
        std::cout << std::endl << name << std::endl;
        std::cout << power << std::endl;
        std::cout << durability << std::endl;
    }
};

class Fighter{
    private:
    char name[24];
    int strength;
    int health;
    Weapon weapon;

    public:
    Fighter(){
        setName(" ");
        setStrength(0);
        setHealth(0);
        setWeapon(weapon);
    }

    Fighter(char* name, int strength, int health, Weapon weapon){
        setName(name);
        setStrength(strength);
        setHealth(health);
        setWeapon(weapon);
    }

    void setName(char* name){
        strcpy(this->name, name);
    }

    void setStrength(int strength){
        this->strength = strength;
    }

    void setHealth(int health){
        this->health = health;
    }

    void setWeapon(Weapon& weapon){
        this->weapon = weapon;
    }

    const char* getName() const{
        return name;
    }

    int getStrength() const{
        return strength;
    }

    int getHealth() const{
        return health;
    }

    const Weapon& getWeapon() const {
        return weapon;
    }

    bool isDead(int health){
        if (health == 0){
            std::cout << "You have died :(" << std::endl;
            return true;
        }
    }

    void attack(Fighter& other){
        other.health -= 10;
    }
};

int main(){

}