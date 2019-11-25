#include "BinarySearch.h"
#include "gtest/gtest.h"

#include <limits>
#include <utility>
#include <array>

using namespace Codility;

template <typename TypeName>
class BinarySearchTest : public testing::Test {
  public:
    TypeName algo;
};

using Solutions = ::testing::Types<BinarySearch<std::array<int32_t, 64>, Implemenation::StdAlgo>,
                                   BinarySearch<std::array<int32_t, 64>, Implemenation::Intrinsics>>;
TYPED_TEST_SUITE(BinarySearchTest, Solutions);

TYPED_TEST(BinarySearchTest, search_list_of_size_1)
{
    auto result = this->algo.search(0);

    EXPECT_EQ(result, true);
}