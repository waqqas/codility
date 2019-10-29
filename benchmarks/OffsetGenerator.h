#ifndef _OFFSET_GENERATOR_H_
#define _OFFSET_GENERATOR_H_

#include <algorithm>
#include <cstdint>
#include <random>
#include <string>
#include <vector>

enum class GeneratorType {
    Random,
    Ascending,
    Descending,
    AscendingWithOffset,
    Sawtooth1,
    Sawtooth2
};

template <GeneratorType = GeneratorType::Random>
class OffsetGenerator {
  public:
    static void generate(std::vector<size_t>& offsets)
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<size_t> distribution(0, offsets.size() - 1);

        std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                       [&distribution, &gen](size_t value) { return distribution(gen); });
    }
};

template <>
class OffsetGenerator<GeneratorType::Ascending> {
  public:
    static void generate(std::vector<size_t>& offsets)
    {
        size_t offset = 0;
        std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                       [&offset](size_t value) { return offset++; });
    }
};

template <>
class OffsetGenerator<GeneratorType::Descending> {
  public:
    static void generate(std::vector<size_t>& offsets)
    {
        size_t offset = offsets.size() - 1;
        std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                       [&offset](size_t value) { return offset--; });
    }
};

template <>
class OffsetGenerator<GeneratorType::AscendingWithOffset> {
  public:
    static void generate(std::vector<size_t>& offsets, size_t initial_offset = 1)
    {
        size_t offset = initial_offset;
        size_t max = offsets.size() - 1;
        std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                       [&offset, max](size_t value) {
                           value = offset;
                           if (offset == max) {
                               offset = 0;
                           } else {
                               offset++;
                           }
                           return value;
                       });
    }
};

template <>
class OffsetGenerator<GeneratorType::Sawtooth1> {
  public:
    static void generate(std::vector<size_t>& offsets, size_t teeth = 4)
    {
        size_t offset = 0;
        size_t max = offsets.size() / teeth;
        std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                       [&offset, max](size_t value) {
                           value = offset;
                           if (value == max) {
                               value = 0;
                           } else {
                               offset++;
                           }
                           return value;
                       });
    }
};

template <>
class OffsetGenerator<GeneratorType::Sawtooth2> {
  public:
    static void generate(std::vector<size_t>& offsets, size_t teeth = 4)
    {
        size_t offset = 0;
        size_t max = offsets.size() / teeth;
        size_t ascending = true;
        std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                       [&offset, &ascending, max](size_t value) {
                           value = offset;

                           if (ascending) {
                               if (offset == max) {
                                   ascending = false;
                               }
                           } else {
                               if (offset == 0) {
                                   ascending = true;
                               }
                           }
                           offset = ascending ? offset + 1 : offset - 1;

                           return value;
                       });
    }
};

#endif
