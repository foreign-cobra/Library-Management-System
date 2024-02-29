#ifndef USERDATABASE_H
#define USERDATABASE_H

#include <iostream>
#include <list>
#include <string>
#include "../header/user.h"

using namespace std;

class userDatabase {
    public:
        userDatabase(int size);
        ~userDatabase();
        void addUser(const string& username, const string& password);
        bool searchUser(const string& username);
        // void returnUser(const string& username);
        bool isAdmin(const string& username, const string& password);

    private:
        list<User> *listOfUsers;
        int size;
};

#endif