#include "GaussianByBoxMuellerRNG.h"

#include <cmath>
#include <cstdlib>

double GaussianByBoxMuellerRNG ::generate() {
  // Implementation taken from
  // https://github.com/pawelsakowski/AF-RCPP-2023-2024/blob/main/packages/optionPricer2/src/getOneGaussianByBoxMueller.cpp
  double result;
  double x;
  double y;
  double sizeSquared;
  do {
    x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
    y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
    sizeSquared = x * x + y * y;
  } while (sizeSquared >= 1.0);

  result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);

  return result;
}