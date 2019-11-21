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

using Solutions = ::testing::Types<BinarySearch<Implemenation::StdAlgo>,
                                   BinarySearch<Implemenation::Intrinsics>>;
TYPED_TEST_SUITE(BinarySearchTest, Solutions);

TYPED_TEST(BinarySearchTest, search_zero)
{
    auto result = this->algo.search(0);

    EXPECT_EQ(result, true);
}