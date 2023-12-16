#include "Payoff.h"

#ifndef UP_AND_IN_CALL_PAYOFF_H
#define UP_AND_IN_CALL_PAYOFF_H

class UpAndInCallPayoff : public Payoff {
 private:
  double K;
  double B;

 public:
  virtual double operator()(double spot) const = 0;
};

#endif
