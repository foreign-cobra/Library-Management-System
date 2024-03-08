#include <gtest/gtest.h>
#include "header/book.h"
#include "header/user.h"
#include "header/library.h"
#include "header/userDatabase.h"

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
    EXPECT_FALSE(book.overdue());

    // Test when the book is overdue
    Date currentDate = Date::getCurrentDate();
    book = Book("Title", "Genre", "Author", "Summary");
    book.alterBorrowedDate(1,1,2022);
    EXPECT_TRUE(book.overdue());
}


TEST(UserTest, constructor1) {
    User* newUser = new User();
    EXPECT_EQ(newUser->getUsername(), "");
    EXPECT_EQ(newUser->getPassword(), "");
}

TEST(UserTest, constructor2) {
    User* newUser = new User("colin", "dog");
    EXPECT_EQ(newUser->getUsername(), "colin");
    EXPECT_EQ(newUser->getPassword(), "dog");
}

TEST(UserTest, changeUsername) {
    User* newUser = new User("colin", "dog");
    newUser->setUsername("blueberry123");
    EXPECT_EQ(newUser->getUsername(), "blueberry123");
    EXPECT_EQ(newUser->getPassword(), "dog");
}

TEST(UserTest, changePassword) {
    User* newUser = new User("colin", "dog");
    newUser->setPassword("hahaha499");
    EXPECT_EQ(newUser->getUsername(), "colin");
    EXPECT_EQ(newUser->getPassword(), "hahaha499");
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
}

TEST(UserDatabaseTest, testSearch) {
    userDatabase* users = new userDatabase();
    User* user1 = new User("colin", "test3123");
    User* user2 = new User("crunchy", "water");
    User* user3 = new User("banana", "monkey");
    users->addUser(user1);
    users->addUser(user2);
    users->addUser(user3);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
