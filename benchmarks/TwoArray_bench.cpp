#include "OffsetGenerator.h"
#include "TwoArray.h"
#include <benchmark/benchmark.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

template <int32_t S, typename G>
void TwoArray(benchmark::State& state)
{
    using value_type = typename Codility::TwoArray<S>::value_type;

    Codility::TwoArray<S> question;

    std::size_t size = state.range(0);
    std::vector<value_type> input(size, 0);

    // generate access pattern
    std::vector<size_t> offsets;
    offsets.resize(size);

    G::generate(offsets);

    // std::for_each(std::begin(offsets), std::end(offsets),
    //               [](size_t value) { std::cout << value << std::endl; });
    // std::cout << std::endl;

    int32_t index = 0;
    for (auto _ : state) {
        ::benchmark::DoNotOptimize(question.solution(input, offsets[index]));
        index++;
        index %= size;
    }
}

BENCHMARK_TEMPLATE(TwoArray, 1, OffsetGenerator<GeneratorType::Random>)
    ->RangeMultiplier(2)
    ->Range(1 << 14, 1 << 24);

BENCHMARK_TEMPLATE(TwoArray, 1, OffsetGenerator<GeneratorType::Ascending>)
    ->RangeMultiplier(2)
    ->Range(1 << 14, 1 << 24);

BENCHMARK_TEMPLATE(TwoArray, 1, OffsetGenerator<GeneratorType::Descending>)
    ->RangeMultiplier(2)
    ->Range(1 << 14, 1 << 24);

BENCHMARK_TEMPLATE(TwoArray, 1, OffsetGenerator<GeneratorType::AscendingWithOffset>)
    ->RangeMultiplier(2)
    ->Range(1 << 14, 1 << 24);

BENCHMARK_TEMPLATE(TwoArray, 1, OffsetGenerator<GeneratorType::Sawtooth1>)
    ->RangeMultiplier(2)
    ->Range(1 << 14, 1 << 24);

BENCHMARK_TEMPLATE(TwoArray, 1, OffsetGenerator<GeneratorType::Sawtooth2>)
    ->RangeMultiplier(2)
    ->Range(1 << 14, 1 << 24);