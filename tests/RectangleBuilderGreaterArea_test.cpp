#include "RectangleBuilderGreaterArea.h"
#include "gtest/gtest.h"

template <typename TypeName>
class RectangleBuilderGreaterArea : public testing::Test {
  public:
    TypeName question;
};

using Solutions = ::testing::Types<Codility::RectangleBuilderGreaterArea<1>>;
TYPED_TEST_SUITE(RectangleBuilderGreaterArea, Solutions);

TYPED_TEST(RectangleBuilderGreaterArea, test)
{
    EXPECT_EQ(true, true);
}
