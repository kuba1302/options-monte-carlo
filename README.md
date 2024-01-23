# OptionMonteCarlo

OptionMonteCarlo is an Rcpp package providing efficient Monte Carlo simulations for pricing European style up-and-in call options. It allows users to assess the theoretical price of such options considering various market conditions.

## Installation

To install the latest version from GitHub:

```r
install.packages("devtools")
library(devtools)
devtools::install_github("kuba1302/options-monte-carlo")
```

## Usage
```r
library(OptionMonteCarlo)

# Set parameters
S0 <- 140         # Underlying price at option pricing
K <- 150          # Strike price
sigma <- 0.24     # Annualized volatility rate
r <- 0.07         # Annualized risk-free rate
t <- 0.75         # Time to maturity
barrier <- 145    # Barrier level
numSimulations <- 10000
numTimeSteps <- 100

# Get option price
optionPrice <- getUpAndInCallPrice(S0, K, sigma, r, t, barrier, numSimulations, numTimeSteps)
print(optionPrice)

```

## Makefile
To make cpp development easier, Makefile was utilized.
Take into account, that it is specific to mac os.

```
make all: Compiles the full program.
make clean: Removes object files and the main target.
make rebuild: Cleans and then compiles the program.
make run: Executes the compiled program.
make rebuild-run: Rebuilds and runs the program in one step.
```
