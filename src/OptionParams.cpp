#include "OptionParams.h"

OptionParams::OptionParams(double InitialPriceOfAsset, double StrikePrice,
                           double Volatility, double InterestRate,
                           double TimeToMaturity, double BarrierLevel)
    : InitialPriceOfAsset(InitialPriceOfAsset),
      StrikePrice(StrikePrice),
      Volatility(Volatility),
      InterestRate(InterestRate),
      TimeToMaturity(TimeToMaturity),
      BarrierLevel(BarrierLevel){};