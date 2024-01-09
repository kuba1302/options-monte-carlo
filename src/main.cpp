#include <Rcpp.h>

#include <iostream>

#include "GaussianByBoxMuellerRNG.h"
#include "MonteCarloPricer.h"
#include "OptionParams.h"
#include "UpAndInCallPayoff.h"

using namespace Rcpp;

double getUpAndInCallPrice(double InitialPriceOfAsset, double StrikePrice,
                           double Volatility, double InterestRate,
                           double TimeToMaturity, double BarrierLevel,
                           int numSimulations, int numTimeSteps) {
  auto params = std::make_unique<OptionParams>(InitialPriceOfAsset, StrikePrice,
                                               Volatility, InterestRate,
                                               TimeToMaturity, BarrierLevel);
  auto rng = std::make_unique<GaussianByBoxMuellerRNG>();
  auto payoff = std::make_unique<UpAndInCallPayoff>(params->StrikePrice,
                                                    params->BarrierLevel);

  MonteCarloPricer pricer(std::move(payoff), std::move(rng), std::move(params));

  double price = pricer.calculate(numSimulations, numTimeSteps);
  std::cout << "Price: " << price << '\n';
  return price;
}