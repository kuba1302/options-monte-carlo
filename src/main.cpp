#include <spdlog>

#include "GaussianByBoxMuellerRNG.h"
#include "MonteCarloPricer.h"
#include "OptionParams.h"
#include "Payoff.h"
#include "UpAndInCallPayoff.h"

void main() {
  OptionParams params = OptionParams(140, 150, 0.24, 0.07, 0.75, 160);
  GaussianByBoxMuellerRNG rng = GaussianByBoxMuellerRNG();
  UpAndInCallPayoff payoff =
      UpAndInCallPayoff(params.StrikePrice, params.BarrierLevel);
  MonteCarloPricer pricer =
      MonteCarloPricer(std::make_unique<UpAndInCallPayoff>(payoff),
                       std::make_unique<GaussianByBoxMuellerRNG>(rng),
                       params.InterestRate, params.TimeToMaturity, 10000);
  double price = pricer.calculate();
  spdlog::info("Price: {}", price);