\name{option-montecarlo-package}
\alias{option-montecarlo-package}
\alias{option-montecarlo}
\docType{package}
\title{
  Monte Carlo Methods for Option Pricing
}
\description{
  The 'option-montecarlo-package' is designed for pricing financial options using Monte Carlo simulation methods. It provides a comprehensive set of tools to handle various option pricing scenarios with an emphasis on Monte Carlo techniques.
}
\details{
  The package includes functions for pricing different types of options, with a special focus on barrier options like 'Up-and-In' calls. Users can leverage the `getUpAndInCallPrice` function to compute option prices under varying market conditions, utilizing advanced random number generation and simulation methods.
}
\author{
  Jakub Wujec

  Maintainer: Jakub Wujec <kuba1302@gmail.com>
}
\references{
  This section can include references to financial mathematics literature, Monte Carlo methods, and derivative pricing models that inform the package's development.
}
\keyword{ finance }
\keyword{ monte carlo }
\keyword{ options }
\examples{
  \dontrun{
     ## Example using getUpAndInCallPrice
     ## This example can showcase how to use the function with hypothetical parameters.
     ## Example:
     ## price <- getUpAndInCallPrice(100, 120, 0.25, 0.05, 1, 150, 10000, 250)
     ## print(price)
  }
}
