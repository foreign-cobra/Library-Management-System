#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <list>
#include "../header/book.h"

using namespace std;

class User {
    public:
        string getUsername() const;
        void setUsername(string user);
        string getPassword() const;
        void setPassword(string pass);
        list<Book*> getBookList() const;
        void borrowBook(Book* book);
        void displayBooksOwned() const;
        User();
        User(string user, string pass);
    private:
        string username;
        string password;
        list<Book*> userBooks;
};


#endif