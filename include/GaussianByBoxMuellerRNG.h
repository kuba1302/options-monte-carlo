#include "RandomNumberGeneratorBase.h"

#ifndef GAUSSIAN_BY_BOX_MUELLER_RNG_H
#define GAUSSIAN_BY_BOX_MUELLER_RNG_H

class GaussianByBoxMuellerRNG : public RandomNumberGeneratorBase {
 public:
  ~GaussianByBoxMuellerRNG() = default;
  double generate();
};

#endif