#include <iostream>
#include <iomanip>
#include <fstream>
#include "../header/helper.h"
#include "../header/termcolor.hpp"
#include "../header/library.h"
#include "../header/book.h"
#include "../header/userDatabase.h"

using namespace std;

int main() {
    Library database(11);                               // First, we must create our database                          
    userDatabase* userList = new userDatabase();        // Then, we create our user account list

    try {
    ifstream databaseFile;
    databaseFile.open("database.txt");                  // We must first open our database file

    if (databaseFile.is_open()) {
        string newBookTitle;
        string newBookAuthor;
        string newBookGenre;
        string newBookSummary;
        string trashVariable;

        while(getline(databaseFile, newBookTitle, '|') &&
              getline(databaseFile, newBookAuthor, '|') &&
              getline(databaseFile, newBookGenre, '|') &&
              getline(databaseFile, newBookSummary)) {
            database.insert(newBookTitle, newBookAuthor, newBookGenre, newBookSummary);
        }
        databaseFile.close();
    }

    else {
        databaseFile.close();
        throw runtime_error("ERROR: Couldn't open database file :(");        //Run time error in case file does not open
    }
    }

    catch(const exception& error) {
        cout << error.what() << endl;
    }

    try {
        ifstream accountFile;
        accountFile.open("accounts.txt");

        if (accountFile.is_open()) {
            string userName;
            string passWord;
            while (getline(accountFile, userName, ',') &&
                   getline(accountFile, passWord)) {
                    User* newUser = new User(userName, passWord);
                    userList->addUser(newUser);
            }
        }
        else {
            accountFile.close();
            throw runtime_error("ERROR: Couldn't open database file :(");
        }
    }

    catch (const exception& error) {
        cout << error.what() << endl;
    }

    //Once we create the database, we need to get our user logged in!
    int warningMessage = 0;
    char userInput;
    bool userContinue = true;
    User* newUser;
    string beginPrompt = "************************* Library Management System *************************";
    string createaccount = "I --- Create an Account --- I";
    string signin = "II --- Sign In --- II";
    string exitProgram = "III --- Exit Program --- III"; 

    do {
    cout << termcolor::yellow;
    centerText(beginPrompt, 160);
    cout << "\n\n";
    centerText(createaccount, 160);
    cout << "\n\n";
    centerText(signin, 160);
    cout << "\n\n";
    centerText(exitProgram, 160);
    cout << "\n\n";
    cout << termcolor::white;

    cin >> userInput;

    switch(userInput) {
        case '1':
        {

            newUser = userList->createAccount();
            userContinue = false;
            break;

        }
        case '2':
        {
            // User wants to log into an existing account
            newUser = userList->signIn();
            if (newUser != nullptr) {
                userContinue = false;
                break;
            }

            cout << termcolor::red;
            string SignInError = "ERROR: Either Username/Password was entered incorrectly!";
            centerText(SignInError, 160);
            cout << "\n\n\n";
            break;
        }
        default:
        {
            // User wants to exit the program
            return 0;
        }
    }
    } while (userContinue);



    // Then, the actual program must begin
    userContinue = true;

    do {
        outputMenu(warningMessage);
        cin >> userInput;

        switch(userInput) {
            case '1':
            {
                bool userContinueProfile = true;
                do {
                outputUserProfile(0);
                char userProfileInput;
                cin >> userProfileInput;

                switch(userProfileInput) {
                    case '1':
                    {
                        // TODO: Output Account Information
                        cout << "Username: " << newUser->getUsername() << endl;
                        cout << "Password: " << newUser->getUsername() << endl;
                        cout << "\n";
                        break;
                    }
                    case '2':
                    {   
                        // TODO: Output list of borrowed books
                        newUser->displayBooksOwned();
                        break;
                    }
                    case '3':
                    {
                        // TODO: View a list of book fines
                        break;
                    }

                    default:
                    {   
                        //User wants to exit
                        userContinueProfile = false;
                        break;

                    }
                }
                } while (userContinueProfile);

                warningMessage = 0;
                break;
            }
            case '2':
            {
                //TODO: Implement "search for book" function
                bool userContinueSearch = true;
                int searchType = 0;

                do {
                outputSearchMenu(searchType);
                char userSearchInput;
                cin >> userSearchInput;


                switch(userSearchInput) {
                    case '1':
                    {
                        // TODO: Call Search Function
                        cout << termcolor::yellow;
                        string searchInstructions = "Search for your book! (case-sensitive)\n\n";
                        centerText(searchInstructions, 160);
                        cout << termcolor::white;
                        string titleLookUp = "Title: ";
                        centerText(titleLookUp, 160);
                        string bookFind;
                        cin.ignore();
                        getline(cin, bookFind);
                        cout << "\n\n";

                        Book* bookFound = database.bookSearch(bookFind);

                        if (bookFound != nullptr) {
                            // TODO: Display Book Page and the appropriate options for borrowing
                            bookFound->displayInfo();
                            string borrowBook = "I --- Borrow Book --- I";
                            string returnBook = "II --- Return Book --- II";
                            string exitBookMenu = "III --- Exit to Search Menu --- III";
                            centerText(borrowBook, 160);
                            cout << "\n\n";
                            centerText(returnBook, 160);
                            cout << "\n\n";
                            centerText(exitBookMenu, 160);
                            cout << "\n\n";

                            cin >> userInput;

                            switch(userInput) {
                                case '1':
                                {
                                    newUser->borrowBook(bookFound);
                                    break;
                                }
                                case '2':
                                {
                                    // Return book function needed
                                    break;
                                }
                                default:
                                {
                                    //User wants to exit, do nothing
                                    break;
                                }
                            }
                            
                        }

                        else {
                            cout << termcolor::red;
                            string errorBook = "No books found in the database, please try again!";
                            centerText(errorBook, 160);
                            cout << "\n\n" << termcolor::reset;
                        }
                        break;
                    }
                    case '2':
                    {   
                        // TODO: Call Add Book Function
                        break;
                    }

                    default:
                    {
                        // Do nothing, user wants to return to the main menu
                        userContinueSearch = false;
                        break;
                    }
                }
                } while (userContinueSearch);


                warningMessage = 0;
                break;
            }
            case '3':
            {   
                warningMessage = 0;
                break;
            }
            case '4':
            {
                if (userList->isAdmin(newUser)) {
                    userList->displayAllUsers();
                }

                else {
                    cout << termcolor::red;
                    string adminWarning = "You do not have permission to do that!";
                    cout << "\n\n";
                    centerText(adminWarning, 160);
                    cout << "\n\n";
                    cout << termcolor::reset;
                }
                warningMessage = 0;
                break;
            }
            case '5':
            {   
                //signInOrCreate();
                warningMessage = 0;
                break;
            }
            case '6':
            {  
                userContinue = false; 
                warningMessage = 0;
                break;
            }
    
            default:
            {
                warningMessage = 1;
                break;
            }
        }

    } while (userContinue);

    //Reset back to normal color. 
    delete newUser; //testing

    cout << termcolor::reset;

    string EndOfProgram = "Program has been terminated";
    centerText(EndOfProgram, 160);
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    return 0;
}