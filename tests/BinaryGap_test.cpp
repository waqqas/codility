#include "BinaryGap.h"
#include "gtest/gtest.h"

#include <limits>
#include <utility>

template <typename TypeName> class BinaryGapTest : public testing::Test {
public:
  TypeName question;
};

using Solutions =
    ::testing::Types<Codility::BinaryGap<1>, Codility::BinaryGap<2>>;
TYPED_TEST_SUITE(BinaryGapTest, Solutions);

TYPED_TEST(BinaryGapTest, example1) {
  // Arrange
  int actual = -1;
  int expected = 5;

  // Act
  actual = this->question.solution(0x411);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, example2) {
  // Arrange
  int actual = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0xf);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, example3) {
  // Arrange
  int actual = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x20);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, extremes_min) {
  // Arrange
  int actual = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x01);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, extremes_max) {
  // Arrange
  int actual = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(std::numeric_limits<int>::max());

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, trailing_zeros_one) {
  // Arrange
  int actual = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(6);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, trailing_zeros_two) {
  // Arrange
  int actual = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(328);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, power_of_2_one) {
  // Arrange
  int actual = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(5);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, power_of_2_two) {
  // Arrange
  int actual = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x10);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, power_of_2_three) {
  // Arrange
  int actual = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x400);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, simple1_one) {
  // Arrange
  int actual = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(0x9);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, simple1_two) {
  // Arrange
  int actual = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(0xA);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, simple2_one) {
  // Arrange
  int actual = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(19);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, simple2_two) {
  // Arrange
  int actual = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(42);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, simple3_one) {
  // Arrange
  int actual = -1;
  int expected = 3;

  // Act
  actual = this->question.solution(1162);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, simple3_two) {
  // Arrange
  int actual = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(5);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, medium1_one) {
  // Arrange
  int actual = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(51712);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, medium1_two) {
  // Arrange
  int actual = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(20);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, medium2_one) {
  // Arrange
  int actual = -1;
  int expected = 3;

  // Act
  actual = this->question.solution(561892);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, medium2_two) {
  // Arrange
  int actual = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(9);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, medium3_one) {
  // Arrange
  int actual = -1;
  int expected = 9;

  // Act
  actual = this->question.solution(66561);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, large_one) {
  // Arrange
  int actual = -1;
  int expected = 20;

  // Act
  actual = this->question.solution(6291457);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, large_two) {
  // Arrange
  int actual = -1;
  int expected = 4;

  // Act
  actual = this->question.solution(74901729);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, large_three) {
  // Arrange
  int actual = -1;
  int expected = 25;

  // Act
  actual = this->question.solution(805306373);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, large_four) {
  // Arrange
  int actual = -1;
  int expected = 5;

  // Act
  actual = this->question.solution(1376796946);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, large_five) {
  // Arrange
  int actual = -1;
  int expected = 29;

  // Act
  actual = this->question.solution(1073741825);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(BinaryGapTest, large_six) {
  // Arrange
  int actual = -1;
  int expected = 28;

  // Act
  actual = this->question.solution(1610612737);

  // Assert
  EXPECT_EQ(actual, expected);
}
