#include "gtest/gtest.h"
#include "solutions.h"

#include <limits>
#include <utility>

template <typename TypeName>
class SolutionTest : public testing::Test
{
public:
  TypeName question;
};

using Solutions = ::testing::Types<Codility::BinaryGap<1>, Codility::BinaryGap<2>>;
TYPED_TEST_SUITE(SolutionTest, Solutions);

TYPED_TEST(SolutionTest, example1)
{
  // Arrange
  int actual   = -1;
  int expected = 5;

  // Act
  actual = this->question.solution(0x411);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, example2)
{
  // Arrange
  int actual   = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0xf);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, example3)
{
  // Arrange
  int actual   = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x20);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, extremes_min)
{
  // Arrange
  int actual   = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x01);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, extremes_max)
{
  // Arrange
  int actual   = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(std::numeric_limits<int>::max());

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, trailing_zeros_one)
{
  // Arrange
  int actual   = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(6);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, trailing_zeros_two)
{
  // Arrange
  int actual   = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(328);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, power_of_2_one)
{
  // Arrange
  int actual   = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(5);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, power_of_2_two)
{
  // Arrange
  int actual   = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x10);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, power_of_2_three)
{
  // Arrange
  int actual   = -1;
  int expected = 0;

  // Act
  actual = this->question.solution(0x400);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, simple1_one)
{
  // Arrange
  int actual   = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(0x9);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, simple1_two)
{
  // Arrange
  int actual   = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(0xA);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, simple2_one)
{
  // Arrange
  int actual   = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(19);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, simple2_two)
{
  // Arrange
  int actual   = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(42);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, simple3_one)
{
  // Arrange
  int actual   = -1;
  int expected = 3;

  // Act
  actual = this->question.solution(1162);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, simple3_two)
{
  // Arrange
  int actual   = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(5);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, medium1_one)
{
  // Arrange
  int actual   = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(51712);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, medium1_two)
{
  // Arrange
  int actual   = -1;
  int expected = 1;

  // Act
  actual = this->question.solution(20);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, medium2_one)
{
  // Arrange
  int actual   = -1;
  int expected = 3;

  // Act
  actual = this->question.solution(561892);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, medium2_two)
{
  // Arrange
  int actual   = -1;
  int expected = 2;

  // Act
  actual = this->question.solution(9);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, medium3_one)
{
  // Arrange
  int actual   = -1;
  int expected = 9;

  // Act
  actual = this->question.solution(66561);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, large_one)
{
  // Arrange
  int actual   = -1;
  int expected = 20;

  // Act
  actual = this->question.solution(6291457);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, large_two)
{
  // Arrange
  int actual   = -1;
  int expected = 4;

  // Act
  actual = this->question.solution(74901729);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, large_three)
{
  // Arrange
  int actual   = -1;
  int expected = 25;

  // Act
  actual = this->question.solution(805306373);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, large_four)
{
  // Arrange
  int actual   = -1;
  int expected = 5;

  // Act
  actual = this->question.solution(1376796946);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, large_five)
{
  // Arrange
  int actual   = -1;
  int expected = 29;

  // Act
  actual = this->question.solution(1073741825);

  // Assert
  EXPECT_EQ(actual, expected);
}

TYPED_TEST(SolutionTest, large_six)
{
  // Arrange
  int actual   = -1;
  int expected = 28;

  // Act
  actual = this->question.solution(1610612737);

  // Assert
  EXPECT_EQ(actual, expected);
}
