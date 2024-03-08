/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This is header for the DateTime class which inherits from the Time class and is defined as Month/Day/Year Hour:Minute:Second
* Date: <2/24/2024>
*/

#pragma once
#include <string>
#include "time.h"

using namespace std;


class DateTime : public Time {
    friend ostream& operator<<(ostream& out, DateTime dt);

public:
    DateTime();
    DateTime(string dt);
    DateTime(int mon, int day, int yr);
    DateTime(int mon, int day, int yr, int hr, int min, int second);

    void setDateTime(string dt);

    int getMonth() { return month; };
    int getDay() { return day; };
    int getYear() { return year; };

    string toString();

    // You may need these operators for comparing datetime
    bool operator>(const DateTime&) const;
    bool operator<(const DateTime&) const;
    bool operator>=(const DateTime&) const;
    bool operator<=(const DateTime&) const;

private:
    int month;
    int day;
    int year;
};
