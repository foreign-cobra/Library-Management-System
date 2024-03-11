#include <gtest/gtest.h>
#include "header/settleFines.h"
#include "header/book.h"
#include "header/user.h"
#include "header/library.h"
#include "header/userDatabase.h"
#include "header/userFines.h"

TEST(UserFinesTest, ReturnBeforeDueDate) {
    Date::setTestCurrentDate(10, 1, 2022); // Set "current" date for test
    Date borrowedDate(1, 1, 2022); // Borrowing date
    double fine = UserFines::calculateFine(borrowedDate);
    EXPECT_EQ(0.0, fine);
}

// Test returning a book on the due date (no fine should be applied)
TEST(UserFinesTest, ReturnOnDueDate) {
    Date::setTestCurrentDate(15, 1, 2022); // Assuming a 14-day borrowing period
    Date borrowedDate(1, 1, 2022); // Borrowing date
    double fine = UserFines::calculateFine(borrowedDate);
    EXPECT_EQ(0.0, fine);
}

// Test returning a book after the due date (a fine should be applied)
TEST(UserFinesTest, ReturnAfterDueDate) {
    Date::setTestCurrentDate(20, 1, 2022); // Set "current" date for test greater than 14 days from borrowed date
    Date borrowedDate(1, 1, 2022); // Borrowing date
    double fine = UserFines::calculateFine(borrowedDate);
    // Assuming the fine is calculated based on the number of days overdue
    EXPECT_GT(fine, 0.0);
}

// User class unit tests

TEST(BookTest, Constructor) {
    Book book("Title", "Genre", "Author", "Summary");
    EXPECT_EQ(book.getBookTitle(), "Title");
    EXPECT_EQ(book.getBookGenre(), "Genre");
    EXPECT_EQ(book.getBookAuthor(), "Author");
    EXPECT_EQ(book.getBookSummary(), "Summary");
    EXPECT_TRUE(book.getStatus());
}

TEST(BookTest, BorrowedDate) {
    Book book("Title", "Genre", "Author", "Summary"); //CONSTRUCTOR SETS BORROWED DATE TO TODAY
    Date currentDate = Date::getCurrentDate();
    Date borrowedDate = book.getBorrowedDate();
    EXPECT_EQ(borrowedDate.day, currentDate.day);
    EXPECT_EQ(borrowedDate.month, currentDate.month);
    EXPECT_EQ(borrowedDate.year, currentDate.year);
}

TEST(BookTest, Overdue) {
    Book book("Title", "Genre", "Author", "Summary");
    // EXPECT_FALSE(book.overdue());

    // Test when the book is overdue
    Date currentDate = Date::getCurrentDate();
    Date::setTestCurrentDate(1,1,2024);
    book = Book("Title", "Genre", "Author", "Summary");
    book.alterBorrowedDate(1,1,2022);
    EXPECT_TRUE(book.overdue());
}


TEST(UserTest, constructor1) {
    User* newUser = new User();
    EXPECT_EQ(newUser->getUsername(), "");
    EXPECT_EQ(newUser->getPassword(), "");
    delete newUser;
}

TEST(UserTest, constructor2) {
    User* newUser = new User("colin", "dog");
    EXPECT_EQ(newUser->getUsername(), "colin");
    EXPECT_EQ(newUser->getPassword(), "dog");
    delete newUser;
}

TEST(UserTest, changeUsername) {
    User* newUser = new User("colin", "dog");
    newUser->setUsername("blueberry123");
    EXPECT_EQ(newUser->getUsername(), "blueberry123");
    EXPECT_EQ(newUser->getPassword(), "dog");
    delete newUser;
}

TEST(UserTest, changePassword) {
    User* newUser = new User("colin", "dog");
    newUser->setPassword("hahaha499");
    EXPECT_EQ(newUser->getUsername(), "colin");
    EXPECT_EQ(newUser->getPassword(), "hahaha499");
    delete newUser;
}

TEST(UserTest, displayBooks) {
    User* newUser = new User("colin", "dog");
    Book* book1 = new Book("a", "b", "c", "d");
    Book* book2 = new Book ("e", "f", "g", "h");
    newUser->borrowBook(book1);
    newUser->borrowBook(book2);
    testing::internal::CaptureStdout();
    newUser->displayBooksOwned();
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1. a\n\n2. e\n\n");
    delete newUser;
}

// Insert and Search Tests

TEST(LibraryInsertTest, testEmpty) {
    Library database(5);
    EXPECT_FALSE(database.bookSearch("Cat in The Hat"));
}

