#ifndef PAYOFF_H
#define PAYOFF_H

class Payoff {
 public:
  virtual ~Payoff() {}
  virtual double operator()(double spot) const = 0;
};

#endif
