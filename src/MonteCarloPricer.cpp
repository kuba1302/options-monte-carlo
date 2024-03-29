#include "MonteCarloPricer.h"

#include <cmath>

MonteCarloPricer::MonteCarloPricer(
    std::unique_ptr<Payoff> payoff,
    std::unique_ptr<RandomNumberGeneratorBase> rng,
    std::unique_ptr<OptionParams> params)
    : payoff(std::move(payoff)),
      rng(std::move(rng)),
      params(std::move(params)) {}

std::pair<bool, double> MonteCarloPricer::simulatePricePath(int numTimeSteps,
                                                            double dt) const {
  double spot = params->InitialPriceOfAsset;
  bool barrierBreached = false;

  for (int j = 0; j < numTimeSteps; ++j) {
    double gauss_bm = rng->generate();
    // Use geometric brownian motion to simulate the price path
    spot *= exp(
        (params->InterestRate - 0.5 * params->Volatility * params->Volatility) *
            dt +
        params->Volatility * gauss_bm * sqrt(dt));

    if (spot >= params->BarrierLevel) {
      barrierBreached = true;
    }
  }

  return {barrierBreached, spot};
}

double MonteCarloPricer::calculate(int numSimulations, int numTimeSteps) const {
  double discountFactor =
      std::exp(-params->InterestRate * params->TimeToMaturity);
  double sumPayoffs = 0.0;
  double dt = params->TimeToMaturity / numTimeSteps;

  for (int i = 0; i < numSimulations; ++i) {
    auto [barrierBreached, spot] = simulatePricePath(numTimeSteps, dt);

    double payoffResult = 0.0;
    if (barrierBreached) {
      payoffResult = (*payoff)(spot);
    }
    sumPayoffs += payoffResult;
  }

  double meanPayoff = sumPayoffs / numSimulations;
  return meanPayoff * discountFactor;
}
