#include "../header/settleFines.h"
#include <iostream>
#include <string>
#include <cctype> //to be able to use isdigit

using namespace std;

void PaymentProcessor::settleFine(double amount) {
    cout << "The total fine amount is $" << amount << ".\n";

    string creditCardNum;
    string expirationDate;
    string cvc;

    while (true) {
        cout << "Please enter your credit card number (16 digits): ";
        getline(cin, creditCardNum);
        if (!isValidCreditCardNum(creditCardNum)) {
            cout << "Invalid credit card number. Please try again.\n";
            continue;
        }

        cout << "Enter expiration date (MM/YY): ";
        getline(cin, expirationDate);
        if (!isValidExpirationDate(expirationDate)) {
            cout << "Invalid expiration date. Please try again.\n";
            continue;
        }

        cout << "Enter CVC (3 digits): ";
        getline(cin, cvc);
        if (!isValidCVC(cvc)) {
            cout << "Invalid CVC. Please try again.\n";
            continue;
        }

        break; // All inputs are valid
    }

    cout << "Processing payment...\n";
    cout << "Payment successful. Your fine has been settled.\n";
}

bool PaymentProcessor::isValidCreditCardNum(const string& number) {
    if (number.length() != 16) { 
        return false;
    }

    for (char c : number) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true; 
}

bool PaymentProcessor::isValidExpirationDate(const string& date) {
    if (date.length() != 5 || date[2] != '/') {
        return false;
    }

    for (int i = 0; i < date.length(); ++i) {
        if (i == 2) continue; // Skip the slash
        if (!isdigit(date[i])) {
            return false;
        }
    }

    return true;
}

bool PaymentProcessor::isValidCVC(const string& cvc) {
    if (cvc.length() != 3) {
        return false;
    }

    for (char c : cvc) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
} 