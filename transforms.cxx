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

  vec2 dXdY_dL0{ P[7], P[8] };
  vec2 dZdAx_dL0{ P[9], P[10] };
  vec2 dAydAz_dL0{ P[11], P[12] };

  vec2 dXdY_dL1{ P[14], P[15] };
  vec2 dZdAx_dL1{ P[16], P[17] };
  vec2 dAydAz_dL1{ P[18], P[19] };

  vec2 dXdY_dPhi{ P[21], P[22] };
  vec2 dZdAx_dPhi{ P[23], P[24] };
  vec2 dAydAz_dPhi{ P[25], P[26] };

  vec2 dXdY_dTheta{ P[28], P[29] };
  vec2 dZdAx_dTheta{ P[30], P[31] };
  vec2 dAydAz_dTheta{ P[32], P[33] };

  vec2 dXdY_dCM{ P[35], P[36] };
  vec2 dZdAx_dCM{ P[37], P[38] };
  vec2 dydAz_dCM{ P[39], P[40] };

  const double s0 =
    dXdY_dL0[0] * S[0] + dXdY_dL0[1] * S[1] + dZdAx_dL0[0] * S[2];
  const double s1 =
    dXdY_dL1[0] * S[0] + dXdY_dL1[1] * S[1] + dZdAx_dL1[0] * S[2];
  const double s2 =
    dXdY_dPhi[0] * S[0] + dXdY_dPhi[1] * S[1] + dZdAx_dPhi[0] * S[2];
  const double s3 =
    dXdY_dTheta[0] * S[0] + dXdY_dTheta[1] * S[1] + dZdAx_dTheta[0] * S[2];
  const double s4 =
    dXdY_dCM[0] * S[0] + dXdY_dCM[1] * S[1] + dZdAx_dCM[0] * S[2];

  vec2 Pmult1 = { P[3], P[4] };
  vec2 Pmult2 = { P[5], P[42] };
  vec2 Pmult3 = { P[43], P[44] };

  dXdY_dL0 -= s0 * Pmult1;
  dZdAx_dL0 -= s0 * Pmult2;
  dAydAz_dL0 -= s0 * Pmult3;
  vstore(&P[7], dXdY_dL0);
  vstore(&P[9], dZdAx_dL0);
  vstore(&P[11], dAydAz_dL0);

  dXdY_dL1 -= s1 * Pmult1;
  dZdAx_dL1 -= s1 * Pmult2;
  dAydAz_dL1 -= s1 * Pmult3;
  vstore(&P[14], dXdY_dL1);
  vstore(&P[16], dZdAx_dL1);
  vstore(&P[18], dAydAz_dL1);

  dXdY_dPhi -= s2 * Pmult1;
  dZdAx_dPhi -= s2 * Pmult2;
  dAydAz_dPhi -= s2 * Pmult3;
  vstore(&P[21], dXdY_dPhi);
  vstore(&P[23], dZdAx_dPhi);
  vstore(&P[25], dAydAz_dPhi);

  dXdY_dTheta -= s3 * Pmult1;
  dZdAx_dTheta -= s3 * Pmult2;
  dAydAz_dTheta -= s3 * Pmult3;
  vstore(&P[28], dXdY_dTheta);
  vstore(&P[30], dZdAx_dTheta);
  vstore(&P[32], dAydAz_dTheta);

  dXdY_dCM -= s4 * Pmult1;
  dZdAx_dCM -= s4 * Pmult2;
  dydAz_dCM -= s4 * Pmult3;
  vstore(&P[35], dXdY_dCM);
  vstore(&P[37], dZdAx_dCM);
  vstore(&P[39], dydAz_dCM);

  return P[7];
}

