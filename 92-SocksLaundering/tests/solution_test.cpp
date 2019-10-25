#include "solutions.h"
#include "gtest/gtest.h"

#include <vector>

template <typename TypeName> class SolutionTest : public testing::Test {
public:
  TypeName question;
};

using Solutions = ::testing::Types<Codility::SocksLaundering<1>>;
TYPED_TEST_SUITE(SolutionTest, Solutions);

TYPED_TEST(SolutionTest, example) {
  // Arrange
  typename TypeParam::pair_count actual = -1;
  typename TypeParam::pair_count expected = 3;
  std::vector clean = {1, 2, 1, 1};
  std::vector dirty = {1, 4, 3, 2, 4};

  // Act
  actual = this->question.solution(2, clean, dirty);

  // Assert
  EXPECT_EQ(actual, expected);
}


