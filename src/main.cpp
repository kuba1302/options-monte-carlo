#include <iostream>

#include "GaussianByBoxMuellerRNG.h"
#include "MonteCarloPricer.h"
#include "OptionParams.h"
#include "UpAndInCallPayoff.h"

int main() {
  auto params = std::make_unique<OptionParams>(140, 150, 0.24, 0.07, 0.75, 141);
  auto rng = std::make_unique<GaussianByBoxMuellerRNG>();
  auto payoff = std::make_unique<UpAndInCallPayoff>(params->StrikePrice,
                                                    params->BarrierLevel);

  MonteCarloPricer pricer(std::move(payoff), std::move(rng), std::move(params));

  int numSimulations = 100000;
  int numTimeSteps = 100;

  double price = pricer.calculate(numSimulations, numTimeSteps);
  std::cout << "Price: " << price << '\n';
}