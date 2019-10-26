#include "benchmark/benchmark.h"
#include "StrSymmetryPoint.h"
#include <algorithm>
#include <string>


template <int32_t S> void StrSymmetryPoint(benchmark::State &state) {
  Codility::StrSymmetryPoint<S> question;

  std::size_t size = state.range(0) + 1; // make it odd
  std::string input;
  input.resize(size);

  std::for_each(input.begin(), input.end(),
                [](std::string::value_type &val) { val = '\0'; });

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(question.solution(input));
  }
}

BENCHMARK_TEMPLATE(StrSymmetryPoint, 1)->RangeMultiplier(8)->Range(1, 200000);
