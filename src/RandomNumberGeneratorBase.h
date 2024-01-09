#ifndef RANDOM_NUMBER_GENERATOR_BASE_H
#define RANDOM_NUMBER_GENERATOR_BASE_H

class RandomNumberGeneratorBase {
 public:
  virtual ~RandomNumberGeneratorBase() = default;
  virtual double generate() = 0;
};

#endif