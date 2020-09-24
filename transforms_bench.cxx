#include "benchmark/benchmark.h"
#include "transforms.h"
#include <iostream>

static void
transform_bench(benchmark::State& state)
{
  const double S[3] = { 0.4, 0.2, 0.9 };

  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      double P[45] = { 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09,
                       0.1,  0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
                       0.19, 0.2,  0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27,
                       0.28, 0.29, 0.3,  0.31, 0.32, 0.33, 0.34, 0.35, 0.36,
                       0.37, 0.38, 0.39, 0.4,  0.41, 0.42, 0.43, 0.44, 0.45 };
      double Jac[10];
      // Jacobian production
      //
      transform(P, S);
      Jac[0] = P[7] + P[8] + P[9];
      Jac[1] = P[14] + P[15] + P[16];
      Jac[2] = P[21] + P[22] + P[23];
      Jac[3] = P[28] + P[29] + P[30];
      Jac[4] = P[35] + P[36] + P[37];
      Jac[5] = P[7] + P[8] + P[9];
      Jac[6] = P[14] + P[15] + P[16];
      Jac[7] = P[21] + P[22] + P[23];
      Jac[8] = P[28] + P[29] + P[30];
      Jac[9] = P[35] + P[36] + P[37];
      benchmark::DoNotOptimize(Jac);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(transform_bench)->RangeMultiplier(2)->Range(1024, 8192);

static void
transformVec_bench(benchmark::State& state)
{
  const double S[3] = { 0.4, 0.2, 0.9 };

  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      double P[45] = { 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09,
                       0.1,  0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
                       0.19, 0.2,  0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27,
                       0.28, 0.29, 0.3,  0.31, 0.32, 0.33, 0.34, 0.35, 0.36,
                       0.37, 0.38, 0.39, 0.4,  0.41, 0.42, 0.43, 0.44, 0.45 };
      transformVec(P, S);
      double Jac[10];
      // Jacobian production
      //
      Jac[0] = P[7] + P[8] + P[9];
      Jac[1] = P[14] + P[15] + P[16];
      Jac[2] = P[21] + P[22] + P[23];
      Jac[3] = P[28] + P[29] + P[30];
      Jac[4] = P[35] + P[36] + P[37];
      Jac[5] = P[7] + P[8] + P[9];
      Jac[6] = P[14] + P[15] + P[16];
      Jac[7] = P[21] + P[22] + P[23];
      Jac[8] = P[28] + P[29] + P[30];
      Jac[9] = P[35] + P[36] + P[37];
      benchmark::DoNotOptimize(Jac);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(transformVec_bench)->RangeMultiplier(2)->Range(1024, 8192);

static void
transformVec2_bench(benchmark::State& state)
{
  const double S[3] = { 0.4, 0.2, 0.9 };

  for (auto _ : state) {
    const int n = state.range(0);
    for (int i = 0; i < n; ++i) {
      double P[45] = { 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09,
                       0.1,  0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
                       0.19, 0.2,  0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27,
                       0.28, 0.29, 0.3,  0.31, 0.32, 0.33, 0.34, 0.35, 0.36,
                       0.37, 0.38, 0.39, 0.4,  0.41, 0.42, 0.43, 0.44, 0.45 };
      transformVec2(P, S);
      double Jac[10];
      // Jacobian production
      //
      Jac[0] = P[7] + P[8] + P[9];
      Jac[1] = P[14] + P[15] + P[16];
      Jac[2] = P[21] + P[22] + P[23];
      Jac[3] = P[28] + P[29] + P[30];
      Jac[4] = P[35] + P[36] + P[37];
      Jac[5] = P[7] + P[8] + P[9];
      Jac[6] = P[14] + P[15] + P[16];
      Jac[7] = P[21] + P[22] + P[23];
      Jac[8] = P[28] + P[29] + P[30];
      Jac[9] = P[35] + P[36] + P[37];
      benchmark::DoNotOptimize(Jac);
      benchmark::ClobberMemory();
    }
  }
}
BENCHMARK(transformVec2_bench)->RangeMultiplier(2)->Range(1024, 8192);

BENCHMARK_MAIN();
