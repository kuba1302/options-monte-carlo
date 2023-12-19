#include "UpAndInCallPayoff.h"

#include <algorithm>

UpAndInCallPayoff::UpAndInCallPayoff(double StrikePrice, double BarrierLevel)
    : StrikePrice(StrikePrice), BarrierLevel(BarrierLevel) {}

double UpAndInCallPayoff::operator()(double spot) const {
  if (spot >= BarrierLevel) {
    return std::max(spot - StrikePrice, 0.0);
  }
  return 0.0;
}