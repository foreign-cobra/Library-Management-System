#include "../header/user.h"
#include "../header/book.h"

using namespace std;

User::User() : username(""), password("") {
}

User::User(string user, string pass) : username(user), password(pass) {
}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

void User::setUsername(string user) {
    this->username = user;
}

void User::setPassword(string pass) {
    this->password = pass;
}

list<Book*> User::getBookList() const {
    return userBooks;
}

void User::borrowBook(Book* book) {
    userBooks.push_back(book);
}

void User::displayBooksOwned() const {
    int count = 0;
    for (const auto& i : userBooks) {
        count++;
        cout << count << ". " << i->getBookTitle() << endl << endl;
    }
}

/*
    add books as a different class?
    display books owned as a different class?
*/ 

