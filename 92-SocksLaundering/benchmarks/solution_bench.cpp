#include "benchmark/benchmark.h"
#include "solutions.h"


template <int32_t S> void BM_Solution(benchmark::State &state) {
  Codility::SocksLaundering<S> question;

  for (auto _ : state) {
    // ::benchmark::DoNotOptimize(question.solution(input));
  }
}

BENCHMARK_TEMPLATE(BM_Solution, 1)->RangeMultiplier(2)->Range(1, 50);
