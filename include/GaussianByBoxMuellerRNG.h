#include "RandomNumberGeneratorBase.h"

#ifndef GAUSSIAN_BY_BOX_MUELLER_RNG_H
#define GAUSSIAN_BY_BOX_MUELLER_RNG_H

class GaussianByBoxMuellerRNG : public RandomNumberGeneratorBase {
  virtual double generate() = 0;
};

#endif