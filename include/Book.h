#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Book
{

private:
	string bookTitle;
	string bookGenre;
	string bookAuthor;
	string bookSummary;
	bool bookStatus;

public:
	Book();
	Book(const string &bookTitle, const string &bookGenre, const string &bookAuthor, const string &bookSummary, bool bookStatus);
	string getBookTitle();
	string getBookGenre();
	string getBookAuthor();
	string getBookSummary();
	bool getStatus();
	bool overdue();

private:
	int computeHash(const string &stringWord);
};

#endif