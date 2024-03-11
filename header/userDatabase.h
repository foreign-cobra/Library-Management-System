#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <iostream>
#include <list>
#include <string>
#include "../header/user.h"

using namespace std;

class userDatabase {
    public:
        userDatabase();
        ~userDatabase();
        int getSize() const;
        list<User*> getUserList() const;
        void addUser(User*& newUser);
        User* searchUser(const string& username);
        bool isAdmin(User*& newUser);
        void displayAllUsers() const;
        User* createAccount();
        User* signIn();

    private:
        list<User*> listOfUsers;
        int size;
};

#endif