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

double
transform(double* __restrict__ P, const double* __restrict__ S);
double
transformVec(double* __restrict__ P, const double* __restrict__ S);

double
transformVec2(double* __restrict__ P, const double* __restrict__ S);

#endif
