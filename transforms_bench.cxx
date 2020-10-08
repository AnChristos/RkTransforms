#include "benchmark/benchmark.h"
#include "transforms.h"
#include <cstring>
#include <algorithm>
#include <random>
/*
 * A bit hacky way to create random inputs
 */
double P[45];
double S[3];
class InitArray
{
public:
  InitArray()
  {
    std::mt19937 gen;
    std::uniform_real_distribution<> dis(1.0, 10.0);
    for (size_t i = 0; i < 45; ++i) {
      P[i] = dis(gen);
    }
    for (size_t i = 0; i < 3; ++i) {
      S[i] = dis(gen);
    }
  }
};
InitArray initArray;


static void
transform_bench(benchmark::State& state)
{
  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      transform(P, S);
    }
  }
}
BENCHMARK(transform_bench)->RangeMultiplier(2)->Range(1024, 8192);


static void
transformVec2_bench(benchmark::State& state)
{
  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      transformVec2(P, S);
    }
  }
}
BENCHMARK(transformVec2_bench)->RangeMultiplier(2)->Range(1024, 8192);

BENCHMARK_MAIN();
