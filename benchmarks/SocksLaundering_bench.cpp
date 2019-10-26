#include "benchmark/benchmark.h"
#include "SocksLaundering.h"


template <int32_t S> void SocksLaundering(benchmark::State &state) {
  Codility::SocksLaundering<S> question;

  for (auto _ : state) {
    // ::benchmark::DoNotOptimize(question.solution(input));
  }
}

BENCHMARK_TEMPLATE(SocksLaundering, 1)->RangeMultiplier(2)->Range(1, 50);
