#include "RectangleBuilderGreaterArea.h"
#include <benchmark/benchmark.h>

template <int32_t S> void RectangleBuilderGreaterArea(benchmark::State &state) {
  Codility::RectangleBuilderGreaterArea<S> question;

  for (auto _ : state) {
  }
}

BENCHMARK_TEMPLATE(RectangleBuilderGreaterArea, 1);
