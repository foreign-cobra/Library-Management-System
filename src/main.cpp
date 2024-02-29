#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "../header/helper.h"
#include "../header/termcolor.hpp"
#include "../header/library.h"
#include "../header/book.h"
#include "../header/userDatabase.h"


using namespace std;


int main(int /*argc*/, char ** /*argv*/) {
    Library database(11);
    userDatabase accounts(1);
                                                        // First, we must create our database
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
        throw runtime_error("ERROR: Couldn't open file :(");        //Run time error in case file does not open
    }
    }

    catch(const exception& error) {
        cout << error.what() << endl;
    }

    // Then, the actual program must begin

    int warningMessage = 0;
    char userInput;

    bool userContinue = true;

    createAccount(); //This createAccount is supposed to return a pointer to the account that was just created. 

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
                        break;
                    }
                    case '2':
                    {   
                        // TODO: Output list of borrowed books
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

                        bool bookFound = database.bookSearch(bookFind);

                        if (bookFound) {
                            // TODO: Display Book Page and the appropriate options for borrowing
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
    cout << "\033[0m\n\n\n\n\n\n\n\n\n\n";

    string EndOfProgram = "Program has been terminated";
    centerText(EndOfProgram, 160);
    cout << "\n\n\n\n\n\n\n\n\n\n\n";

    return 0;
}