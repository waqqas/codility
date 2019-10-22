#include "solutions.h"

#include <benchmark/benchmark.h>
#include <limits>

template <int32_t S>
void BM_Solution(benchmark::State &state)
{
  Codility::BinaryGap<S> question;
  int32_t                number = static_cast<int32_t>(state.range(0));

  for (auto _ : state)
  {
    ::benchmark::DoNotOptimize(question.solution(number));
  }
}

BENCHMARK_TEMPLATE(BM_Solution, 1)->RangeMultiplier(8)->Range(1, std::numeric_limits<int32_t>::max());
BENCHMARK_TEMPLATE(BM_Solution, 2)->RangeMultiplier(8)->Range(1, std::numeric_limits<int32_t>::max());
