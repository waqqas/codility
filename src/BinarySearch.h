#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <algorithm>
#include <array>
#include <cstdint>
#include "vectorclass.h"

namespace Codility {

enum class Implemenation {
    StdAlgo,
    Intrinsics,
};

constexpr size_t SIZE = 4096U;

template <Implemenation = Implemenation::StdAlgo>
class BinarySearch {
  public:
    using value_type = int32_t;
    using array_type = std::array<value_type, SIZE>;
    using index_type = array_type::size_type;

  private:
    array_type data;

  public:
    BinarySearch()
    {
        for (index_type index = 0; index < data.size(); ++index) {
            data[index] = index;
        }
    }
    bool search(const value_type& to_find)
    {
        return std::binary_search(std::begin(data), std::end(data), to_find);
    }
};

template <>
class BinarySearch<Implemenation::Intrinsics> {
  public:
    using value_type = int32_t;
    using array_type = std::array<value_type, SIZE>;
    using index_type = array_type::size_type;

  private:
    array_type data;

  public:
    BinarySearch()
    {
        for (index_type index = 0; index < data.size(); ++index) {
            data[index] = index;
        }
    }
    bool search(const value_type& to_find) { return false; }
};

} // namespace Codility
#endif
