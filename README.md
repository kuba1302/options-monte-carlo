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

## Makefile for Streamlined C++ Development

To simplify and enhance the C++ development process, a tailored Makefile is included in this package. The Makefile is designed to be macOS-specific and streamlines various build steps. Here's how you can leverage the Makefile commands:

```
make all: Executes the complete compilation process for the program.
make clean: Clears out all the object files and the final compiled binary, keeping your workspace tidy.
make rebuild: Performs a clean slate build by first removing previous compilations and then generating fresh binaries.
make run: Directly runs the compiled binary, allowing for immediate testing of the program.
make rebuild-run: Combines cleaning, building, and running steps into a single command for efficient iteration cycles.
```
