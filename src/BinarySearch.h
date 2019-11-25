#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "vectorclass.h"
#include <algorithm>
#include <array>
#include <cstdint>
#include <iterator>

namespace Codility {

enum class Implemenation {
    StdAlgo,
    Intrinsics,
};

template <size_t SIZE, typename T = int32_t, Implemenation = Implemenation::StdAlgo>
class BinarySearch {
  public:
    using array_type = std::array<T, SIZE>;
    using value_type = typename array_type::value_type;
    using index_type = typename array_type::size_type;

  private:
    array_type data;

  public:
    BinarySearch()
    {
        for (index_type index = 0; index < data.size(); ++index) {
            data[index] = index;
        }
    }
    bool search(const T& to_find)
    {
        return std::binary_search(std::begin(data), std::end(data), to_find);
    }
};

template <size_t SIZE, typename T>
class alignas(64) BinarySearch<SIZE, T, Implemenation::Intrinsics> {
  public:
    using array_type = std::array<T, SIZE>;
    using value_type = typename array_type::value_type;
    using index_type = typename array_type::size_type;

  private:
    array_type data;

  public:
    BinarySearch()
    {
        for (index_type index = 0; index < data.size(); ++index) {
            data[index] = index;
        }
        std::sort(std::begin(data), std::end(data));
    }
    bool search(const T& to_find)
    {
        // initialize start/end to the array bounds
        index_type start_ = 0;
        index_type end_ = data.size();
        index_type begin_ = 0;

        while (1) {
            // find the indexes bounds to load
            index_type size = end_ - start_;
            index_type jump = size / 4;

            // load values from indexes (lookup)
            Vec4i pivots(data[jump], data[jump * 2], data[jump * 3], 0);

            // compare with to_find
            Vec4i find(to_find);
            Vec4ib equal = pivots == find;

            // find the portion in which the item lies
            int match = horizontal_find_first(equal);
            if (match == -1) {
                Vec4ib less_than = pivots < find;
                int match = horizontal_find_first(less_than);

                // calculate new start, end
                start_ = jump * match;
                end_ = jump * (match + 1);

            } else {
                return true; // calculate index
            }
        }

        return false;
    }
};

} // namespace Codility
#endif
