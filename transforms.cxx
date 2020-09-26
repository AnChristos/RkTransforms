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
transformVec(double* __restrict__ P, const double* __restrict__ S)
{
  using namespace CxxUtils;
  using vec2 = CxxUtils::vec<double, 2>;

  vec2 dXdL0_dYdL0{ P[7], P[8] };
  vec2 dZdL0_dAxdL0{ P[9], P[10] };
  vec2 dAydL0_dAzdL0{ P[11], P[12] };

  vec2 dXdL1_dYdL1{ P[14], P[15] };
  vec2 dZdL1_dAxdL1{ P[16], P[17] };
  vec2 dAydL1_dAzdL1{ P[18], P[19] };

  vec2 dXdPhi_dYdPhi{ P[21], P[22] };
  vec2 dZdPhi_dAxdPhi{ P[23], P[24] };
  vec2 dAydPhi_dAzdPhi{ P[25], P[26] };

  vec2 dXdTheta_dYdTheta{ P[28], P[29] };
  vec2 dZdTheta_dAxdTheta{ P[30], P[31] };
  vec2 dAydTheta_dAzdTheta{ P[32], P[33] };

  vec2 dXdCM_dYdCM{ P[35], P[36] };
  vec2 dZdCM_dAxdCM{ P[37], P[38] };
  vec2 dAydCM_dAzdCM{ P[39], P[40] };

  const double s0 =
    dXdL0_dYdL0[0] * S[0] + dXdL0_dYdL0[1] * S[1] + dZdL0_dAxdL0[0] * S[2];
  const double s1 =
    dXdL1_dYdL1[0] * S[0] + dXdL1_dYdL1[1] * S[1] + dZdL1_dAxdL1[0] * S[2];
  const double s2 = dXdPhi_dYdPhi[0] * S[0] + dXdPhi_dYdPhi[1] * S[1] +
                    dZdPhi_dAxdPhi[0] * S[2];
  const double s3 = dXdTheta_dYdTheta[0] * S[0] + dXdTheta_dYdTheta[1] * S[1] +
                    dZdTheta_dAxdTheta[0] * S[2];
  const double s4 =
    dXdCM_dYdCM[0] * S[0] + dXdCM_dYdCM[1] * S[1] + dZdCM_dAxdCM[0] * S[2];

  vec2 Pmult1 = { P[3], P[4] };
  vec2 Pmult2 = { P[5], P[42] };
  vec2 Pmult3 = { P[43], P[44] };

  dXdL0_dYdL0 -= s0 * Pmult1;
  dZdL0_dAxdL0 -= s0 * Pmult2;
  dAydL0_dAzdL0 -= s0 * Pmult3;
  vstore(&P[7], dXdL0_dYdL0);
  vstore(&P[9], dZdL0_dAxdL0);
  vstore(&P[11], dAydL0_dAzdL0);

  dXdL1_dYdL1 -= s1 * Pmult1;
  dZdL1_dAxdL1 -= s1 * Pmult2;
  dAydL1_dAzdL1 -= s1 * Pmult3;
  vstore(&P[14], dXdL1_dYdL1);
  vstore(&P[16], dZdL1_dAxdL1);
  vstore(&P[18], dAydL1_dAzdL1);

  dXdPhi_dYdPhi -= s2 * Pmult1;
  dZdPhi_dAxdPhi -= s2 * Pmult2;
  dAydPhi_dAzdPhi -= s2 * Pmult3;
  vstore(&P[21], dXdPhi_dYdPhi);
  vstore(&P[23], dZdPhi_dAxdPhi);
  vstore(&P[25], dAydPhi_dAzdPhi);

  dXdTheta_dYdTheta -= s3 * Pmult1;
  dZdTheta_dAxdTheta -= s3 * Pmult2;
  dAydTheta_dAzdTheta -= s3 * Pmult3;
  vstore(&P[28], dXdTheta_dYdTheta);
  vstore(&P[30], dZdTheta_dAxdTheta);
  vstore(&P[32], dAydTheta_dAzdTheta);

  dXdCM_dYdCM -= s4 * Pmult1;
  dZdCM_dAxdCM -= s4 * Pmult2;
  dAydCM_dAzdCM -= s4 * Pmult3;
  vstore(&P[35], dXdCM_dYdCM);
  vstore(&P[37], dZdCM_dAxdCM);
  vstore(&P[39], dAydCM_dAzdCM);

  return P[7];
}