double
transformVec2(double* __restrict__ P, const double* __restrict__ S)
{
  using namespace CxxUtils;
  using vec2 = CxxUtils::vec<double, 2>;

  vec2 dXdY_dL0;
  vload(dXdY_dL0, &P[7]);
  vec2 multS{ S[0], S[1] };
  vec2 multS0 = dXdY_dL0 * multS;

  vec2 dXdY_dL1;
  vload(dXdY_dL1, &P[14]);
  vec2 multS1 = dXdY_dL1 * multS;

  vec2 dXdY_dPhi;
  vload(dXdY_dPhi, &P[21]);
  vec2 multS2 = dXdY_dPhi * multS;

  vec2 dXdY_dTheta;
  vload(dXdY_dTheta, &P[28]);
  vec2 multS3 = dXdY_dTheta * multS;

  vec2 dXdY_dCM;
  vload(dXdY_dCM, &P[35]);
  vec2 multS4 = dXdY_dCM * multS;

  const double s0 = multS0[0] + multS0[1] + P[9] * S[2];
  const double s1 = multS1[0] + multS1[1] + P[16] * S[2];
  const double s2 = multS2[0] + multS2[1] + P[23] * S[2];
  const double s3 = multS3[0] + multS3[1] + P[30] * S[2];
  const double s4 = multS4[0] + multS4[1] + P[37] * S[2];

  vec2 dZdAx_dL0;
  vload(dZdAx_dL0, &P[9]);
  vec2 dAydAz_dL0;
  vload(dAydAz_dL0, &P[11]);

  vec2 dZdAx_dL1;
  vload(dZdAx_dL1, &P[16]);
  vec2 dAydAz_dL1;
  vload(dAydAz_dL1, &P[18]);

  vec2 dZdAx_dPhi;
  vload(dZdAx_dPhi, &P[23]);
  vec2 dAydAz_dPhi;
  vload(dAydAz_dPhi, &P[25]);

  vec2 dZdAx_dTheta;
  vload(dZdAx_dTheta, &P[30]);
  vec2 dAydAz_dTheta;
  vload(dAydAz_dTheta, &P[32]);

  vec2 dZdAx_dCM;
  vload(dZdAx_dCM, &P[37]);
  vec2 dydAz_dCM;
  vload(dydAz_dCM, &P[39]);

  vec2 Pmult1 = { P[3], P[4] };
  vec2 Pmult2 = { P[5], P[42] };
  vec2 Pmult3 = { P[43], P[44] };

  dXdY_dL0 -= s0 * Pmult1;
  dZdAx_dL0 -= s0 * Pmult2;
  dAydAz_dL0 -= s0 * Pmult3;
  vstore(&P[7], dXdY_dL0);
  vstore(&P[9], dZdAx_dL0);
  vstore(&P[11], dAydAz_dL0);

  dXdY_dL1 -= s1 * Pmult1;
  dZdAx_dL1 -= s1 * Pmult2;
  dAydAz_dL1 -= s1 * Pmult3;
  vstore(&P[14], dXdY_dL1);
  vstore(&P[16], dZdAx_dL1);
  vstore(&P[18], dAydAz_dL1);

  dXdY_dPhi -= s2 * Pmult1;
  dZdAx_dPhi -= s2 * Pmult2;
  dAydAz_dPhi -= s2 * Pmult3;
  vstore(&P[21], dXdY_dPhi);
  vstore(&P[23], dZdAx_dPhi);
  vstore(&P[25], dAydAz_dPhi);

  dXdY_dTheta -= s3 * Pmult1;
  dZdAx_dTheta -= s3 * Pmult2;
  dAydAz_dTheta -= s3 * Pmult3;
  vstore(&P[28], dXdY_dTheta);
  vstore(&P[30], dZdAx_dTheta);
  vstore(&P[32], dAydAz_dTheta);

  dXdY_dCM -= s4 * Pmult1;
  dZdAx_dCM -= s4 * Pmult2;
  dydAz_dCM -= s4 * Pmult3;
  vstore(&P[35], dXdY_dCM);
  vstore(&P[37], dZdAx_dCM);
  vstore(&P[39], dydAz_dCM);

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
transformVec6Transf(double* __restrict__ P_in, const double* __restrict__ S)
{
  using vec2 = Pstruct6::vec2;
  Pstruct6 P;
  P.fromP(P_in);
  for (int i = 0; i < 3; i++) {
    vec2 s = S[0] * P.dX[i] + S[1] * P.dY[i] + S[2] * P.dZ[i];
    P.dX[i] -= s * P.dir[0];
    P.dY[i] -= s * P.dir[1];
    P.dZ[i] -= s * P.dir[2];
    P.dAx[i] -= s * P.dAds[0];
    P.dAy[i] -= s * P.dAds[1];
    P.dAz[i] -= s * P.dAds[2];
  }
  P.toP(P_in);
  return P_in[7];
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
