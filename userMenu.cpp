/**
* Assignment: <Lab 1: Manage User Accounts> 
* Name: <Jasmine Peng>
* Description: In this class, the user data is read and initialized. The list of actions that a user can take is also displayed on the console. It allows simple actions such as signing in, signing out, creating a new account, and updating user information.
* Date: <2/24/2024>
*/

#include <iostream>
#include <sstream>
#include <string>

#include "userMenu.h"
#include "utils.h"

using namespace std;

/**
 * Purpose: <Default constructor for UserMenu>
*/
UserMenu::UserMenu()
    : Menu("Manage User Accounts") {

    // init usermenu options
    initSelection();
    // load users_data.csv
    initData();
}

/**
* Purpose: <Constructor for UserMenu, where you can pass in the name of the UserMenu>
* Parameter: <string name>
*/
UserMenu::UserMenu(string name)
    : Menu(name) {

    // init usermenu options
    initSelection();
    // load users_data.csv
    initData();
}

/**
* List the usermenu selection...
*/
void UserMenu::initSelection() {
    // Initialize users options
    addOption("1) Sign-in");
    addOption("2) Sign Out");
    addOption("3) Reset Password");
    addOption("4) Create Account");
    addOption("5) Manage Profiles");
    addOption("x) Quit");
}

