#include "transforms.h"
#include <iostream>

int
main()
{

  const double S[3] = { 0.4, 0.2, 0.9 };

  double P[45] = {};
  double Pvec[45] = {};
  double Pvec2[45] = {};
  double Pvec6[45] = {};
  std::cout << "={";
  for (int i = 0; i < 45; ++i) {
    P[i] = 1e-02 * (i + 1);
    Pvec[i] = P[i];
    Pvec2[i] = P[i];
    Pvec6[i] = P[i];
    std::cout << P[i] << ", ";
    if (i != 0 && i % 4 == 0) {
      std::cout << '\n';
    }
  }
  std::cout << "}; " << '\n';

  Pstruct6 Ps;
  Ps.fromP(P);
  transformVec6(Ps, S);
  double Pvec6out[45] = {};
  Ps.toP(Pvec6out);

  transform(P, S);
  transformVec(Pvec, S);
  transformVec2(Pvec2, S);
  transformVec6Transf(Pvec6, S);

  std::cout << '\n' << '\n';
  for (int i = 0; i < 45; ++i) {
    std::cout << P[i] << " , " << Pvec[i] << " , " << Pvec2[i] << " , "
              << Pvec6[i] << " , " << Pvec6out[i] << '\n';
  }

  return 0;
}

