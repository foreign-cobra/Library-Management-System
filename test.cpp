#include <gtest/gtest.h>
#include "header/book.h"

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
