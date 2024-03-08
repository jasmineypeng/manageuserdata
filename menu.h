/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: This is a simple Menu class which names and displays options.
* Date: <2/24/2024>
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
   base class menu
*/
class Menu {
public:
    // Default constructor
    Menu();

    // Constructor with name of the menu.
    Menu(string name);

    // Name of the menu
    void setName(string name) {
        this->name = name;
    }

    /**
       Adds an option to the end of this menu.
       @param option the option to add
    */
    void addOption(string option);
    /**
       Displays the menu, with options numbered starting with 1,
       and prompts the user for input. Repeats until a valid input
       is supplied.
       @return the number that the user supplied
    */
    int doMenu() const;
    int doMenuIndex() const;
    char doMenuOption() const;

    bool hasOption() const {
        return options.size() > 0;
    };
private:
    void display() const;
    void displayIndex() const;

    string name;
    vector<string> options;
};
