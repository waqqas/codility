#include "SocksLaundering.h"
#include "gtest/gtest.h"

#include <vector>

template <typename TypeName>
class SocksLaundering : public testing::Test {
  public:
    TypeName question;
};

using Solutions = ::testing::Types<Codility::SocksLaundering<1>>;
TYPED_TEST_SUITE(SocksLaundering, Solutions);

TYPED_TEST(SocksLaundering, single_pair_of_clean_socks)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 1;
    typename TypeParam::sock_list clean = {1, 1};
    typename TypeParam::sock_list dirty;

    // Act
    actual = this->question.solution(0, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, two_pairs_of_clean_socks)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 2;
    typename TypeParam::sock_list clean = {1, 2, 1, 2};
    typename TypeParam::sock_list dirty;

    // Act
    actual = this->question.solution(0, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, one_mismatch_in_clean_socks)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 2;
    typename TypeParam::sock_list clean = {1, 3, 2, 1, 2};
    typename TypeParam::sock_list dirty;

    // Act
    actual = this->question.solution(0, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, one_match_in_dirty_socks)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 1;
    typename TypeParam::sock_list clean = {1};
    typename TypeParam::sock_list dirty = {1};

    // Act
    actual = this->question.solution(1, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, one_clean_and_one_dirty_pair)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 2;
    typename TypeParam::sock_list clean = {1, 1, 2};
    typename TypeParam::sock_list dirty = {2};

    // Act
    actual = this->question.solution(1, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, two_matches_in_dirty_socks)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 2;
    typename TypeParam::sock_list clean = {1, 2};
    typename TypeParam::sock_list dirty = {1, 2};

    // Act
    actual = this->question.solution(2, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, honor_max_wash)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 1;
    typename TypeParam::sock_list clean = {1, 2};
    typename TypeParam::sock_list dirty = {1, 2};

    // Act
    actual = this->question.solution(1, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, example)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 3;
    typename TypeParam::sock_list clean = {1, 2, 1, 1};
    typename TypeParam::sock_list dirty = {1, 4, 3, 2, 4};

    // Act
    actual = this->question.solution(2, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}

TYPED_TEST(SocksLaundering, two_dirty_pairs_less_washable)
{
    // Arrange
    typename TypeParam::pair_count actual = -1;
    typename TypeParam::pair_count expected = 1;
    typename TypeParam::sock_list clean = {};
    typename TypeParam::sock_list dirty = {1, 4, 1, 2, 4};

    // Act
    actual = this->question.solution(2, clean, dirty);

    // Assert
    EXPECT_EQ(actual, expected);
}