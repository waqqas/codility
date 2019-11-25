#include "BinarySearch.h"

#include <benchmark/benchmark.h>
#include <limits>

using namespace Codility;

template <size_t SIZE, Implemenation I>
void BinarySearchBench(benchmark::State& state)
{
    using value_type = typename BinarySearch<SIZE, I>::value_type;
    int32_t number = static_cast<value_type>(state.range(0));

    BinarySearch<SIZE, I> algo;

    for (auto _ : state) {
        ::benchmark::DoNotOptimize(algo.search(number));
    }
}

BENCHMARK_TEMPLATE(BinarySearchBench, 64, Implemenation::StdAlgo)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
BENCHMARK_TEMPLATE(BinarySearchBench, 64, Implemenation::Intrinsics)
    ->RangeMultiplier(8)
    ->Range(1, 1 << 12);
