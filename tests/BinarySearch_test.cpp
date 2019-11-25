#include "BinarySearch.h"
#include "gtest/gtest.h"

#include <limits>
#include <utility>

using namespace Codility;

template <typename TypeName>
class BinarySearchTest : public testing::Test {
  public:
    TypeName algo;
};

using Solutions = ::testing::Types<BinarySearch<64, int32_t, Implemenation::StdAlgo>,
                                   BinarySearch<64, int32_t, Implemenation::Intrinsics>,
                                   BinarySearch<64, int32_t, Implemenation::UnorderedSet>
                                   // BinarySearch<1024, int32_t, Implemenation::Intrinsics>
                                   >;
TYPED_TEST_SUITE(BinarySearchTest, Solutions);

TYPED_TEST(BinarySearchTest, search_list_of_size_1)
{
    auto result = this->algo.search(0);

    EXPECT_EQ(result, true);
}