#include "BinarySearch.h"
#include "gtest/gtest.h"

#include <array>
#include <limits>
#include <unordered_set>
#include <utility>

using namespace Codility;

template <typename TypeName>
class BinarySearchTest : public testing::Test {
  public:
    TypeName algo;
};

using Solutions
    = ::testing::Types<BinarySearch<std::array<int32_t, 64>, Implemenation::StdAlgo>,
                       BinarySearch<std::array<int32_t, 64>, Implemenation::Intrinsics>,
                       BinarySearch<std::array<int32_t, 64>, Implemenation::IntrinsicsImpl2>,
                       BinarySearch<std::unordered_set<int32_t>, Implemenation::UnorderedSet>>;
TYPED_TEST_SUITE(BinarySearchTest, Solutions);

TYPED_TEST(BinarySearchTest, search_list_of_size_1)
{
    auto result = this->algo.search(0);

    EXPECT_EQ(result, true);
}