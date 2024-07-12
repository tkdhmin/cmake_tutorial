#include "factorial.h"
#include <gtest/gtest.h>
#include <iostream>

// Tests factorial of zero.
TEST(FactorialTest, Zero) {EXPECT_EQ(1, factorial(0));}
TEST(FactorialTest, Positive_number){
    EXPECT_EQ(1, factorial(1));
    EXPECT_EQ(2, factorial(2));
    EXPECT_EQ(6, factorial(3));
    EXPECT_EQ(40320, factorial(8));
}

// Tests factorial of positive numbers.

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}