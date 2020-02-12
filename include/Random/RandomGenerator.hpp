#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <iostream>
#include <random>

class RandomGenerator{
  public:
  
    std::mt19937 generator;
    
    RandomGenerator(): generator(std::random_device{}()) {}
};

#endif