double
transformVec2(double* __restrict__ P, const double* __restrict__ S)
{
  using namespace CxxUtils;
  using vec2 = CxxUtils::vec<double, 2>;
  using vec4 = CxxUtils::vec<double, 4>;

  vec2 multS{ S[0], S[1] };

  vec2 dXdL0_dYdL0;
  vload(dXdL0_dYdL0, &P[7]);
  vec2 multS0 = dXdL0_dYdL0 * multS;

  vec2 dXdL1_dYdL1;
  vload(dXdL1_dYdL1, &P[14]);
  vec2 multS1 = dXdL1_dYdL1 * multS;

  vec2 dXdPhi_dYdPhi;
  vload(dXdPhi_dYdPhi, &P[21]);
  vec2 multS2 = dXdPhi_dYdPhi * multS;

  vec2 dXdTheta_dYdTheta;
  vload(dXdTheta_dYdTheta, &P[28]);
  vec2 multS3 = dXdTheta_dYdTheta * multS;

  vec2 dXdCM_dYdCM;
  vload(dXdCM_dYdCM, &P[35]);
  vec2 multS4 = dXdCM_dYdCM * multS;

  const double s0 = multS0[0] + multS0[1] + P[9] * S[2];
  const double s1 = multS1[0] + multS1[1] + P[16] * S[2];
  const double s2 = multS2[0] + multS2[1] + P[23] * S[2];
  const double s3 = multS3[0] + multS3[1] + P[30] * S[2];
  const double s4 = multS4[0] + multS4[1] + P[37] * S[2];

  vec4 dZdL0_dAxdL0_dAydL0_dAzdL0;
  vload(dZdL0_dAxdL0_dAydL0_dAzdL0, &P[9]);

  vec4 dZdL1_dAxdL1_dAydL1_dAzdL1;
  vload(dZdL1_dAxdL1_dAydL1_dAzdL1, &P[16]);

  vec4 dZdPhi_dAxdPhi_dAydPhi_dAzdPhi;
  vload(dZdPhi_dAxdPhi_dAydPhi_dAzdPhi, &P[23]);

  vec4 dZdTheta_dAxdTheta_dAydTheta_dAzdTheta;
  vload(dZdTheta_dAxdTheta_dAydTheta_dAzdTheta, &P[30]);

  vec4 dZdCM_dAxdCM_AydCM_dAzdCM;
  vload(dZdCM_dAxdCM_AydCM_dAzdCM, &P[37]);

  vec2 Pmult1 = { P[3], P[4] };
  vec4 Pmult2 = { P[5], P[42], P[43], P[44] };

  dXdL0_dYdL0 -= s0 * Pmult1;
  dZdL0_dAxdL0_dAydL0_dAzdL0 -= s0 * Pmult2;
  vstore(&P[7], dXdL0_dYdL0);
  vstore(&P[9], dZdL0_dAxdL0_dAydL0_dAzdL0);

  dXdL1_dYdL1 -= s1 * Pmult1;
  dZdL1_dAxdL1_dAydL1_dAzdL1 -= s1 * Pmult2;
  vstore(&P[14], dXdL1_dYdL1);
  vstore(&P[16], dZdL1_dAxdL1_dAydL1_dAzdL1);

  dXdPhi_dYdPhi -= s2 * Pmult1;
  dZdPhi_dAxdPhi_dAydPhi_dAzdPhi -= s2 * Pmult2;
  vstore(&P[21], dXdPhi_dYdPhi);
  vstore(&P[23], dZdPhi_dAxdPhi_dAydPhi_dAzdPhi);

  dXdTheta_dYdTheta -= s3 * Pmult1;
  dZdTheta_dAxdTheta_dAydTheta_dAzdTheta -= s3 * Pmult2;
  vstore(&P[28], dXdTheta_dYdTheta);
  vstore(&P[30], dZdTheta_dAxdTheta_dAydTheta_dAzdTheta);

  dXdCM_dYdCM -= s4 * Pmult1;
  dZdCM_dAxdCM_AydCM_dAzdCM -= s4 * Pmult2;
  vstore(&P[35], dXdCM_dYdCM);
  vstore(&P[37], dZdCM_dAxdCM_AydCM_dAzdCM);

  return P[7];
}
double
transformVec6Array(double* __restrict__ P, const double* __restrict__ S)
{

  using namespace CxxUtils;
  using vec2 = CxxUtils::vec<double, 2>;
  // dL0    /dL1    /dPhi   /dThe   /dCM
  //  dX /   P[ 7]   P[14]   P[21]   P[28]   P[35]
  vec2 dX0{ P[7], P[14] };
  vec2 dX1{ P[21], P[28] };
  vec2 dX2{ P[35] };

  //  dY /   P[ 8]   P[15]   P[22]   P[29]   P[36]
  vec2 dY0{ P[8], P[15] };
  vec2 dY1{ P[22], P[29] };
  vec2 dY2{ P[36] };

  // Z  ->P[2]  dZ /   P[ 9]   P[16]   P[23]   P[30]   P[37]
  vec2 dZ0{ P[9], P[16] };
  vec2 dZ1{ P[23], P[30] };
  vec2 dZ2{ P[37] };

  // dAx/   P[10]   P[17]   P[24]   P[31]   P[38]
  vec2 dAx0{ P[10], P[17] };
  vec2 dAx1{ P[24], P[31] };
  vec2 dAx2{ P[38] };

  // dAy/   P[11]   P[18]   P[25]   P[32]   P[39]
  vec2 dAy0{ P[11], P[18] };
  vec2 dAy1{ P[25], P[32] };
  vec2 dAy2{ P[39] };

  // dAz/   P[12]   P[19]   P[26]   P[33]   P[40]
  vec2 dAz0{ P[12], P[19] };
  vec2 dAz1{ P[26], P[33] };
  vec2 dAz2{ P[40] };

  // dCM/   P[13]   P[20]   P[27]   P[34]   P[41]
  vec2 dCM0{ P[13], P[20] };
  vec2 dCM1{ P[27], P[34] };
  vec2 dCM2{ P[41] };

  vec2 s0 = S[0] * dX0 + S[1] * dY0 + S[2] * dZ0;
  dX0 -= s0 * P[3];
  dY0 -= s0 * P[4];
  dZ0 -= s0 * P[5];
  dAx0 -= s0 * P[42];
  dAy0 -= s0 * P[43];
  dAz0 -= s0 * P[44];

  vec2 s1 = S[0] * dX1 + S[1] * dY1 + S[2] * dZ1;
  dX1 -= s1 * P[3];
  dY1 -= s1 * P[4];
  dZ1 -= s1 * P[5];
  dAx1 -= s1 * P[42];
  dAy1 -= s1 * P[43];
  dAz1 -= s1 * P[44];

  vec2 s2 = S[0] * dX2 + S[1] * dY2 + S[2] * dZ2;
  dX2 -= s2 * P[3];
  dY2 -= s2 * P[4];
  dZ2 -= s2 * P[5];
  dAx2 -= s2 * P[42];
  dAy2 -= s2 * P[43];
  dAz2 -= s2 * P[44];

  P[7] = dX0[0];
  P[8] = dY0[0];
  P[9] = dZ0[0];
  P[10] = dAx0[0];
  P[11] = dAy0[0];
  P[12] = dAz0[0];
  P[13] = dCM0[0];

  P[14] = dX0[1];
  P[15] = dY0[1];
  P[16] = dZ0[1];
  P[17] = dAx0[1];
  P[18] = dAy0[1];
  P[19] = dAz0[1];
  P[20] = dCM0[1];

  P[21] = dX1[0];
  P[22] = dY1[0];
  P[23] = dZ1[0];
  P[24] = dAx1[0];
  P[25] = dAy1[0];
  P[26] = dAz1[0];
  P[27] = dCM1[0];

  P[28] = dX1[1];
  P[29] = dY1[1];
  P[30] = dZ1[1];
  P[31] = dAx1[1];
  P[32] = dAy1[1];
  P[33] = dAz1[1];
  P[34] = dCM1[1];

  P[35] = dX2[0];
  P[36] = dY2[0];
  P[37] = dZ2[0];
  P[38] = dAx2[0];
  P[39] = dAy2[0];
  P[40] = dAz2[0];
  P[41] = dCM2[0];

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
