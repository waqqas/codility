#include "solutions.h"

#include <benchmark/benchmark.h>
#include <string>

template <int32_t S>
void BM_Solution(benchmark::State &state) {
  Codility::StrSymmetryPoint<S> question;

  std::string input("racecar");

  for (auto _ : state) {
    ::benchmark::DoNotOptimize(question.solution(input));
  }
}

BENCHMARK_TEMPLATE(BM_Solution, 1);
