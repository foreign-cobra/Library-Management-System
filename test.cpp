#include <gtest/gtest.h>
#include "header/settleFines.h"

TEST(SettleFinesTest, ValidCreditCardNum) {
    PaymentProcessor processor;
    EXPECT_TRUE(processor.isValidCreditCardNum("1234567890123456"));
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
