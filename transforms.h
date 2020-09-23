#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#include "vec.h"

void
transform(double* __restrict__ P,
          const double* __restrict__ S);
void
transformVec(double* __restrict__ P,
             const double* __restrict__ S);

void
transformVec2(double* __restrict__ P,
             const double* __restrict__ S);


#endif
