#ifndef HELPER_HPP_
#define HELPER_HPP_

#include <string>
#include "../header/user.h"


void outputMenu(const int errorNum); //Outputs the main menu of our Library Management System with a param to determine if there was an error
void outputUserProfile(const int errorNum); // Outputs the menu for the User Profile screen
void outputUserInformation(); // Outputs the information for of the current user
void outputSearchMenu(const int errorNum); // Outputs the menu for searching or adding a new book
void centerText(const std::string& text, int terminalWidth); //Accepts a string and an int to center the text in the terminal
void simpleMenu(); // Outputs the standard LMS header
User* loginLayout();

#endif // HELPER_HPP_