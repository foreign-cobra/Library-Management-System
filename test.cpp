#include <gtest/gtest.h>
#include "header/book.h"
#include "header/user.h"

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
