#ifndef LIBRARYHPP_
#define LIBRARYHPP
#include <string>
#include <list>
#include <iostream>
#include "book.h"

using namespace std;

class Library
{

private:
    list<string> *library;
    int size;

public:
    Library(int defaultSize);
    ~Library();
    void insert(const string &bookTitle);
    bool bookSearch(const string &bookTitle);
    void returnBook(const string &bookTitle);
    void borrowBook(const string &bookTitle);
    void createNewBook(const string &bookTitle, const string &bookAuthor, const string &bookGenre, const string &bookSummary);

    private: 
    int computeID(const string &stringWord);
};

#endif // LIBRARY_HPP