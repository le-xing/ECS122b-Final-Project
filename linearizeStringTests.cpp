#include <string>
#include <algorithm>

#include "linearizeString.h"
#include "gtest/gtest.h"

using testing::Test;

TEST(LinearizeStringTest, ReturnStringLengthTest) {
    std::string S1 = "abc";
    std::string S2 = "cbbcbb";
    std::string L1 = linearizeString(S1);
    std::string L2 = linearizeString(S2);
    EXPECT_EQ(S1.length(), L1.length());
    EXPECT_EQ(S2.length(), L2.length());
}

TEST(LinearizeStringTest, SameContentsStringTest) {
    std::string S = "btsynwa";
    std::string L = linearizeString(S);
    std::sort(S.begin(), S.end());
    std::sort(L.begin(), L.end());
    EXPECT_EQ(S, L);
}

TEST(LinearizeStringTest, LinearizeSmallStringTest) {
    std::string S = "zxyabc";
    std::string L = linearizeString(S);
    EXPECT_EQ("abczxy", L);
}

TEST(LinearizeStringTest, LinearizeLargeStringTest) { 
    std::string S = "erhoqnqidfaqiwblzdfiwnlkndfirncoq";
    std::string L = linearizeString(S);
    EXPECT_EQ("aqiwblzdfiwnlkndfirncoqerhoqnqidf", L);
}    

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

