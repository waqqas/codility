#include "BinarySearch.h"

#include <benchmark/benchmark.h>
#include <limits>

using namespace Codility;

template <size_t SIZE, typename T, Implemenation I>
void BinarySearchBench(benchmark::State& state)
{
    using value_type = typename BinarySearch<SIZE, T, I>::value_type;
    int32_t number = static_cast<value_type>(state.range(0));

    BinarySearch<SIZE, T, I> algo;

    for (auto _ : state) {
        ::benchmark::DoNotOptimize(algo.search(number));
    }
}

BENCHMARK_TEMPLATE(BinarySearchBench, 256, int32_t, Implemenation::StdAlgo)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
BENCHMARK_TEMPLATE(BinarySearchBench, 256, int32_t, Implemenation::Intrinsics)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
BENCHMARK_TEMPLATE(BinarySearchBench, 256, int32_t, Implemenation::IntrinsicsImpl2)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
// ->RangeMultiplier(2)
// ->Range(1, 1 << 12);
BENCHMARK_TEMPLATE(BinarySearchBench, 256, int32_t, Implemenation::UnorderedSet)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
