#include "solutions.h"
#include "gtest/gtest.h"

#include <string>
#include <utility>

template <typename TypeName> class SolutionTest : public testing::Test {
public:
  TypeName question;
};

using Solutions = ::testing::Types<Codility::StrSymmetryPoint<1>,
                                   Codility::StrSymmetryPoint<2>>;
TYPED_TEST_SUITE(SolutionTest, Solutions);

TYPED_TEST(SolutionTest, valid1) {
  // Arrange
  int actual = -1;
  int expected = 3;

  // Act
  actual = this->question.solution(std::string("racecar"));

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, single_letter) {
  // Arrange
  int actual = -1;
  int expected = -1;

  // Act
  actual = this->question.solution(std::string("x"));

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, empty_string) {
  // Arrange
  int actual = -1;
  int expected = -1;

  // Act
  actual = this->question.solution(std::string(""));

  // Assert
  EXPECT_EQ(actual, expected);
}