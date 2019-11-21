#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <algorithm>
#include <array>
#include <cstdint>

namespace Codility {

enum class Implemenation {
    StdAlgo,
    Intrinsics,
};

template <Implemenation = Implemenation::StdAlgo>
class BinarySearch {
  public:
    using value_type = int32_t;

  private:
    std::array<value_type, 4096> data;

  public:
    bool search(const value_type& to_find)
    {
        return std::binary_search(std::begin(data), std::end(data), to_find);
    }
};

template <>
class BinarySearch<Implemenation::Intrinsics> {
  public:
    using value_type = int32_t;

  private:
    std::array<value_type, 4096> data;

  public:
    bool search(const value_type& to_find) { return false; }
};

} // namespace Codility
#endif
