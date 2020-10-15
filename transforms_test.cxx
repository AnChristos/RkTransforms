#include "transforms.h"
#include <iostream>

int
main()
{


  double P[45] = {};
  double Pvec[45] = {};
  std::cout << "={";
  for (int i = 0; i < 45; ++i) {
    P[i] = 1e-02 * (i + 1);
    Pvec[i] = P[i];
    std::cout << P[i] << ", ";
    if (i != 0 && i % 4 == 0) {
      std::cout << '\n';
    }
  }
  std::cout << "}; " << '\n';

  globalToLocalHelper(P, 0.1,0.2,0.3,0.4,0.5);
  globalToLocalVecHelper(Pvec, 0.1,0.2,0.3,0.4,0.5);

  std::cout << '\n' << '\n';
  for (int i = 0; i < 45; ++i) {
    std::cout << P[i] << " , " << Pvec[i] << " , " << '\n';
  }

  return 0;
}

