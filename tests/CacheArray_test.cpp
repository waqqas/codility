#include "CacheArray.h"
#include "gtest/gtest.h"

TEST(CacheArray, ArrayOfSize3)
{
    Cache::Array<uint32_t, 3> data;
    
    data[0] = 1U;
    data[1] = 2U;
    data[2] = 3U;
    EXPECT_EQ(data[0], 2U);
    EXPECT_EQ(data[1], 1U);
    EXPECT_EQ(data[2], 3U);
}


TEST(CacheArray, ArrayOfSize4)
{
    Cache::Array<uint32_t, 4> data;
    
    data[0] = 1U;
    data[1] = 2U;
    data[2] = 3U;
    data[3] = 4U;

    EXPECT_EQ(data[0], 3U);
    EXPECT_EQ(data[1], 2U);
    EXPECT_EQ(data[2], 4U);
    EXPECT_EQ(data[3], 1U);
}

TEST(CacheArray, ArrayOfSize5)
{
    Cache::Array<uint32_t, 5> data;
    
    data[0] = 1U;
    data[1] = 2U;
    data[2] = 3U;
    data[3] = 4U;
    data[4] = 5U;

    EXPECT_EQ(data[0], 3U);
    EXPECT_EQ(data[1], 2U);
    EXPECT_EQ(data[2], 4U);
    EXPECT_EQ(data[3], 1U);
    EXPECT_EQ(data[4], 5U);
}

TEST(CacheArray, ArrayOfSize6)
{
    Cache::Array<uint32_t, 6> data;
    
    data[0] = 1U;
    data[1] = 2U;
    data[2] = 3U;
    data[3] = 4U;
    data[4] = 5U;
    data[5] = 6U;

    EXPECT_EQ(data[0], 4U);
    EXPECT_EQ(data[1], 2U);
    EXPECT_EQ(data[2], 5U);
    EXPECT_EQ(data[3], 1U);
    EXPECT_EQ(data[4], 3U);
    EXPECT_EQ(data[5], 6U);
}