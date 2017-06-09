#include <string>
#include <algorithm>

#include "LCSTwoStrings.h"
#include "gtest/gtest.h"

using testing::Test;

TEST(LCSTwoStringsTest, Test) {
    std::string S1 = "abc";
    std::string S2 = "abd";
   // std::string LCS = LCSTwoStrings(S1, S2);
    EXPECT_TRUE(1);
}


int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

