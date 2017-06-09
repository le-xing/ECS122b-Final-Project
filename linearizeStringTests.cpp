#include <string>
#include <algorithm>

#include "linearizeString.h"
#include "gtest/gtest.h"

using testing::Test;

// Testing that the linearized string is the same length as the cut circular
// string
TEST(LinearizeStringTest, ReturnStringLengthTest) {
    std::string S1 = "abc";
    std::string S2 = "cbbcbb";
    std::string L1 = linearizeString(S1);
    std::string L2 = linearizeString(S2);
    EXPECT_EQ(S1.length(), L1.length());
    EXPECT_EQ(S2.length(), L2.length());
}

// Testing that the linearized string is made up of the same characters as the
// original string
TEST(LinearizeStringTest, SameContentsStringTest) {
    std::string S = "btsynwa";
    std::string L = linearizeString(S);
    std::sort(S.begin(), S.end());
    std::sort(L.begin(), L.end());
    EXPECT_EQ(S, L);
}

// Testing that the function returns the same string if the cut string is 
// already lexically smallest string
TEST(LinearizeStringTest, LinearizeSmallStringTest) {
    std::string S = "abcdef";
    std::string L = linearizeString(S);
    EXPECT_EQ(S, L);
}

// Testing that the string is linearized correctly
TEST(LinearizeStringTest, LinearizeStringTest) { 
    std::string S = "zyxabc";
    std::string L = linearizeString(S);
    EXPECT_EQ("abczyx", L);
}    

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

