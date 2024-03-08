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

void User::borrowBook(Book* book) { // borrows the book and adds the book to the list of books they borrow
    userBooks.push_back(book);
}

void User::displayBooksOwned() const { // goes through each book and lists its title
    int count = 0;
    for (const auto& i : userBooks) {
        count++;
        cout << count << ". " << i->getBookTitle() << endl << endl;
    }
}
}