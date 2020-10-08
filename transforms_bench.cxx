#include "benchmark/benchmark.h"
#include "transforms.h"
#include <cstring>
#include <algorithm>
#include <random>
/*
 * A bit hacky way to create random inputs
 */
double Pref[42];
double Sref[3];
class InitArray
{
public:
  InitArray()
  {
    std::mt19937 gen;
    std::uniform_real_distribution<> dis(1.0, 10.0);
    for (size_t i = 0; i < 42; ++i) {
      Pref[i] = dis(gen);
    }
    for (size_t i = 0; i < 3; ++i) {
      Sref[i] = dis(gen);
    }
  }
};
InitArray initArray;


static void
transform_bench(benchmark::State& state)
{
  double P[42];
  double S[3];
  std::memcpy(P,Pref,42*sizeof(double));
  std::memcpy(S,Sref,3*sizeof(double));
  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      transform(P, S);
      benchmark::DoNotOptimize(P);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(transform_bench)->RangeMultiplier(2)->Range(1024, 8192);


static void
transformVec2_bench(benchmark::State& state)
{
  double P[42];
  double S[3];
  std::memcpy(P,Pref,42*sizeof(double));
  std::memcpy(S,Sref,3*sizeof(double));
  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      transformVec2(P, S);
      benchmark::DoNotOptimize(P);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(transformVec2_bench)->RangeMultiplier(2)->Range(1024, 8192);

BENCHMARK_MAIN();
