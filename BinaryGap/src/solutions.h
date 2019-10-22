#ifndef _SOLUTIONS_H_
#define _SOLUTIONS_H_

#include <iostream>
#include <limits>

namespace Codility {
inline bool is_zero(uint32_t mask, int32_t number)
{
  return !(mask & number);
}

template <int32_t S>
class BinaryGap
{
public:
  int32_t solution(int32_t number)
  {
    bool               start_counting = false;
    int32_t            max_zeros      = 0;
    int32_t            current_zeros  = 0;
    constexpr uint32_t max_mask = static_cast<uint32_t>(std::numeric_limits<int32_t>::max()) + 1;

    for (uint32_t mask = 1; mask < max_mask; mask <<= 1)
    {
      if (is_zero(mask, number))
      {
        if (start_counting)
        {
          current_zeros++;
        }
      }
      else
      {
        if (current_zeros > max_zeros)
        {
          max_zeros = current_zeros;
        }
        current_zeros  = 0;
        start_counting = true;
      }
    }
    return max_zeros;
  }
};

template <>
class BinaryGap<2>
{
public:
  int32_t solution(int32_t number)
  {
    int32_t            max_zeros     = 0;
    int32_t            current_zeros = 0;
    constexpr uint32_t max_mask = static_cast<uint32_t>(std::numeric_limits<int32_t>::max()) + 1;

    uint32_t mask = 1;

    while (is_zero(mask, number))
    {
      mask <<= 1;
    }

    for (; mask < max_mask; mask <<= 1)
    {
      if (is_zero(mask, number))
      {
        current_zeros++;
      }
      else
      {
        if (current_zeros > max_zeros)
        {
          max_zeros = current_zeros;
        }
        current_zeros = 0;
      }
    }
    return max_zeros;
  }
};
}  // namespace Codility
#endif