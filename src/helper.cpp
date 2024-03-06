#include <iostream>
#include <iomanip>
#include <string>
#include "../header/helper.h"
#include "../header/user.h"
#include "../header/termcolor.hpp"

using namespace std;

void outputMenu(const int errorNum) {
    // Output standard title with proper text color
    int terminalWidth = 160;
    cout << termcolor::blue;
    cout << "\n\n";

    for (int i = 0; i < 42; i++) {
        cout << " ";
    }

    for (int i = 0; i < 25; i++) {
        cout << "*";
    }

    cout << "\033[1m LibraryManagementSystem \033[0m";

    cout << termcolor::blue;

    for (int i = 0; i < 25; i++) {
        cout << "*";
    }
    cout << "\n\n\n";

    switch (errorNum) {

    case 0:
        {
        // Output build message
        cout << termcolor::yellow;
        string warning = "⚠ Warning, this application is still in development. More features will be added soon. ⚠";
        centerText(warning, terminalWidth);
        break;
        }

    case 1:
        // Output error message, user entered an invalid value
        {
        cout << termcolor::yellow;
        string invalidWarning = "⚠ ERROR: Invalid value was entered! ⚠";
        centerText(invalidWarning, terminalWidth);
        } break;
        

    default:
        {
        // No output
        } break;     
    }

    cout << "\n\n\n";
    string instructions = "Please select a number between 1-7 and hit the enter key to continue.";
    centerText(instructions, terminalWidth);

    cout << termcolor::blue << termcolor::bold << "\n\n\n";
    string signIn = "I --- User Profile --- I";
    centerText(signIn, terminalWidth);

    cout << "\n\n\n";
    string createSign = "II ---Search For Book --- II";
    centerText(createSign, terminalWidth);

    cout << "\n\n\n";
    string returnBorrow = "III --- Settle Fines --- III";
    centerText(returnBorrow, terminalWidth);

    cout << "\n\n\n";
    string addNew = "IV --- See List of Accounts --- IV";
    centerText(addNew, terminalWidth);

    cout << "\n\n\n";
    string settleMoney = "V --- Sign Out --- V";
    centerText(settleMoney, terminalWidth);

    cout << "\n\n\n";
    string recommendBook = "VI --- Exit Application --- VI";
    centerText(recommendBook, terminalWidth);
    cout << "\n";
}

void outputUserProfile(const int errorNum) {

    cout << termcolor::white << "\n\n";

    string userProfile = "********** User Profile **********";
    centerText(userProfile, 160); 
    cout << termcolor::yellow << "\n\n\n";

    switch (errorNum) {

    case 0:
        {
        // Output standard message
        string standardText = "Select an action and hit enter to continue";
        centerText(standardText, 160);
        break;
        }

    case 1:
        // Output error message, user entered an invalid value
        {
        cout << termcolor::yellow;
        string invalidWarning = "⚠ ERROR: Invalid value was entered! ⚠";
        centerText(invalidWarning, 160);
        } break;
        

    default:
        {
        // No output
        } break;     
    }

    cout << termcolor::blue << termcolor::bold << "\n\n\n";
    string accountInfo = "I --- Account Info --- I";
    centerText(accountInfo, 160);

    cout << "\n\n\n";
    string listBooks = "II --- List of Borrowed Books --- II";
    centerText(listBooks, 160);

    cout << "\n\n\n";
    string settleFines = "III --- Book Fines --- III";
    centerText(settleFines, 160);

    cout << "\n\n\n";
    string mainMenu = "IV --- Main Menu --- IV";
    centerText(mainMenu, 160);

    cout << "\n\n\n";
    
}

void outputSearchMenu(const int errorNum) {
    cout << termcolor::white << termcolor::bold << "\n\n";

    string userProfile = "********** Search Books **********";
    centerText(userProfile, 160); 
    cout << termcolor::yellow << "\n\n\n";

    switch (errorNum) {

    case 0:
        {
        // Output standard message
        string standardText = "Select an action and hit enter to continue";
        centerText(standardText, 160);
        break;
        }

    case 1:
        // Output error message, user entered an invalid value
        {
        cout << termcolor::yellow;
        string invalidWarning = "⚠ ERROR: Invalid value was entered! ⚠";
        centerText(invalidWarning, 160);
        } break;
        

    default:
        {
        // No output
        } break;     
    }

    cout << termcolor::blue << termcolor::bold << "\n\n\n";
    string accountInfo = "I --- Look Up Book --- I";
    centerText(accountInfo, 160);

    cout << "\n\n\n";
    string listBooks = "II --- Add New Book --- II";
    centerText(listBooks, 160);

    cout << "\n\n\n";
    string settleFines = "III --- Main Menu --- III";
    centerText(settleFines, 160);

    cout << "\n\n\n";
}

void centerText(const string &text, int terminalWidth) {
    int textLength = static_cast<int>(text.length());

    if (textLength >= terminalWidth)
    {
        // If text is longer than terminal width, print it as is
        cout << text << endl;
    }
    else
    {
        int padding = (terminalWidth - textLength) / 2;
        // Print padding spaces followed by the text
        cout << setw(padding + textLength) << text;
    }
}

void simpleMenu() {
    int terminalWidth = 160;
    cout << termcolor::blue;
    cout << "\n\n\n";

    for (int i = 0; i < 42; i++) {
        cout << " ";
    }

    for (int i = 0; i < 25; i++) {
        cout << "*";
    }

    cout << "\033[1m LibraryManagementSystem \033[0m";

    cout << termcolor::blue;

    for (int i = 0; i < 25; i++) {
        cout << "*";
    }
    cout << "\n\n\n";
}

User* loginLayout() {
    int terminalWidth = 160;
    string username;
    string password;

    simpleMenu();
    cout << termcolor::yellow;
    string prompt1 = "--- Create An Account ---";
    string prompt2 = "Please enter a username: ";
    string prompt3 = "Please enter a password: ";
    string prompt4 = "Both your Username and Password must be at least 5 characters!";

    do {
    centerText(prompt4, terminalWidth);
    cout << "\n\n\n";
    centerText(prompt1, terminalWidth);
    cout << "\n\n\n";
    centerText(prompt2, terminalWidth);
    getline(cin, username);
    cout << "\n\n";
    centerText(prompt3, terminalWidth);
    getline(cin, password);

    cout  << "\n\n";

    } while((username.size() < 5) || (password.size() < 5)); 

    User* newUser = new User(username, password);

    return newUser;
}