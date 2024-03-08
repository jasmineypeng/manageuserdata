/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This provides the header of the User class which stores the attributes and personal information of a given user.
* Date: <2/24/2024>
*/

#pragma once
#include <string>
#include "dateTime.h"

using namespace std;

class User {
    friend istream& operator >>(istream& in, User& user);
    friend ostream& operator<<(ostream& out, User& user);

public:
    User();
    User(string _name, string _password) {
        username = _name;
        password = _password;
    };
    ~User();

    // Mutator methods
    void setId(int _id) { id = _id; };
    void setRole(string _role) { role = _role; };
    void setSignInDateTime(string dt) {    signInDt.setDateTime(dt); }
    void setSignOutDateTime(string dt) { signOutDt.setDateTime(dt);    }
    void setUserName(string name) {    username = name; };
    void setPassword(string name) {    password = name; };
    void setFirstName(string name) { firstname = name; };
    void setLastName(string name) {    lastname = name; };
    void setAddress(string name) { address = name; };
    void setCity(string name) {    city = name; };
    void setState(string name) { state = name; };
    void setZip(string value) {    zip = value; };
    void setPhone(string value) { phone = value; };
    void setEmail(string name) { email = name; };

    // Accessor methods
    int getId() { return id; };
    string getRole() { return role;    };
    string getUsername() { return username; };
    string getPassword() { return password; };
    DateTime getsignInDateTime() { return signInDt; };
    DateTime getsignOutDateTime() { return signOutDt; };
    string getFirstName() { return firstname; };
    string getLastName() { return lastname; };
    string getAddress() { return address; };
    string getCity() { return city; };
    string getState() { return state; };
    string getZip() { return zip; };
    string getPhone() { return phone; };
    string getEmail() { return email; };

    string to_csv();

    // returns whether the user Id is the same
    bool operator==(const User&) const;
    // returns whether the user Id is different
    bool operator!=(const User&) const;

    // compare user Id with the same operator
    bool operator>(const User&) const;
    bool operator<(const User&) const;
    bool operator>=(const User&) const;
    bool operator<=(const User&) const;

private:
    // data member from users_data.csv
    int id;
    string role;
    string username;
    string password;
    DateTime signInDt;
    DateTime signOutDt;
    string firstname;
    string lastname;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    string email;
};
