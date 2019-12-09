#ifndef CACHE_ARRAY_H
#define CACHE_ARRAY_H

#include <array>
#include <cstddef>

namespace Cache {

template <typename T, size_t SIZE>
class Array {
  private:
    using array_type = std::array<T, SIZE>;
    using size_type = typename array_type::size_type;
    using reference = typename array_type::reference;
    using const_reference = typename array_type::const_reference;

    using offset_type = std::array<size_type, SIZE>;

    array_type data;
    offset_type offsets;

  public:
    Array()
    : offsets{1U, 0U, 2U}
    {
    }

    reference operator[](size_type logical)
    {
        size_type physical = offsets[logical];
        return data[physical];
    }
};
} // namespace Cache
#endif