TEST(LibraryInsertTest, testBasic) {
    Library database(5);
    database.insert("C", "A", "T", "S");
    EXPECT_TRUE(database.bookSearch("C"));
}

TEST(LibraryInsertTest, testAdvanced) {
    Library database(5);
    database.insert("C", "A", "T", "S");
    database.insert("B", "A", "A", "D");
    database.insert("F", "O", "U", "R");
    database.insert("C", "O", "L", "I");
    database.insert("D", "O", "O", "R");
    EXPECT_TRUE(database.bookSearch("F"));
    EXPECT_TRUE(database.bookSearch("C"));
    EXPECT_TRUE(database.bookSearch("B"));
    EXPECT_FALSE(database.bookSearch("Z"));
}

// Testing Compute ID

TEST(LibraryIDTest, testGeneral) {
    Library database(10);

    EXPECT_EQ(database.computeID("Balling"), 7);

}

TEST(LibraryIDTest, testBig) {
    Library database(100);

    EXPECT_EQ(database.computeID("HUGEBARGAINS"), 80);

}

TEST(LibraryIDTest, testGinormous) {
    Library database(1000);

    EXPECT_EQ(database.computeID("EVENBIGGER"), 734);
}

TEST(UserDatabaseTest, testAddUser) {
    userDatabase* users = new userDatabase();
    User* user1 = new User("colin", "test3123");
    User* user2 = new User("crunchy", "water");
    User* user3 = new User("banana", "monkey");
    users->addUser(user1);
    users->addUser(user2);
    users->addUser(user3);
    ASSERT_EQ(users->getSize(), 3);
    delete users;
}

TEST(UserDatabaseTest, testDisplayAcc) {
    userDatabase* users = new userDatabase();
    User* user1 = new User("colin", "test3123");
    User* user2 = new User("crunchy", "water");
    User* user3 = new User("banana", "monkey");
    users->addUser(user1);
    users->addUser(user2);
    users->addUser(user3);
    testing::internal::CaptureStdout();
    users->displayAllUsers();
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1. Username: colin\n\n2. Username: crunchy\n\n3. Username: banana\n\n");
    delete users;
}

TEST(UserDatabaseTest, testSearch) {
    userDatabase* users = new userDatabase();
    User* user1 = new User("colin", "test3123");
    User* user2 = new User("crunchy", "water");
    User* user3 = new User("banana", "monkey");
    users->addUser(user1);
    users->addUser(user2);
    users->addUser(user3);
    ASSERT_EQ(users->searchUser("crunchy"), user2);
    ASSERT_EQ(users->searchUser("crunchy", "water"), user2);
    delete users;
}

TEST(UserDatabaseTest, adminFail) {
    userDatabase* users = new userDatabase();
    User* user1 = new User("Admin2", "hackingsystem");
    ASSERT_FALSE(users->isAdmin(user1));
    delete user1;
    delete users;
}

TEST(UserDatabaseTest, adminPass) {
    userDatabase* users = new userDatabase();
    User* user1 = new User("Admin1", "cs100");
    ASSERT_TRUE(users->isAdmin(user1));
    delete user1;
    delete users;
}


TEST(SettleFinesTest, InvalidCreditCardNum) {
    PaymentProcessor processor;
    EXPECT_FALSE(processor.isValidCreditCardNum("1234"));
    EXPECT_FALSE(processor.isValidCreditCardNum("abcdefghijk"));
}

TEST(SettleFinesTest, ValidExpirationDate) {
    PaymentProcessor processor;
    EXPECT_TRUE(processor.isValidExpirationDate("12/34"));
}

TEST(SettleFinesTest, ValidCreditCardNum) {
    PaymentProcessor processor;
    EXPECT_TRUE(processor.isValidCreditCardNum("1234567890123456"));
}
   
TEST(SettleFinesTest, InvalidExpirationDate) {
    PaymentProcessor processor;
    EXPECT_FALSE(processor.isValidExpirationDate("123/45"));
    EXPECT_FALSE(processor.isValidExpirationDate("ab/cd"));
}

TEST(SettleFinesTest, ValidCVC) {
    PaymentProcessor processor;
    EXPECT_TRUE(processor.isValidCVC("123"));
}

TEST(SettleFinesTest, InvalidCVC) {
    PaymentProcessor processor;
    EXPECT_FALSE(processor.isValidCVC("12"));
    EXPECT_FALSE(processor.isValidCVC("abcd"));
}

// The main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
