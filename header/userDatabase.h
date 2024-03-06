#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <iostream>
#include <list>
#include <string>
#include "../header/user.h"

using namespace std;

class userDatabase {
    public:
        // userDatabase(const string& fileName);
        // ~userDatabase();
        // void addUser(const string& username, const string& password);
        // User* searchUser(const string& username);
        // bool isAdmin(const string& username, const string& password);
        // void displayAllUsers() const;
        // list<User>* createDatabase(const string& file);
        // void createAccount();
        // void signIn();
        userDatabase();
        ~userDatabase();
        int getSize() const;
        list<User*> getUserList() const;
        void addUser(const string& username, const string& password);
        // User* searchUser(const string& username, const string& password);
        bool isAdmin(const string& username, const string& password);
        void displayAllUsers() const;
        void createAccount();

    private:
        list<User*> listOfUsers;
        int size;
};

#endif