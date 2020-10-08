#include "transforms.h"

ATH_ENABLE_VECTORIZATION;

double
transform(double* __restrict__ P, const double* __restrict__ S)
{

  const double s0 = P[7] * S[0] + P[8] * S[1] + P[9] * S[2];
  const double s1 = P[14] * S[0] + P[15] * S[1] + P[16] * S[2];
  const double s2 = P[21] * S[0] + P[22] * S[1] + P[23] * S[2];
  const double s3 = P[28] * S[0] + P[29] * S[1] + P[30] * S[2];
  const double s4 = P[35] * S[0] + P[36] * S[1] + P[37] * S[2];

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

  return P[7];
}


double
transformVec2(double* __restrict__ P, const double* __restrict__ S)
{
  using namespace CxxUtils;
  using vec2 = CxxUtils::vec<double, 2>;
  using vec4 = CxxUtils::vec<double, 4>;

  const double s0 = P[7] * S[0] + P[8] * S[1] + P[9] * S[2];
  const double s1 = P[14] * S[0] + P[15] * S[1] + P[16] * S[2];
  const double s2 = P[21] * S[0] + P[22] * S[1] + P[23] * S[2];
  const double s3 = P[28] * S[0] + P[29] * S[1] + P[30] * S[2];
  const double s4 = P[35] * S[0] + P[36] * S[1] + P[37] * S[2];

  vec2 Pmult1 = { P[3], P[4] };
  vec4 Pmult2 = { P[5], P[42], P[43], P[44] };

  vec2 dXdL0_dYdL0;
  vload(dXdL0_dYdL0, &P[7]);
  vec4 dZdL0_dAxdL0_dAydL0_dAzdL0;
  vload(dZdL0_dAxdL0_dAydL0_dAzdL0, &P[9]);
  dXdL0_dYdL0 -= s0 * Pmult1;
  dZdL0_dAxdL0_dAydL0_dAzdL0 -= s0 * Pmult2;
  vstore(&P[7], dXdL0_dYdL0);
  vstore(&P[9], dZdL0_dAxdL0_dAydL0_dAzdL0);

  vec2 dXdL1_dYdL1;
  vload(dXdL1_dYdL1, &P[14]);
  vec4 dZdL1_dAxdL1_dAydL1_dAzdL1;
  vload(dZdL1_dAxdL1_dAydL1_dAzdL1, &P[16]);
  dXdL1_dYdL1 -= s1 * Pmult1;
  dZdL1_dAxdL1_dAydL1_dAzdL1 -= s1 * Pmult2;
  vstore(&P[14], dXdL1_dYdL1);
  vstore(&P[16], dZdL1_dAxdL1_dAydL1_dAzdL1);

  vec2 dXdPhi_dYdPhi;
  vload(dXdPhi_dYdPhi, &P[21]);
  vec4 dZdPhi_dAxdPhi_dAydPhi_dAzdPhi;
  vload(dZdPhi_dAxdPhi_dAydPhi_dAzdPhi, &P[23]);
  dXdPhi_dYdPhi -= s2 * Pmult1;
  dZdPhi_dAxdPhi_dAydPhi_dAzdPhi -= s2 * Pmult2;
  vstore(&P[21], dXdPhi_dYdPhi);
  vstore(&P[23], dZdPhi_dAxdPhi_dAydPhi_dAzdPhi);

  vec2 dXdTheta_dYdTheta;
  vload(dXdTheta_dYdTheta, &P[28]);
  vec4 dZdTheta_dAxdTheta_dAydTheta_dAzdTheta;
  vload(dZdTheta_dAxdTheta_dAydTheta_dAzdTheta, &P[30]);
  dXdTheta_dYdTheta -= s3 * Pmult1;
  dZdTheta_dAxdTheta_dAydTheta_dAzdTheta -= s3 * Pmult2;
  vstore(&P[28], dXdTheta_dYdTheta);
  vstore(&P[30], dZdTheta_dAxdTheta_dAydTheta_dAzdTheta);

  vec2 dXdCM_dYdCM;
  vload(dXdCM_dYdCM, &P[35]);
  vec4 dZdCM_dAxdCM_AydCM_dAzdCM;
  vload(dZdCM_dAxdCM_AydCM_dAzdCM, &P[37]);
  dXdCM_dYdCM -= s4 * Pmult1;
  dZdCM_dAxdCM_AydCM_dAzdCM -= s4 * Pmult2;
  vstore(&P[35], dXdCM_dYdCM);
  vstore(&P[37], dZdCM_dAxdCM_AydCM_dAzdCM);

  return P[7];
}
/*
 * Implementation from Scott Snyder
 */

void
Pstruct6::fromP(const double* __restrict__ P) __restrict__
{
  pos[0] = P[0];
  pos[1] = P[1];
  pos[2] = P[2];
  dir[0] = P[3];
  dir[1] = P[4];
  dir[2] = P[5];
  CM = P[6];

  int ip = 7;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      dX[i][j] = P[ip++];
      dY[i][j] = P[ip++];
      dZ[i][j] = P[ip++];
      dAx[i][j] = P[ip++];
      dAy[i][j] = P[ip++];
      dAz[i][j] = P[ip++];
      dCM[i][j] = P[ip++];
    }
  }

  dX[2][0] = P[35];
  dY[2][0] = P[36];
  dZ[2][0] = P[37];
  dAx[2][0] = P[38];
  dAy[2][0] = P[39];
  dAz[2][0] = P[40];

  dX[2][1] = 0;
  dY[2][1] = 0;
  dZ[2][1] = 0;
  dAx[2][1] = 0;
  dAy[2][1] = 0;
  dAz[2][1] = 0;

  dCMdCM = P[41];

  dAds[0] = P[42];
  dAds[1] = P[43];
  dAds[2] = P[44];
}

void
Pstruct6::toP(double* __restrict__ P) const __restrict__
{
  P[0] = pos[0];
  P[1] = pos[1];
  P[2] = pos[2];
  P[3] = dir[0];
  P[4] = dir[1];
  P[5] = dir[2];
  P[6] = CM;

  int ip = 7;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      P[ip++] = dX[i][j];
      P[ip++] = dY[i][j];
      P[ip++] = dZ[i][j];
      P[ip++] = dAx[i][j];
      P[ip++] = dAy[i][j];
      P[ip++] = dAz[i][j];
      P[ip++] = dCM[i][j];
    }
  }

  P[35] = dX[2][0];
  P[36] = dY[2][0];
  P[37] = dZ[2][0];
  P[38] = dAx[2][0];
  P[39] = dAy[2][0];
  P[40] = dAz[2][0];

  P[41] = dCMdCM;

  P[42] = dAds[0];
  P[43] = dAds[1];
  P[44] = dAds[2];
}

double
transformVec6(Pstruct6& __restrict__ P, const double* __restrict__ S)
{
  using vec2 = Pstruct6::vec2;

  for (int i = 0; i < 3; i++) {
    vec2 s = S[0] * P.dX[i] + S[1] * P.dY[i] + S[2] * P.dZ[i];

    P.dX[i] -= s * P.dir[0];
    P.dY[i] -= s * P.dir[1];
    P.dZ[i] -= s * P.dir[2];

    P.dAx[i] -= s * P.dAds[0];
    P.dAy[i] -= s * P.dAds[1];
    P.dAz[i] -= s * P.dAds[2];
  }
  return P.dX[0][0];
}
