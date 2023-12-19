#ifndef OPTIONPARAMS_H
#define OPTIONPARAMS_H

class OptionParams {
 public:
  double InitialPriceOfAsset;
  double StrikePrice;
  double Volatility;
  double InterestRate;
  double TimeToMaturity;
  double BarrierLevel;

  OptionParams(double InitialPriceOfAsset, double StrikePrice,
               double Volatility, double InterestRate, double TimeToMaturity,
               double BarrierLevel);
};

#endif
