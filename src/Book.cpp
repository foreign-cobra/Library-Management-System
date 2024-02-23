#include "../include/Book.h"

using namespace std;

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