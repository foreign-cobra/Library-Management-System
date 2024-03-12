#include "../header/userFines.h"
#include "../header/book.h"
#include <iostream>

using namespace std;


const double UserFines::FINE_PER_DAY = 0.75;

// Constructor definition (if needed for further implementation)
UserFines::UserFines() {}

// Calculates fine based on the borrowed date
double UserFines::calculateFine(const Date& borrowedDate) {
    Date currentDate = Date::getCurrentDate(); 
    int daysDifference = currentDate - borrowedDate;
    int daysOverdue = daysDifference - DUE_DAYS;

    if (daysOverdue > 0) {
        return daysOverdue * FINE_PER_DAY;
    } else {
        return 0.0; // No fine if not overdue
    }
}