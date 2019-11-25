#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "vectorclass.h"
#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstdint>
#include <iterator>
#include <vector>

using namespace std;

#define INSTR_SIZE 4
#define VEC_TYPE Vec4i

namespace Codility {

enum class Implemenation { StdAlgo, Intrinsics, UnorderedSet };

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

#if 0
        VEC_TYPE a;
        VEC_TYPE b(to_find);

        int list[INSTR_SIZE] = {0};

        int seg_len = SIZE/INSTR_SIZE;
        int seg_start = 0;

        for(auto i = 0; i < INSTR_SIZE; i++)
            list[i] = data[seg_start + i*seg_len];

        a.load(list);

        while (seg_len >= 1)
        {   
                auto match = horizontal_find_first(a == b);
                if (-1 != match)
                {
                    return true;
                }
                else    
                {
                    match = horizontal_find_first(a > b);
                    if (-1 == match) 
                        match = INSTR_SIZE;

                    seg_start   = seg_start + (seg_len * (match - 1));
                    seg_len     = seg_len / INSTR_SIZE;

                    for(auto i = 0; i < INSTR_SIZE; i++)
                        list[i] = data[seg_start + i*seg_len];
                    a.load(list);
                }       
        }
        return false;
#else
        Vec4i a;
        Vec4i b(to_find);

        int seg_len = SIZE / 4;
        int seg_start = 0;

        a = Vec4i(data[seg_start + 0 * seg_len], data[seg_start + 1 * seg_len],
                  data[seg_start + 2 * seg_len], data[seg_start + 3 * seg_len]);

        while (seg_len >= 1) {
            auto match = horizontal_find_first(a == b);
            if (-1 != match) {
                // cout << to_find << " found at " << seg_start + match << endl;
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
#endif
    }
};

template <size_t SIZE, typename T>
class alignas(64) BinarySearch<SIZE, T, Implemenation::UnorderedSet> {
  public:
    using array_type = std::array<T, SIZE>;
    using value_type = typename array_type::value_type;
    using index_type = typename array_type::size_type;

  private:
    unordered_set<uint32_t> data;

  public:
    BinarySearch()
    {
        for (index_type index = 0; index < data.size(); ++index) {
            data.insert(index);
        }
    }
    bool search(const T& to_find) { return (data.find(to_find) != data.end()); }
};

} // namespace Codility
#endif
