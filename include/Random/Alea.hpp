#ifndef ALEA_HPP
#define ALEA_HPP

#include "RandomGenerator.hpp"

#include <iostream>

template<typename T, typename Enable = void>
class Alea;

template<typename T>
class Alea<T, std::enable_if_t<std::is_integral_v<T>>> : public RandomGenerator{
  public:
    std::uniform_int_distribution<T>  distribution;

    Alea(T min, T max)
    : RandomGenerator(), distribution(min, max) {}

    T operator()(){
      return this->distribution(this->generator);
    }
};

template<typename T>
class Alea<T, std::enable_if_t<std::is_floating_point_v<T>>> : public RandomGenerator{
  public:
    std::uniform_real_distribution<T>  distribution;

    Alea(T min, T max)
    : RandomGenerator(), distribution(min, max) {}

    T operator()(){
      return this->distribution(this->generator);
    }
};

// redéfinir opérateur ()()

template<typename T>
auto alea_generator(T min, T max){
  return Alea<T>(min, max);
}

#endif