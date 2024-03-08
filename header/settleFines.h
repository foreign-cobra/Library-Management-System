#ifndef SETTLEFINES_H
#define SETTLEFINES_H

#include <iostream>
#include <string>
#include <cctype> 

using namespace std;


class PaymentProcessor { 

public:
    void settleFine(double amount);
    bool isValidCreditCardNum(const string& number);
    bool isValidExpirationDate(const string& date);
    bool isValidCVC(const string& cvc);
};

#endif