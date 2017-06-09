#include "buildTree.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <random>
#include <string>

using testing::Test;

#define NUM_TEST_CASES 1000
#define RANDOM_STRING_SIZE 100
#define RANDOM_SUBSTRING_SIZE 8

TEST(LCSTwoStringsSanityCheck, LCSTwoStringsRandom) {
  const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
  std::default_random_engine generator;
  std::uniform_int_distribution<int> letterDistribution(0, 25);
  std::uniform_int_distribution<int> shiftDistribution(0, RANDOM_STRING_SIZE);
  for (int i = 0; i < NUM_TEST_CASES; i++) {
    std::string S1 = "";
    std::string S2 = "";
    for (int j = 0; j < RANDOM_STRING_SIZE; j++) {
      S1.push_back('a' + letterDistribution(generator));
      S2.push_back('a' + letterDistribution(generator));
    }
    std::string CS = "";
    for (int j = 0; j < RANDOM_SUBSTRING_SIZE; j++) {
      CS.push_back('a' + letterDistribution(generator));
    }
    S1.insert(shiftDistribution(generator), CS);
    S2.insert(shiftDistribution(generator), CS);
    std::string LCS = LCSTwoStrings(S1, S2);
    EXPECT_GE(LCS.length(), CS.length());
  }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}