#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#if defined(__GNUC__) && !defined(__clang__) && !defined(__ICC) &&             \
  !defined(__COVERITY__) && !defined(__CUDACC__)
#define ATH_ENABLE_VECTORIZATION                                               \
  _Pragma("GCC optimize (\"tree-vectorize\")") class                           \
    ATH_ENABLE_VECTORIZATION_SWALLOW_SEMICOLON
#else
#define ATH_ENABLE_VECTORIZATION                                               \
  class ATH_ENABLE_VECTORIZATION_SWALLOW_SEMICOLON
#endif

#include "vec.h"
struct alignas(32) Pstruct6
{
  using vec2 = CxxUtils::vec<double, 2>;
  vec2 dX[3];
  vec2 dY[3];
  vec2 dZ[3];
  vec2 dAx[3];
  vec2 dAy[3];
  vec2 dAz[3];
  vec2 dCM[3];

  double pos[3];
  double dir[3];
  double dAds[3];

  double dCMdCM;
  double CM;
  void fromP(const double* __restrict__P) __restrict__;
  void toP(double* __restrict__ P) const __restrict__;
};

double
transform(double* __restrict__ P, const double* __restrict__ S);
double
transformVec(double* __restrict__ P, const double* __restrict__ S);
double
transformVec2(double* __restrict__ P, const double* __restrict__ S);
double
transformVec6Transf(double* __restrict__ P_in, const double* __restrict__ S);
double
transformVec6(Pstruct6& __restrict__ P, const double* __restrict__ S);

#endif
