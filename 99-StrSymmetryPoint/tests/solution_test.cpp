#include "solutions.h"
#include "gtest/gtest.h"

#include <string>
#include <utility>

template <typename TypeName> class SolutionTest : public testing::Test {
public:
  TypeName question;
};

using Solutions = ::testing::Types<Codility::StrSymmetryPoint<1>>;
TYPED_TEST_SUITE(SolutionTest, Solutions);

TYPED_TEST(SolutionTest, valid1) {
  // Arrange
  int actual = -1;
  int expected = 3;
  std::string input("racecar");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, single_letter) {
  // Arrange
  int actual = -1;
  int expected = 0;
  std::string input("x");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, empty) {
  // Arrange
  int actual = -1;
  int expected = -1;
  std::string input("");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, invalid1) {
  // Arrange
  int actual = -1;
  int expected = -1;
  std::string input("radecar");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}