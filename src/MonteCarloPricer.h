#ifndef PRICE_H
#define PRICE_H

#include <memory>

#include "OptionParams.h"
#include "Payoff.h"
#include "RandomNumberGeneratorBase.h"
class MonteCarloPricer {
 private:
  std::unique_ptr<Payoff> payoff;
  std::unique_ptr<RandomNumberGeneratorBase> rng;
  std::unique_ptr<OptionParams> params;

 public:
  MonteCarloPricer(std::unique_ptr<Payoff> payoff,
                   std::unique_ptr<RandomNumberGeneratorBase> rng,
                   std::unique_ptr<OptionParams> params);
  ~MonteCarloPricer() = default;

  double calculate(int numSimulations, int numTimeSteps) const;
  std::pair<bool, double> simulatePricePath(int numTimeSteps, double dt) const;
};

#endif