#ifndef OPTION_H
#define OPTION_H

class Option {
 protected:
  double strikePrice;
  double underlyingPrice;
  double volatility;
  double riskFreeRate;
  double timeToMaturity;

  Option(double strike, double underlying, double vol, double rate, double time)
      : strikePrice(strike),
        underlyingPrice(underlying),
        volatility(vol),
        riskFreeRate(rate),
        timeToMaturity(time) {}

  virtual ~Option() {}
  virtual double payoff() const = 0;
  virtual double price() const = 0;
}

#endif