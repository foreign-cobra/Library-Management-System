#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <list>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    // Constructor to initialize the date
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void displayDate(){
        cout << day << "/" << month << "/" << year << endl;
    }
    // Function to get current date
    static Date getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
    }
};
class Book
{

private:
    string bookTitle;
    string bookGenre;
    string bookAuthor;
    string bookSummary;
    Date borrowedDate;
    bool bookStatus; //true == open, false == taken

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
    bool overdue();
    void alterBorrowedDate(int d, int m, int y); //I made this for testing, we can get rid of it later if we want to
};

#endif
