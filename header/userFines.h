#ifndef USERFINES_H
#define USERFINES_H

#include "book.h"
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

class UserFines {
private:
    static const int DUE_DAYS = 14; // Days allowed before fines start
    static const double FINE_PER_DAY; // Fine amount per day after due date

public:
    // Constructor
    UserFines();

    // Calculates fine for an overdue book
    static double calculateFine(const Date& borrowedDate);
};

#endif 