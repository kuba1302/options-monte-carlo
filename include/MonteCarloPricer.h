#ifndef PRICE_H
#define PRICE_H

#include <memory>

#include "Payoff.h"
#include "RandomNumberGeneratorBase.h"

class MonteCarloPricer {
 private:
  std::unique_ptr<Payoff> payoff;
  std::unique_ptr<RandomNumberGeneratorBase> rng;
  double InterestRate;
  double TimeToMaturity;
  int numSimulations;

 public:
  MonteCarloPricer(std::unique_ptr<Payoff> payoff,
                   std::unique_ptr<RandomNumberGeneratorBase> rng,
                   double InterestRate, double TimeToMaturity,
                   int numSimulations);
  virtual ~MonteCarloPricer() = default;

  virtual double calculate() const = 0;
};

#endif