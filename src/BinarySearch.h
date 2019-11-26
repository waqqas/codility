#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "vectorclass.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iterator>
#include <vector>

using namespace std;

using vector_type = Vec4i;

namespace Codility {

enum class Implemenation { StdAlgo, Intrinsics, IntrinsicsImpl2, UnorderedSet };

template <typename T, Implemenation = Implemenation::StdAlgo>
class BinarySearch {
  public:
    using array_type = T;
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
    bool search(const value_type& to_find)
    {
        return std::binary_search(std::begin(data), std::end(data), to_find);
    }
};

template <typename T>
class alignas(64) BinarySearch<T, Implemenation::Intrinsics> {
  public:
    using array_type = T;
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
    bool search(const value_type& to_find)
    {

        Vec4i a;
        Vec4i b(to_find);

        int seg_len = data.size() / 4;
        int seg_start = 0;

        a = Vec4i(data[seg_start + 0 * seg_len], data[seg_start + 1 * seg_len],
                  data[seg_start + 2 * seg_len], data[seg_start + 3 * seg_len]);

        // while (seg_len >= 1)
        for (auto it = 0; it < 4; it++) {
            auto match = horizontal_find_first(a == b);
            if (-1 != match) {

                return true;
            } else {
                match = horizontal_find_first(a > b);
                if (-1 == match)
                    match = 4;

                seg_start = seg_start + (seg_len * (match - 1));
                seg_len = seg_len / 4;

                a = Vec4i(data[seg_start + 0 * seg_len], data[seg_start + 1 * seg_len],
                          data[seg_start + 2 * seg_len], data[seg_start + 3 * seg_len]);
            }
        }
        return false;
    }
};

template <typename T>
class alignas(64) BinarySearch<T, Implemenation::IntrinsicsImpl2> {
  public:
    using array_type = T;
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
    bool search(const value_type& to_find)
    {
        vector_type a;
        vector_type b(to_find);

        vector_type offset(0, 64, 128, 192);

        int seg_len = data.size() / a.size();
        int seg_start = 0, match, shift_idx = 0;

        for (seg_len = data.size() >> 2; seg_len >= 1; seg_len = seg_len >> 2) {
            vector_type base(seg_start);
            vector_type index = offset + base;

            offset = offset >> 2;

            a = Vec4i(data[index[0]], data[index[1]], data[index[2]], data[index[3]]);

            // a = Vec4i(data[seg_start + 0 * seg_len], data[seg_start + 1 * seg_len],
            //               data[seg_start + 2 * seg_len], data[seg_start + 3 * seg_len]);

            match = horizontal_find_first(a >= b);

            if (-1 == match) {
                match = a.size();
            }

            else if (to_find == a[match]) {
                return true;
            }

            seg_start = seg_start + (seg_len * (match - 1));
        }

        return false;
    }
};

template <typename T>
class alignas(64) BinarySearch<T, Implemenation::UnorderedSet> {
  public:
    using array_type = T;
    using value_type = typename array_type::value_type;
    using index_type = typename array_type::size_type;

  private:
    unordered_set<int32_t> data;

  public:
    BinarySearch()
    {
        for (index_type index = 0; index < data.size(); ++index) {
            data.insert(index);
        }
    }
    bool search(const value_type& to_find) { return (data.find(to_find) != data.end()); }
};

} // namespace Codility
#endif
