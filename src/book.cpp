#include "../header/book.h"

using namespace std;

Date Date::testCurrentDate = Date(); // Initialize with default constructor
bool Date::useTestDate = false; // Initialize as false

// Static methods and operator- implementation
Date Date::getCurrentDate() {
    if (useTestDate) {
        return testCurrentDate;
    } else {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        return Date(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
    }
}

void Date::setTestCurrentDate(int d, int m, int y) {
    testCurrentDate = Date(d, m, y);
    useTestDate = true;
}

void Date::resetToCurrentDate() {
    useTestDate = false;
}

int Date::operator-(const Date& other) const {
    int thisDays = year * 365 + month * 30 + day;
    int otherDays = other.year * 365 + other.month * 30 + other.day;
    return abs(thisDays - otherDays);
}

Book::Book(){
    bookTitle = "";
    bookGenre = "";
    bookAuthor = "";
    bookSummary = "";
    bookStatus = true;
}

Book::Book(const string &bookTitle_, const string &bookGenre_, const string &bookAuthor_, const string &bookSummary_){
    bookTitle = bookTitle_;
    bookGenre = bookGenre_;
    bookAuthor = bookAuthor_;
    bookSummary = bookSummary_;
    bookStatus = true;
    borrowedDate = Date::getCurrentDate(); //TEMPORARY FOR TESTING IF DATE SYSTEM IS WORKING PROPERLY
}
string Book::getBookTitle(){
    return bookTitle;
}

string Book::getBookGenre(){
    return bookGenre;
}

string Book::getBookAuthor(){
    return bookAuthor;
}

string Book::getBookSummary(){
    return bookSummary;
}

bool Book::getStatus(){
    return bookStatus;
}
Date Book::getBorrowedDate(){
    return borrowedDate;
}
void Book::displayInfo(){
    cout << "Name: " << this->getBookTitle() << endl;
    cout << "Author: " << this->getBookAuthor() << endl;
    cout << "Genre: " << this->getBookGenre() << endl;
    cout << "Summary: " << this->getBookSummary() << endl;
    if(this->getStatus()){
        cout << "Available for borrowing" << endl;
    }else{
        cout << "Currently loaned out to other user" << endl;
    }
}
void Book::alterBorrowedDate(int d, int m, int y){
    borrowedDate = Date(d,m,y);
}
bool Book::overdue() {
    // Get the current date
    Date currentDate = Date::getCurrentDate();

    // Check if the current date is more than 30 days after the borrowed date
    if (currentDate.year > borrowedDate.year + 1) {
        return true;
    } else if (currentDate.year == borrowedDate.year + 1) {
        if (currentDate.month > borrowedDate.month) {
            return true;
        } else if (currentDate.month == borrowedDate.month) {
            if (currentDate.day > borrowedDate.day) {
                return true;
            }
        }
    }
    return false;
}