#include "transforms.h"
void
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
}

void
transformVec(double* __restrict__ P, const double* __restrict__ S)
{
  using namespace CxxUtils;
  vec<double, 2> Pin1{ P[7], P[8] };
  vec<double, 2> Pin2{ P[9], P[10] };
  vec<double, 2> Pin3{ P[11], P[12] };

  vec<double, 2> Pin4{ P[14], P[15] };
  vec<double, 2> Pin5{ P[16], P[17] };
  vec<double, 2> Pin6{ P[18], P[19] };

  vec<double, 2> Pin7{ P[21], P[22] };
  vec<double, 2> Pin8{ P[23], P[24] };
  vec<double, 2> Pin9{ P[25], P[26] };

  vec<double, 2> Pin10{ P[28], P[29] };
  vec<double, 2> Pin11{ P[30], P[31] };
  vec<double, 2> Pin12{ P[32], P[33] };

  vec<double, 2> Pin13{ P[35], P[36] };
  vec<double, 2> Pin14{ P[37], P[38] };
  vec<double, 2> Pin15{ P[39], P[40] };

  const double s0 = Pin1[0] * S[0] + Pin1[1] * S[1] + Pin2[0] * S[2];
  const double s1 = Pin4[0] * S[0] + Pin4[1] * S[1] + Pin5[0] * S[2];
  const double s2 = Pin7[0] * S[0] + Pin7[1] * S[1] + Pin8[0] * S[2];
  const double s3 = Pin10[0] * S[0] + Pin10[1] * S[1] + Pin11[0] * S[2];
  const double s4 = Pin13[0] * S[0] + Pin13[1] * S[1] + Pin14[0] * S[2];

  vec<double, 2> Pmult1 = { P[3], P[4] };
  vec<double, 2> Pmult2 = { P[5], P[42] };
  vec<double, 2> Pmult3 = { P[43], P[44] };

  Pin1 -= s0 * Pmult1;
  Pin2 -= s0 * Pmult2;
  Pin3 -= s0 * Pmult3;
  vstore(&P[7], Pin1);
  vstore(&P[9], Pin2);
  vstore(&P[11], Pin3);

  Pin4 -= s1 * Pmult1;
  Pin5 -= s1 * Pmult2;
  Pin6 -= s1 * Pmult3;
  vstore(&P[14], Pin4);
  vstore(&P[16], Pin5);
  vstore(&P[18], Pin6);

  Pin7 -= s2 * Pmult1;
  Pin8 -= s2 * Pmult2;
  Pin9 -= s2 * Pmult3;
  vstore(&P[21], Pin7);
  vstore(&P[23], Pin8);
  vstore(&P[25], Pin9);

  Pin10 -= s3 * Pmult1;
  Pin11 -= s3 * Pmult2;
  Pin12 -= s3 * Pmult3;
  vstore(&P[28], Pin10);
  vstore(&P[30], Pin11);
  vstore(&P[32], Pin12);

  Pin13 -= s4 * Pmult1;
  Pin14 -= s4 * Pmult2;
  Pin15 -= s4 * Pmult3;
  vstore(&P[35], Pin13);
  vstore(&P[37], Pin14);
  vstore(&P[39], Pin15);
}


void transformVec2(double* __restrict__ P, const double* __restrict__ S) {
  using namespace CxxUtils;
  vec<double, 2> Pin1;
  vload(Pin1, &P[7]);
  vec<double, 2> Pin2;
  vload(Pin2, &P[9]);
  vec<double, 2> Pin3;
  vload(Pin3, &P[11]);
  vec<double, 2> Pin4;
  vload(Pin4, &P[14]);
  vec<double, 2> Pin5;
  vload(Pin5, &P[16]);
  vec<double, 2> Pin6;
  vload(Pin6, &P[18]);
  vec<double, 2> Pin7;
  vload(Pin7, &P[21]);
  vec<double, 2> Pin8;
  vload(Pin8, &P[23]);
  vec<double, 2> Pin9;
  vload(Pin9, &P[25]);
  vec<double, 2> Pin10;
  vload(Pin10, &P[28]);
  vec<double, 2> Pin11;
  vload(Pin11, &P[30]);
  vec<double, 2> Pin12;
  vload(Pin12, &P[32]);
  vec<double, 2> Pin13;
  vload(Pin13, &P[35]);
  vec<double, 2> Pin14;
  vload(Pin14, &P[37]);
  vec<double, 2> Pin15;
  vload(Pin15, &P[39]);

  vec<double, 2> multS{S[0], S[1]};
  vec<double, 2> multS0 = Pin1 * multS;
  vec<double, 2> multS1 = Pin4 * multS;
  vec<double, 2> multS2 = Pin7 * multS;
  vec<double, 2> multS3 = Pin10 * multS;
  vec<double, 2> multS4 = Pin13 * multS;
  const double s0 = multS0[0] + multS0[1] + Pin2[0] * S[2];
  const double s1 = multS1[0] + multS1[1] + Pin5[0] * S[2];
  const double s2 = multS2[0] + multS2[1] + Pin8[0] * S[2];
  const double s3 = multS3[0] + multS3[1] + Pin11[0] * S[2];
  const double s4 = multS4[0] + multS4[1] + Pin14[0] * S[2];

  vec<double, 2> Pmult1 = {P[3], P[4]};
  vec<double, 2> Pmult2 = {P[5], P[42]};
  vec<double, 2> Pmult3 = {P[43], P[44]};

  Pin1 -= s0 * Pmult1;
  Pin2 -= s0 * Pmult2;
  Pin3 -= s0 * Pmult3;
  vstore(&P[7], Pin1);
  vstore(&P[9], Pin2);
  vstore(&P[11], Pin3);

  Pin4 -= s1 * Pmult1;
  Pin5 -= s1 * Pmult2;
  Pin6 -= s1 * Pmult3;
  vstore(&P[14], Pin4);
  vstore(&P[16], Pin5);
  vstore(&P[18], Pin6);

  Pin7 -= s2 * Pmult1;
  Pin8 -= s2 * Pmult2;
  Pin9 -= s2 * Pmult3;
  vstore(&P[21], Pin7);
  vstore(&P[23], Pin8);
  vstore(&P[25], Pin9);

  Pin10 -= s3 * Pmult1;
  Pin11 -= s3 * Pmult2;
  Pin12 -= s3 * Pmult3;
  vstore(&P[28], Pin10);
  vstore(&P[30], Pin11);
  vstore(&P[32], Pin12);

  Pin13 -= s4 * Pmult1;
  Pin14 -= s4 * Pmult2;
  Pin15 -= s4 * Pmult3;
  vstore(&P[35], Pin13);
  vstore(&P[37], Pin14);
  vstore(&P[39], Pin15);
}
