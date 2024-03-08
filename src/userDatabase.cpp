#include "../header/user.h"
#include "../header/userDatabase.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include "../header/termcolor.hpp"
#include "../header/helper.h"

using namespace std;

userDatabase::userDatabase() { // creates the user database
    // nothing for now
    size = 0;
}

userDatabase::~userDatabase() {
    // Iterate through the list and delete each User object
    for (const auto& i : listOfUsers) {
        delete i;
    }

    listOfUsers.clear();
}

int userDatabase::getSize() const {
    return size;
}

list<User*> userDatabase::getUserList() const {
    return listOfUsers;
}

void userDatabase::addUser(User*& newUser) { // first searches if the username is in the database, if it's not then add it to the database
    listOfUsers.push_back(newUser);
    size++;
}

User* userDatabase::searchUser(const string& username, const string& password) { // iterates through the entire database list until it finds the matching username
    for (User* user: listOfUsers) {
        if ((user->getUsername() == username) && (user->getPassword() == password)) {
            return user;
        }
    }

    return nullptr;
}

bool userDatabase::isAdmin(const string& username, const string& password) { // used to check if the user logs in with admin account info and allows them extra features
    if (username == "Admin1" && password == "cs100") {
        return true;
    } else {
        return false;
    }
}

void userDatabase::displayAllUsers() const {
    int count = 0;
    for (const auto& i : listOfUsers) {
        count++;
        cout << count << ". " << "Username: " << i->getUsername() << endl << endl;
    }
}

User* userDatabase::createAccount() {
    User* newUser = loginLayout();

    try {
        ofstream accountFile;
        accountFile.open("accounts.txt", ios::app);                  // We must first open our database file
        if (accountFile.is_open()) {
            accountFile << newUser->getUsername() << "," << newUser->getPassword() << "\n";
            addUser(newUser);
            accountFile.close();
        } else {
            accountFile.close();
            throw runtime_error("ERROR: Couldn't open accounts file :(");
        }
    } catch(const exception& error) {
        cout << error.what() << endl;
    }
    return newUser;
}

User* userDatabase::signIn() {
    int terminalWidth = 160;
    string username;
    string password;


    simpleMenu();
    cout << termcolor::yellow;
    string prompt1 = "--- Sign Into Your Account ---";
    string prompt2 = "Please enter a username: ";
    string prompt3 = "Please enter a password: ";
    string prompt4 = "Both your Username and Password must be at least 5 characters!";
    cin.ignore();

    do {
        centerText(prompt4, terminalWidth);
        cout << "\n\n\n";
        centerText(prompt1, terminalWidth);
        cout << "\n\n\n";
        centerText(prompt2, terminalWidth);
        getline(cin, username);
        cout << "\n\n";
        centerText(prompt3, terminalWidth);
        getline(cin, password);
        cout  << "\n\n";
    } while((username.size() < 5) || (password.size() < 5)); 

    // Now that the username and password have been recorded, we have to read from the accounts.txt file to see if the account exists

    try {
        ifstream accountFile;
        accountFile.open("accounts.txt", ios::app);
        string newUsername;
        string newPassword;

        if (accountFile.is_open()) {
            while(getline(accountFile, newUsername, ',') && 
            getline(accountFile, newPassword)) {
                if((username == newUsername) && (password == newPassword)) {
                    return searchUser(newUsername, newPassword);
                }
            }
            accountFile.close();
        }

        else {
            accountFile.close();
            throw runtime_error("ERROR: Couldn't open accounts file :(");        //Run time error in case file does not open
        }
    }

    catch(const exception& error) {
        cout << error.what() << endl;
    }
    return nullptr;
}