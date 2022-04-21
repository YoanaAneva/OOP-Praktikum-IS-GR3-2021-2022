#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int hour, int minutes);
    Time(const Time& other);
    Time& operator=(const Time& other);


    void setHours(int hours);
    void setMinutes(int minutes);

    int getHours() const;
    int getMinutes() const;

    void printTime() const;
    void addMinutes(int minutes);
    int getMinutesFromStartOfDay() const;
};

#endif