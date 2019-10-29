#include "TwoArray.h"
#include <benchmark/benchmark.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void generate_random_access(std::vector<size_t> &offsets) {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<size_t> distribution(0, offsets.size() - 1);

  std::transform(
      std::begin(offsets), std::end(offsets), std::begin(offsets),
      [&distribution, &gen](size_t value) { return distribution(gen); });
}

void generate_ascending_access(std::vector<size_t> &offsets) {
  size_t offset = 0;
  std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                 [&offset](size_t value) { return offset++; });
}

void generate_descending_access(std::vector<size_t> &offsets) {
  size_t offset = offsets.size() - 1;
  std::transform(std::begin(offsets), std::end(offsets), std::begin(offsets),
                 [&offset](size_t value) { return offset--; });
}

template <int32_t S> void TwoArray(benchmark::State &state) {
  using value_type = typename Codility::TwoArray<S>::value_type;

  Codility::TwoArray<S> question;

  std::size_t size = state.range(0);
  std::vector<value_type> input(size, 0);

  // generate access pattern
  std::vector<size_t> offsets;
  offsets.resize(size);

  // generate_random_access(offsets);
  // generate_ascending_access(offsets);
  generate_descending_access(offsets);

  int32_t index = 0;
  for (auto _ : state) {
    ::benchmark::DoNotOptimize(question.solution(input, offsets[index]));
    index = (++index) % size;
  }
}

BENCHMARK_TEMPLATE(TwoArray, 1)->RangeMultiplier(2)->Range(1 << 15, 1 << 24);
