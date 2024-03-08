/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This class allows us to define the implementation of User and its given attributes, including getter&setter methods and operator overloading.
* Date: <2/24/2024>
*/
#include <iostream>
#include "user.h"

using namespace std;

/**
 * Purpose: <Default constructor where id is set to 0>
*/
User::User() {
    id = 0;
}

/**
* Purpose: <This is a destructor for a User object>
*/
User::~User() {
}

/**
 * Function Name: <to_csv>
 * Purpose: <Returns the string of all the private member variables of User>
 * Return: <string>
*/
string User::to_csv() {
    return to_string(id) + ","
        + role + ","
        + username + ","
        + password + ","
        + signInDt.toString() + ","
        + signOutDt.toString() + ","
        + firstname + ","
        + lastname + ","
        + address + ","
        + city + ","
        + state + ","
        + zip + ","
        + phone + ","
        + email;
}

/**
 * Purpose: <Overloads the == operator, checks input id == user id>
 * Parameter: <const User& user>
 * Return: <bool>
*/
bool User::operator==(const User& user) const {
    return id == user.id;
}

/**
 * Purpose: <Overloads the != operator, checks input id != user id>
 * Parameter: <const User& user>
 * Return: <bool>
*/
bool User::operator!=(const User& user) const {
    return id != user.id;
}

/**
 * Purpose: <Overloads the >  operator, checks input id > user id
 * Parameter: <const User& user>
 * Return: <bool>
*/
bool User::operator>(const User& user) const {
    return id > user.id;
}

/**
 * Purpose: <Overloads the < operator, checks input id < user id>
 * Parameter: <const User& user>
 * Return: <bool>
*/
bool User::operator<(const User& user) const {
    return id < user.id;
}

/**
 * Purpose: <Overloads the >=  operator, checks input id >= user id>
 * Parameter: <const User& user>
 * Return: <bool>
*/
bool User::operator>=(const User& user) const {
    return id >= user.id;
}

/**
 * Purpose: <Overloads the <= operator, checks input id <= user id>
 * Parameter: <const User& user>
 * Return: <bool>
*/
bool User::operator<=(const User& user) const {
    return id <= user.id;
}

/**
 * Purpose: <Overloads the input stream operator>
 * Parameter: <const User& user>
 * Return: <bool>
*/
istream& operator >>(istream& in, User& user){
    cout << "Enter first name: ";
    in >> user.firstname;
    cout << "Enter last name: ";
    in >> user.lastname;
    cout << "Enter role: ";
    in >> user.role;
    cout << "Enter mobile phone number: ";
    in >> user.phone;
    cout << "Enter email: ";
    in >> user.email;
    cout << "Enter username: ";
    in >> user.username;
    cout << "Enter password: ";
    in >> user.password;
    cout << "Enter address: ";
    getline(in >> ws, user.address); // Allows for whitespace and multiple words
    cout << "Enter city: ";
    getline(in >> ws, user.city);
    cout << "Enter state: ";
    getline(in >> ws, user.state);
    cout << "Enter zip: ";
    getline(in >> ws, user.zip);
    return in;
}

/**
 * Purpose: <Overloads the << operator>
 * Parameter: <const User& user>
 * Return: <bool>
*/
ostream& operator<<(ostream& out, User& user) {
    out << user.to_csv();
    return out;
}
