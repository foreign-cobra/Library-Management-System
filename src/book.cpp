#include "book.h"

using namespace std;

Book::Book(){
    string bookTitle = ""
    string bookGenre = ""
    string bookAuthor = ""
    string bookSummary = ""
    bool bookStatus = true;
}

Book::Book(const string &bookTitle, const string &bookGenre, const string &bookAuthor, const string &bookSummary){
    string bookTitle = bookTitle;
    string bookGenre = bookGenre;
    string bookAuthor = bookAuthor;
    string bookSummary = bookSummary;
    bool bookStatus = true;
}
string Book::getBookTitle()
{
    return bookTitle;
}

string Book::getBookGenre()
{
    return bookGenre;
}

string Book::getBookAuthor()
{
    return bookAuthor;
}

string Book::getBookSummary()
{
    return bookSummary;
}

bool Book::getStatus()
{
    return bookStatus;
}