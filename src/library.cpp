#include "../header/library.h"
#include "../header/book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

Library::Library(int defaultSize) {
    size = defaultSize;
    library = new list<Book>[size];
}

Library::~Library() {
    // TODO: Implement appropriate destructor for the Library
}

void Library::insert(const string& bookTitle, const string &bookAuthor, const string &bookGenre, const string& bookSummary) {
    int possibleLocation = computeID(bookTitle);

    list<Book>::iterator traverser; //Traverser that goes through the chained linked list at a specified index of the HashTable

    traverser = library[possibleLocation].begin(); // Begins at the beginning of the chained linked list

    while (traverser != library[possibleLocation].end()) {
        if (traverser->getBookTitle() == bookTitle) {
            //Book is already in the database!
            cout << "Book is already in the database!" << endl;
            return;
        }

        traverser++;
    }

    Book newBook(bookTitle, bookGenre, bookAuthor, bookSummary);

    library[possibleLocation].push_back(newBook); //Insert new bookTitle into the database
}

int Library::computeID(const string &bookTitle) {
    int hash = 0;
    for (char c : bookTitle) {
        hash += static_cast<int>(c);
    }
    return hash % size;
}


bool Library::bookSearch(const string &bookTitle) {
    int possibleLocation = computeID(bookTitle);

    list<Book>::iterator traverser;

    traverser = library[possibleLocation].begin(); // Begins at the beginning of the chained linked list

    while (traverser != library[possibleLocation].end()) {

    if (traverser->getBookTitle() == bookTitle) {
        traverser->displayInfo();
        return true;
    }
    traverser++;
}


    return false;
}