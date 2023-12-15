#include <spdlog/spdlog.h>

#include "OptionParams.h"

OptionParams::OptionParams(double S0, double K, double sigma, double r,
                           double T, double B)
    : S0(S0), K(K), sigma(sigma), r(r), T(T), B(B) {}