/**
* Function Name: <initData>
* Purpose: <Reads file and stores data into list>
* Return: <void>
*/
void UserMenu::initData() {
    openFile(inFile, USER_DATA);

    if (!inFile) {// Returns error if file error occurs
        cout << "Error opening file: " << USER_DATA << std::endl;
        return;
    }

    string line, text;
    int id = 0;
    string role, username, password, signInText, signOutText, fName, lName, address, city, state, zip, phone, email;

    int count = 0;
    while (getline(inFile, line)) {
        // Skip the first line - column names
        if (++count == 1) {
            continue;
        }
        istringstream ss(line);
        getline(ss, text, ',');
        id = stoi(text); // convert from text string to integer
        getline(ss, role, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, signInText, ',');
        getline(ss, signOutText, ',');
        getline(ss, fName, ',');
        getline(ss, lName, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        User user;
        user.setId(id);
        user.setRole(role);
        user.setSignInDateTime(signInText);
        user.setSignOutDateTime(signInText);
        user.setUserName(username);
        user.setPassword(password);
        user.setFirstName(fName);
        user.setLastName(lName);
        user.setAddress(address);
        user.setCity(city);
        user.setState(state);
        user.setZip(zip);
        user.setPhone(phone);
        user.setEmail(email);
        list.push_back(user);
    }

    inFile.close();
}

/**
 * Function Name: <activate>
 * Purpose: <Based on user menu input, runs a certain action>
 * Return: <void>
*/
void UserMenu::activate() {
    char input = 0;
    do {
        input = this->doMenuOption();
        if (input == USER_MENU_SIGNIN) {
            signIn();
        }
        else if (input == USER_MENU_SIGNOUT) {
            signOut();
        }
        else if (input == USER_MENU_RESET) {
            reset();
        }
        else if (input == USER_MENU_CREATE) {
            create();
        }
        else if (input == USERMENU_MANAGE_PROFILE) {
            manageProfiles();
        }
        else if (input == USER_MENU_EXIT) {
            doExit();
        }
        else {
            cout << "Invalid selection!!!" << endl;
        }
    } while (input != USER_MENU_EXIT);

}

/**
 * Function Name: <authenticate>
 * Purpose: <Sets a bool as true if username/email and password matches existing user>
 * Parameter: <string name, string pwd>
 * Return: <bool>
*/
bool UserMenu::authenticate(string name, string pwd) {
    bool valid = false;
    for (int i = 0; i < list.size() /** vector of users */; i++) {
        User u = list.at(i);
        // User the overloading operators for Week 3 in-class
        if ((name == u.getUsername() || name == u.getEmail()) && pwd == u.getPassword()) {
            valid = true;
            user = u; // Added by Jasmine Peng
            break;
        }
    }
    return valid;
}

/**
 * Function Name: <signIn>
 * Purpose: <Allows the user to sign in by checking if input matches existing csv records>
 * Return: <void>
*/
void UserMenu::signIn() {
    
    cout << "Sign-in" << endl;
    cout << "Enter email or mobile phone number: ";
    string name;
    cin >> name; // check if username or email (i.e. @)
    cout << "Enter password: ";
    string pwd;
    cin >> pwd;
    
    loginIn = authenticate(name, pwd);
    if (loginIn) {
        cout << "Sign in was successful" << endl;
        
        // System datetime now and update sign in datetime
        int mo, d, yr, hr, min, sec;
        getCurrentTime(mo, d, yr, hr, min, sec);
        user.setSignInDateTime(to_string(mo) + "/" + to_string(d) + "/" + to_string(yr) +
                            " " + to_string(hr) + ":" + to_string(min) + ":" + to_string(sec)); // Added by Jasmine Peng
        
        // Update list with new user data
        for (int i = 0; i < list.size() /** vector of users */; i++) {
            User u = list.at(i);
            // User the overloading operators for Week 3 in-class
            if (u == user) {
                list.at(i) = user;
            }
        }
    }
    else {
        cout << "Invalid username or password" << endl;
    }
}

/**
 * Function Name: <signOut>
 * Purpose: <Signs user out and updates sign out time>
 * Return: <void>
*/
void UserMenu::signOut() {
    // User must be already sign - in
    if (loginIn) {
        // Update sign out datetime
        int mo, d, yr, hr, min, sec;
        getCurrentTime(mo, d, yr, hr, min, sec);
        user.setSignOutDateTime(to_string(mo) + "/" + to_string(d) + "/" + to_string(yr) +
                            " " + to_string(hr) + ":" + to_string(min) + ":" + to_string(sec)); // Added by Jasmine Peng
        
        // Update list with new user data
        for (int i = 0; i < list.size() /** vector of users */; i++) {
            User u = list.at(i);
            // User the overloading operators for Week 3 in-class
            if (u == user) {
                list.at(i) = user;
            }
        }
        
        loginIn = false; // Set logIn back to false
        
        // Save new sign - in and sign - out datetime to users_data.csv
        saveData();
        
    } else {
        cout << "You must sign-in before proceed" << endl;
        signIn();
    }
}

/**
 * Function Name: <reset>
 * Purpose: <Allows user to reset password and saves to file>
 * Return: <void>
*/
void UserMenu::reset() {
    // User must be already sign - in
    if (loginIn) {
        cout << "Enter password: ";
        string pwd;
        cin >> pwd;
        cout << "Enter new password: ";
        string newpwd;
        cin >> newpwd;
        
        // Checks that user enters correct existing password
        if (user.getPassword() == pwd) {
            // Sets password as new password
            user.setPassword(newpwd);
        }
        
        // Update list with new user data
        for (int i = 0; i < list.size() /** vector of users */; i++) {
            User u = list.at(i);
            // Checks that the id of user matches row in list vector
            if (u == user) {
                list.at(i) = user;
            }
        }
        
        // Save new password to users_data.csv
        saveData();

        
    } else {
        cout << "You must sign-in before proceed" << endl;
        signIn();
    }
}

/**
 * Function Name: <create>
 * Purpose: <Allows the creation of new user and saving user to file>
 * Return: <void>
*/
void UserMenu::create() {
    
    if (!loginIn) {
        // Create new user
        User myuser;
        
        // Finding and setting the user Id
        int idcount = 1000;
        for (int i = 0; i < list.size(); i++)
        {
            idcount++; //
        }
        myuser.setId(idcount); // Sets the Id for the user
        
        
        // Sets the moment the user was created as sign - in datetime
        int mo, d, yr, hr, min, sec;
        getCurrentTime(mo, d, yr, hr, min, sec);
        myuser.setSignInDateTime(to_string(mo) + "/" + to_string(d) + "/" + to_string(yr) +
                            " " + to_string(hr) + ":" + to_string(min) + ":" + to_string(sec));
        
        cin >> myuser; // Allows user to input all information related to a user account
                       // Sets those inputs into the member variables of 'myuser'
        
        list.push_back(myuser); // Adds user to the list
        user = myuser; // Set current user as the newly created user
        loginIn = true; // User is logged in as newly created user
        
        // Save new user information to users_data.csv
        saveData();
        
    } else {
        cout << "You must sign out to proceed" << endl;
    }

}

/**
 * Function Name: <manageProfiles>
 * Purpose: <Allows signed in user to update their information>
 * Return: <void>
*/
void UserMenu::manageProfiles() {
    // User must be already sign - in
    if (loginIn) {
        User updated;
        cin >> updated; // stores new user information into 'updated'
        
        for (int i = 0; i < list.size(); i++) {
            User u = list.at(i);
                if (u == user) {
                    // Update user with all of the newly inputted values
                    user.setFirstName(updated.getFirstName());
                    user.setLastName(updated.getLastName());
                    user.setRole(updated.getRole());
                    user.setPhone(updated.getPhone());
                    user.setEmail(updated.getEmail());
                    user.setUserName(updated.getUsername());
                    user.setAddress(updated.getAddress());
                    user.setCity(updated.getCity());
                    user.setState(updated.getState());
                    user.setZip(updated.getZip());
                    break;
                }
         }
        
        // Update list with new user data
        for (int i = 0; i < list.size() /** vector of users */; i++) {
            User u = list.at(i);
            // Checks that the id of user matches row in list vector
            if (u == user) {
                list.at(i) = user;
            }
        }
        
        // Save new data to users_data.csv
        saveData();
        
    } else {
        cout << "You must sign-in before proceed" << endl;
        signIn();
    }
}

/**
 * Function Name: <doExit>
 * Purpose: <Allows user to exit the running program>
 * Return: <void>
*/
void UserMenu::doExit() {
    signOut();
    cout << "You are exiting the program" << endl;
    exit(0);
}

/**
 * Function Name: <saveData>
 * Purpose: <Save the current list data to the csv file>
 * Return: <void>
*/
void UserMenu::saveData() {
    
    openFile(inFile, USER_DATA);
    
    inFile << "Id, Role, Username, Password, Sign - in datetime, Sign out datetime, First Name, Last Name, Address, City, State, Zip, Phone, Email" << endl;
    for (User user : list){
        inFile << user << endl;
    }
    
    inFile.close();
}
