#include "buildTree.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <random>
#include <string>

using testing::Test;

#define NUM_TEST_CASES 1000
#define RANDOM_STRING_SIZE 100

// Sanity check for suffix tree matching based on 3rd party code
TEST(SuffixTreeSanityCheck, SubstringMatchesInRandomString) {
    const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
    std::default_random_engine generator;
    std::uniform_int_distribution<int> letterDistribution(0, 25);
    std::uniform_int_distribution<int> substringDistribution(1, RANDOM_STRING_SIZE);
    for (int i = 0; i < NUM_TEST_CASES; i++) {
        std::string T = "";
        // Generate a random string of size RANDOM_STRING_SiZE
        for (int j = 0; j < RANDOM_STRING_SIZE; j++) {
            T.push_back('a' + letterDistribution(generator));
        }
        // Get a random substring from the random string
        int start = substringDistribution(generator);
        int end = substringDistribution(generator);
        if (start > end) {
            std::swap(start, end);
        }
        std::string P = "" + T.substr(start, end);
        // Build the suffix tree and check that the substring can be found in it
        suffixTree tree = buildTree(T);
        EXPECT_TRUE(search(P, tree));
    }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
