#include "solutions.h"
#include "gtest/gtest.h"

template <typename TypeName> class SolutionTest : public testing::Test {
public:
  TypeName question;
};

using Solutions = ::testing::Types<Codility::SocksLaundering<1>>;
TYPED_TEST_SUITE(SolutionTest, Solutions);

TYPED_TEST(SolutionTest, valid1) {
  // Arrange
  int actual = -1;
  int expected = -1;

  // Act
  // actual = this->question.solution(input);

  // Assert
  EXPECT_EQ(actual, expected);
}
