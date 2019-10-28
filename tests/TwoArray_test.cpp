#include "TwoArray.h"
#include "gtest/gtest.h"

#include <limits>
#include <utility>

template <typename TypeName> class TwoArrayTest : public testing::Test {
public:
  TypeName question;
};

using Solutions =
    ::testing::Types<Codility::TwoArray<1>>;
TYPED_TEST_SUITE(TwoArrayTest, Solutions);

TYPED_TEST(TwoArrayTest, example1) {
   GTEST_FAIL();
}
