/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This is the header class for Time, given as hr, min, sec
* Date: <2/24/2024>
*/

#pragma once
#include <string>
#include <ostream>

using namespace std;

class Time {
    friend ostream& operator<<(ostream& out, Time time);
public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    };

    Time(int hour, int min, int sec) {
        this->hour = hour;
        minute = min;
        second = sec;
    };

    void setTime(string t);
    void setHour(int hr) { hour = hr; };
    void setMinute(int min) { minute = min;    };
    void setSecond(int sec) { second = sec;    }

    Time getTime() { return *this; };
    int getHour() {    return hour; };
    int getMinute() { return minute; };
    int getSecond() { return second; };

    string toString();

private:
    int hour;
    int minute;
    int second;
};
