#include "../include/Library.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

Library::Library(int defaultSize) {
    size = defaultSize;
    library = new list<string>[size];
}

Library::~Library() {
    // TODO: Implement appropriate destructor for the Library
}

void Library::insert(const string& bookTitle) {
    int possibleLocation = computeID(bookTitle);
    
    list<string>::iterator traverser; //Traverser that goes through the chained linked list at a specified index of the HashTable

    traverser = library[possibleLocation].begin(); // Begins at the beginning of the chained linked list

    while (traverser != library[possibleLocation].end()) {
        if (*traverser == bookTitle) {
            //Book is already in the database!
            return;
        }

        traverser++;
    }

    library[possibleLocation].push_back(bookTitle); //Insert new bookTitle into the database
}

int Library::computeID(const string &bookTitle) {
    int randomInt = 24; // Initialize our random integer to 24. 

    for (unsigned i = 0; i < bookTitle.size(); ++i) {
        int charConverter = bookTitle.at(i) - '0'; // By subtracting the character by an int, it converts it into its special integer. 
		randomInt = randomInt + charConverter; // Each character will have its own respective int. We will add them up so that each string can have differing numbers. 
    }
    
    return ((randomInt * 2) + size - 24) % size; // A strange but deterministic algorithm for computing the hash ID. 
}

bool Library::bookSearch(const string &bookTitle) {
    int possibleLocation = computeID(bookTitle);

    list<string>::iterator traverser;

    traverser = library[possibleLocation].begin(); // Begins at the beginning of the chained linked list

    while (traverser != library[possibleLocation].end()) {
        if (*traverser == bookTitle) {
            //Book is already in the database!
            return true;
        }

        traverser++;
    }

    return false;
}

void Library::outputDatabase() {
    for (int i = 0; i < size; ++i) {
        for (const std::string& book : library[i]) {
            std::cout << "Book: " << book << std::endl;
        }
    }
}



