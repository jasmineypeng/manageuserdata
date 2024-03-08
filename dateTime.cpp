/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This is a DateTime class which inherits from the Time class and is defined as Month/Day/Year Hour:Minute:Second
* Date: <2/24/2024>
*/
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "dateTime.h"
#include "time.h"

using namespace std;

/**
* Sets DateTime as 0/0/0 0:0:0
*/
DateTime::DateTime()
    : Time(0,0,0) {
    month = 0;
    day = 0;
    year = 0;
};

/**
* Sets DateTime as a given month, day, year, hr, min, sec
*/
DateTime::DateTime(int mon, int day, int yr, int hr, int min, int second)
    : Time(hr, min, second) {
    month = mon;
    this->day = day;
    year = yr;
}

/**
* Sets DateTime as a given month, day, year and hr, min, sec from string input
*/
DateTime::DateTime(string dt) {
    setDateTime(dt);
}

/**
* Sets DateTime as a given month, day, year and Time 0:0:0
*/
DateTime::DateTime(int mon, int day, int yr)
    : Time(0, 0, 0) {
    month = mon;
    this->day = day;
    year = yr;
}

/**
* Convert string dt to dateTime
* Format: ex. 1/29/2024 18:30:11
*/
void DateTime::setDateTime(string dt) {
    // Split string dt datetime to Date and Time
    int index = static_cast<int>(dt.find(' '));
    string sdate = dt.substr(0, index);    // ex. "1/29/2024"
    istringstream ss(sdate);
    string text;
    getline(ss, text, '/');
    month = stoi(text);
    getline(ss, text, '/');
    day = stoi(text);
    getline(ss, text, '/');
    year = stoi(text);
    
    string stime = dt.substr(++index);    // ex. "18:30:11"
    Time::setTime(stime);
}

/**
* Changes DateTime to string
*/
string DateTime::toString() {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year) + " " + Time::toString();
}

/**
* Operator overloading > for DateTime object
*/
bool DateTime::operator>(const DateTime& dt) const {
    return month > dt.month;
}

/**
* Operator overloading < for DateTime object
*/
bool DateTime::operator<(const DateTime& dt) const {
    return month < dt.month;
}

/**
* Operator overloading >= for DateTime object
*/
bool DateTime::operator>=(const DateTime& dt) const {
    return month >= dt.month;
}

/**
* Operator overloading <= for DateTime object
*/
bool DateTime::operator<=(const DateTime& dt) const {
    return month <= dt.month;
}


/**
* Outputs DateTime in a specific format
* ex.
* cout << "1/29/2024 18:30:11"
*/
ostream& operator<<(ostream& out, DateTime dt) {
    char fill = out.fill('0');
    out << setw(2) << dt.getMonth() << '/'
        << setw(2) << dt.getDay() << '/'
        << setw(2) << dt.getYear()
        << " " << dt.getTime();
    out.fill(fill);
    return out;
}
