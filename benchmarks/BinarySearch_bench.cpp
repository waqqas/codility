#include "BinarySearch.h"

#include <benchmark/benchmark.h>
#include <limits>

using namespace Codility;

template <Implemenation I>
void BinarySearchBench(benchmark::State& state)
{
    using value_type = typename BinarySearch<I>::value_type;
    int32_t number = static_cast<value_type>(state.range(0));

    BinarySearch<I> algo;

    for (auto _ : state) {
        ::benchmark::DoNotOptimize(algo.search(number));
    }
}

BENCHMARK_TEMPLATE(BinarySearchBench, Implemenation::StdAlgo)
    ->RangeMultiplier(8)
    ->Range(1, std::numeric_limits<int32_t>::max());
BENCHMARK_TEMPLATE(BinarySearchBench, Implemenation::Intrinsics)
    ->RangeMultiplier(8)
    ->Range(1, std::numeric_limits<int32_t>::max());
