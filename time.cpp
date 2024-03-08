/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This class allows us to define Time, given as hr, min, sec
* Date: <2/24/2024>
*/
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "time.h"

using namespace std;

/**
* Returns Time as a string in specific format (ex. "06:20:23")
*/
string Time::toString() {
    return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second); // AM/PM or 24H
}

/**
* Sets Time with hour, minute, and second from given string
*/
void Time::setTime(string t) {
    // Parse string ".... 18:30:11" to hr, min, sec
    string text;
    istringstream ss2(t);
    getline(ss2, text, ':');
    int hr = stoi(text);
    getline(ss2, text, ':');
    int min = stoi(text);
    getline(ss2, text, ':');
    int second = stoi(text);
    setHour(hr);
    setMinute(min);
    setSecond(second);
}


/**
* Overloads the << operator for Time object and sets as specific format
* Time format hour:minute:second
*/
ostream& operator<<(ostream& out, Time time) {
    char fill = out.fill('0');
    out << setw(2) << time.hour << ':'
        << setw(2) << time.minute << ':'
        << setw(2) << time.second;
    out.fill(fill);
    return out;
}
