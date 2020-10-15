#ifndef TRANSFORMS_H
#define TRANSFORMS_H
#include "vec.h"
inline void
globalToLocalHelper(double* __restrict__ P,
                    const double s0,
                    const double s1,
                    const double s2,
                    const double s3,
                    const double s4)
{

  P[7] -= (s0 * P[3]);
  P[8] -= (s0 * P[4]);
  P[9] -= (s0 * P[5]);
  P[10] -= (s0 * P[42]);
  P[11] -= (s0 * P[43]);
  P[12] -= (s0 * P[44]);
  P[14] -= (s1 * P[3]);
  P[15] -= (s1 * P[4]);
  P[16] -= (s1 * P[5]);
  P[17] -= (s1 * P[42]);
  P[18] -= (s1 * P[43]);
  P[19] -= (s1 * P[44]);
  P[21] -= (s2 * P[3]);
  P[22] -= (s2 * P[4]);
  P[23] -= (s2 * P[5]);
  P[24] -= (s2 * P[42]);
  P[25] -= (s2 * P[43]);
  P[26] -= (s2 * P[44]);
  P[28] -= (s3 * P[3]);
  P[29] -= (s3 * P[4]);
  P[30] -= (s3 * P[5]);
  P[31] -= (s3 * P[42]);
  P[32] -= (s3 * P[43]);
  P[33] -= (s3 * P[44]);
  P[35] -= (s4 * P[3]);
  P[36] -= (s4 * P[4]);
  P[37] -= (s4 * P[5]);
  P[38] -= (s4 * P[42]);
  P[39] -= (s4 * P[43]);
  P[40] -= (s4 * P[44]);
}

inline void
globalToLocalVecHelper(double* __restrict__ P,
                       const double s0,
                       const double s1,
                       const double s2,
                       const double s3,
                       const double s4)
{
  using namespace CxxUtils;
  using vec2 = CxxUtils::vec<double, 2>;

  vec2 Pmult1 = { P[3], P[4] };
  vec2 Pmult2 = { P[5], P[42] };
  vec2 Pmult3 = { P[43], P[44] };

  vec2 dXdL0_dYdL0;
  vload(dXdL0_dYdL0, &P[7]);
  vec2 dZdL0_dAxdL0;
  vload(dZdL0_dAxdL0, &P[9]);
  vec2 dAydL0_dAzdL0;
  vload(dAydL0_dAzdL0, &P[11]);
  dXdL0_dYdL0 -= s0 * Pmult1;
  dZdL0_dAxdL0 -= s0 * Pmult2;
  dAydL0_dAzdL0 -= s0 * Pmult3;
  vstore(&P[7], dXdL0_dYdL0);
  vstore(&P[9], dZdL0_dAxdL0);
  vstore(&P[11], dAydL0_dAzdL0);

  vec2 dXdL1_dYdL1;
  vload(dXdL1_dYdL1, &P[14]);
  vec2 dZdL1_dAxdL1;
  vload(dZdL1_dAxdL1, &P[16]);
  vec2 dAydL1_dAzdL1;
  vload(dAydL1_dAzdL1, &P[18]);
  dXdL1_dYdL1 -= s1 * Pmult1;
  dZdL1_dAxdL1 -= s1 * Pmult2;
  dAydL1_dAzdL1 -= s1 * Pmult3;
  vstore(&P[14], dXdL1_dYdL1);
  vstore(&P[16], dZdL1_dAxdL1);
  vstore(&P[18], dAydL1_dAzdL1);

  vec2 dXdPhi_dYdPhi;
  vload(dXdPhi_dYdPhi, &P[21]);
  vec2 dZdPhi_dAxdPhi;
  vload(dZdPhi_dAxdPhi, &P[23]);
  vec2 dAydPhi_dAzdPhi;
  vload(dAydPhi_dAzdPhi, &P[25]);
  dXdPhi_dYdPhi -= s2 * Pmult1;
  dZdPhi_dAxdPhi -= s2 * Pmult2;
  dAydPhi_dAzdPhi -= s2 * Pmult3;
  vstore(&P[21], dXdPhi_dYdPhi);
  vstore(&P[23], dZdPhi_dAxdPhi);
  vstore(&P[25], dAydPhi_dAzdPhi);

  vec2 dXdTheta_dYdTheta;
  vload(dXdTheta_dYdTheta, &P[28]);
  vec2 dZdTheta_dAxdTheta;
  vload(dZdTheta_dAxdTheta, &P[30]);
  vec2 dAydTheta_dAzdTheta;
  vload(dAydTheta_dAzdTheta, &P[32]);
  dXdTheta_dYdTheta -= s3 * Pmult1;
  dZdTheta_dAxdTheta -= s3 * Pmult2;
  dAydTheta_dAzdTheta -= s3 * Pmult3;
  vstore(&P[28], dXdTheta_dYdTheta);
  vstore(&P[30], dZdTheta_dAxdTheta);
  vstore(&P[32], dAydTheta_dAzdTheta);

  vec2 dXdCM_dYdCM;
  vload(dXdCM_dYdCM, &P[35]);
  vec2 dZdCM_dAxdCM;
  vload(dZdCM_dAxdCM, &P[37]);
  vec2 AydCM_dAzdCM;
  vload(AydCM_dAzdCM, &P[39]);
  dXdCM_dYdCM -= s4 * Pmult1;
  dZdCM_dAxdCM -= s4 * Pmult2;
  AydCM_dAzdCM -= s4 * Pmult3;
  vstore(&P[35], dXdCM_dYdCM);
  vstore(&P[37], dZdCM_dAxdCM);
  vstore(&P[39], AydCM_dAzdCM);
}

#endif
