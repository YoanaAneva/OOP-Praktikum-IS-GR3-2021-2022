#include "Time.h"

Time::Time() : hours(0), minutes(0){}

Time::Time(int hours, int minutes){
    if(hours > 23)
        throw std::invalid_argument("Invalid hour!");
    this->hours = hours;

    if(minutes > 59)
        std::invalid_argument("Invalid minutes!");
    this->minutes = minutes;
}

Time::Time(const Time& other){
    this->hours = other.hours;
    this->minutes = other.minutes;
}

Time& Time::operator=(const Time& other){
    this->hours = other.hours;
    this->minutes = other.minutes;
}

void Time::setHours(int hours){
    this->hours = hours;
}
void Time::setMinutes(int minutes){
    this->minutes = minutes;
}

int Time::getHours() const {
    return this->hours;
}
int Time::getMinutes() const{
    return this->minutes;
}

void Time::printTime() const{
    char time[6];
    time[0] = '0' + this->hours / 10;
    time[1] = '0' + this->hours % 10;
    time[2] = ':';
    time[3] = '0' + this->minutes / 10;
    time[4] = '0' + this->minutes % 10;
    std::cout << time << std::endl;
}

void Time::addMinutes(int minutes){
    this->minutes += minutes;

    while(this->minutes > 59){
        this->minutes -= 60;
        this->hours++;
    }
}

int Time::getMinutesFromStartOfDay() const{
    int minutes = this->minutes;
    int tmp = this->hours;
    while(tmp != 0){
        minutes += 60;
        tmp--;
    }
    return minutes;
}

int main(){
    Time t(12,35);
    t.addMinutes(153);
    t.printTime();
    std::cout << t.getMinutesFromStartOfDay();
}