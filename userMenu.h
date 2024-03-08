/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This is the header class where user data is read and initialized and allows the user to update or change the user data.
* Date: <2/24/2024>
*/

#pragma once
#include <fstream>
#include <vector>
#include "menu.h"
#include "user.h"

using namespace std;

const string USER_DATA = "users_data.csv";

enum USER_MENU_OPTION {
    USER_MENU_SIGNIN = '1',
    USER_MENU_SIGNOUT = '2',
    USER_MENU_RESET = '3',
    USER_MENU_CREATE = '4',
    USERMENU_MANAGE_PROFILE = '5',
    USER_MENU_EXIT = 'x'
};

class UserMenu : public Menu {
public:
    
    UserMenu();
    UserMenu(string name); // Name of the UserName

    // Entry point into the UserMenu component
    void activate();

private:
    // Private method of the class:
                            // Menu member function for:
    void signIn();            // USER_MENU_SIGNIN
    void signOut();            // USER_MENU_SIGNOUT
    void reset();            // USER_MENU_CREATE
    void create();            // USER_MENU_RESET
    void manageProfiles();    // USERMENU_MANAGE_PROFILE
    void doExit();            // USER_MENU_EXIT

    void initSelection();    // Init usermenu selection
    void initData();        // read users_data.csv
    void saveData();        // save to users_data.csv
    bool authenticate(string name, string pwd);    // true for valid user

    // Data member of UserMenu:
    fstream inFile;            // file pointer
    User user;                // instance of user signs in
    vector<User> list;        // list of users from users_data.csv
    bool loginIn = false;
};
