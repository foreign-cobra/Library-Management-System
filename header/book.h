#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <list>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    static Date testCurrentDate; // Static member declaration
    static bool useTestDate; // Static flag declaration

    Date() : day(0), month(0), year(0) {} // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {} // Constructor with parameters

    static Date getCurrentDate();
    static void setTestCurrentDate(int d, int m, int y);
    static void resetToCurrentDate();
    void outputCurrentDate(); //Outputs the current date of the Date objecct
    int operator-(const Date& other) const; // Difference operator
    Date operator=(const Date& other); // Assignment operator
};


class Book
{
private:
    string bookTitle;
    string bookGenre;
    string bookAuthor;
    string bookSummary;
    string bookOwner;
    bool bookStatus; //true == open, false == taken
    Date borrowedDate; //Contains the date that a user first borrowed the book

public:
    Book();
    Book(const string &bookTitle, const string &bookGenre, const string &bookAuthor, const string &bookSummary);
    string getBookTitle();
    string getBookGenre();
    string getBookAuthor();
    string getBookSummary();
    Date getBorrowedDate();
    void displayInfo();
    bool getStatus();
    void setStatus(bool status);
    bool overdue();
    void alterBorrowedDate(int d, int m, int y); //I made this for testing, we can get rid of it later if we want to
    void setCurrentBorrower(const string& bookOwner);
    string getCurrentBorrower(); 
    void setBorrowedDate(const Date& borrowedDate);
    Date getBorrowedDate(const Date& borrowedDate);
};

#endif