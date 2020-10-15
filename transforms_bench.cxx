#include "benchmark/benchmark.h"
#include "transforms.h"
#include <cstring>
#include <algorithm>
#include <random>
/*
 * A bit hacky way to create random inputs
 */
double P[45];
double Pvec[45];
class InitArray
{
public:
  InitArray()
  {
    std::mt19937 gen;
    std::uniform_real_distribution<> dis(1.0, 10.0);
    for (size_t i = 0; i < 45; ++i) {
      double in =  dis(gen);
      P[i] = in;
      Pvec[i]=in;
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
      globalToLocalHelper(P, 0.1,0.2,0.3,0.4,0.5);
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
      globalToLocalVecHelper(Pvec, 0.1,0.2,0.3,0.4,0.5);
    }
  }
}
BENCHMARK(transformVec2_bench)->RangeMultiplier(2)->Range(1024, 8192);

BENCHMARK_MAIN();
