#include "OptionParams.h"

class OptionParams {
 public:
  double S0;
  double K;
  double sigma;
  double r;
  double T;
  double B;

  OptionParams(double S0, double K, double sigma, double r, double T, double B);
};