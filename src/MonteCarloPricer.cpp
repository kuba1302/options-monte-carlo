#include "MonteCarloPricer.h"

#include <cmath>
#include <spdlog>

MonteCarloPricer::MonteCarloPricer(
    std::unique_ptr<Payoff> payoff,
    std::unique_ptr<RandomNumberGeneratorBase> rng, double InterestRate,
    double timeToMaturity, int numSimulations)
    : payoff(std::move(payoff)),
      rng(std::move(rng)),
      InterestRate(InterestRate),
      TimeToMaturity(timeToMaturity),
      numSimulations(numSimulations) {}

double MonteCarloPricer::calculate() const {
  double discountFactor = std::exp(-InterestRate * TimeToMaturity);
  double sumPayoffs = 0.0;

  for (int i = 0; i < numSimulations; ++i) {
    if (i % 1000 == 0) {
      spdlog::info("Simulation: {}", i);
    }
    double spot = rng->generate();
    double payoffResult = (*payoff)(spot);
    sumPayoffs += payoffResult;
  }

  double meanPayoff = sumPayoffs / numSimulations;
  return meanPayoff * discountFactor;
}
