#include "TwoArray.h"
#include <benchmark/benchmark.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

template <int32_t S> void TwoArray(benchmark::State &state) {
  using value_type = typename Codility::TwoArray<S>::value_type;

  Codility::TwoArray<S> question;

  std::size_t size = state.range(0);
  std::vector<value_type> input(size, 0);

  // generate access pattern
  std::random_device rd;
  std::mt19937 gen(rd());
  std::size_t max_index = size - 1;
  std::uniform_int_distribution<size_t> distribution(0, max_index);

  std::vector<size_t> offsets;
  offsets.resize(size);

  std::transform(
      std::begin(offsets), std::end(offsets), std::begin(offsets),
      [&distribution, &gen](size_t value) { return distribution(gen); });

  int32_t index = 0;
  for (auto _ : state) {
    ::benchmark::DoNotOptimize(question.solution(input, offsets[index]));
    index = (++index) % size;
  }
}

BENCHMARK_TEMPLATE(TwoArray, 1)->RangeMultiplier(2)->Range(1 << 15, 1 << 24);
