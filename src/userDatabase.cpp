#include "../header/user.h"
#include "../header/userDatabase.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

/*
implement delete account or is that unnecessary?

library private variable is a list of book pointers 
but library object creates just a list of books

where do i find your read text file function?

make the txt file stuff in its own class
*/


userDatabase::userDatabase(int size) {
    this->size = size;
    this->listOfUsers = new list<User>[size];
}

userDatabase::~userDatabase() {

}

void userDatabase::addUser(const string& username, const string& password) {
    bool accountExists = searchUser(username);
    if (accountExists) {
        cout << "Account already exists!" << endl;
    } else {
        User newUser(username, password);
        listOfUsers->push_back(newUser);
    }
}

bool userDatabase::searchUser(const string& username) {
    list<User>::iterator itr;
    itr = listOfUsers->begin();
    
    while (itr != listOfUsers->end()) {
        if (itr->getUsername() == username) {
            return true;
        }
        itr++;
    }

    return false;
}

bool userDatabase::isAdmin(const string& username, const string& password) {
    if (username == "Admin1" && password == "cs100") {
        return true;
    } else {
        return false;
    }
}