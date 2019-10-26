#include "StrSymmetryPoint.h"
#include "gtest/gtest.h"

#include <string>
#include <utility>

template <typename TypeName> class StrSymmetryPointTest : public testing::Test {
public:
  TypeName question;
};

using Solutions = ::testing::Types<Codility::StrSymmetryPoint<1>>;
TYPED_TEST_SUITE(StrSymmetryPointTest, Solutions);

TYPED_TEST(StrSymmetryPointTest, valid1) {
  // Arrange
  int actual = -1;
  int expected = 3;
  std::string input("racecar");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(StrSymmetryPointTest, single_letter) {
  // Arrange
  int actual = -1;
  int expected = 0;
  std::string input("x");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(StrSymmetryPointTest, empty) {
  // Arrange
  int actual = -1;
  int expected = -1;
  std::string input("");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(StrSymmetryPointTest, last_char_mismatch) {
  // Arrange
  int actual = -1;
  int expected = -1;
  std::string input("radecar");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(StrSymmetryPointTest, first_char_mismatch) {
  // Arrange
  int actual = -1;
  int expected = -1;
  std::string input("aacecar");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(StrSymmetryPointTest, middle_char_mismatch) {
  // Arrange
  int actual = -1;
  int expected = -1;
  std::string input("rbcecar");

  // Act
  actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}