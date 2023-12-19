#include "Payoff.h"

#ifndef UP_AND_IN_CALL_PAYOFF_H
#define UP_AND_IN_CALL_PAYOFF_H

class UpAndInCallPayoff : public Payoff {
 private:
  double StrikePrice;
  double BarrierLevel;

 public:
  UpAndInCallPayoff(double StrikePrice, double B);
  virtual double operator()(double spot) const = 0;
};

#endif
