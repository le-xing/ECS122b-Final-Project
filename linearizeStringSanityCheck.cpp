#include <algorithm>
#include <random>
#include <string>
#include <iostream>

#include "linearizeString.h"
#include "gtest/gtest.h"

using testing::Test;

#define NUM_TEST_CASES 100
#define RANDOM_STRING_SIZE 20

TEST(LinearizeStringSanityCheck, SmallestLexicalString) {
    const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
    std::default_random_engine generator;
    std::uniform_int_distribution<int> letterDistribution(0, 25);
    std::uniform_int_distribution<int> shiftDistribution(1, RANDOM_STRING_SIZE - 1);
    for (int i = 0; i < NUM_TEST_CASES; i++) {
        std::string T = "";
        std::string initial;
        for (int j = 0; j < RANDOM_STRING_SIZE; j++) {
            T.push_back('a' + letterDistribution(generator));
        }

        initial = linearizeString(T);
        std::rotate(T.begin(), T.begin() + shiftDistribution(generator), T.end());
        std::string shift = linearizeString(T);
        EXPECT_EQ(initial, shift);
    }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
