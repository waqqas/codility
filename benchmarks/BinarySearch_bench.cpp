#include "BinarySearch.h"

#include <benchmark/benchmark.h>
#include <limits>
#include <array>

using namespace Codility;

template <typename T, Implemenation I>
void BinarySearchBench(benchmark::State& state)
{
    using value_type = typename BinarySearch<T, I>::value_type;
    int32_t number = static_cast<value_type>(state.range(0));

    BinarySearch<T, I> algo;

    for (auto _ : state) {
        ::benchmark::DoNotOptimize(algo.search(number));
    }
}

BENCHMARK_TEMPLATE(BinarySearchBench, std::array<int32_t, 256>, Implemenation::StdAlgo)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
BENCHMARK_TEMPLATE(BinarySearchBench, std::array<int32_t, 256>, Implemenation::Intrinsics)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
BENCHMARK_TEMPLATE(BinarySearchBench, std::array<int32_t, 256>, Implemenation::IntrinsicsImpl2)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
BENCHMARK_TEMPLATE(BinarySearchBench, std::array<int32_t, 256>, Implemenation::UnorderedSet)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
