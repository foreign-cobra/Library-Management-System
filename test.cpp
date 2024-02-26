#include <gtest/gtest.h>
#include "header/book.h"
#include "header/user.h"
#include "header/library.h"

// User class unit tests

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


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
