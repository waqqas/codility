#include "CacheArray.h"
#include "gtest/gtest.h"

TEST(CacheArray, Store_at_zero_index)
{
    Cache::Array<uint32_t, 3> data;
    
    data[0] = 1U;
    data[1] = 2U;
    data[2] = 3U;
    EXPECT_EQ(data[0], 2U);
    EXPECT_EQ(data[1], 1U);
    EXPECT_EQ(data[2], 3U);
}