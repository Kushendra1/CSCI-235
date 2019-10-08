#pragma once
#include <iostream>
#include <string>
#include "Animal.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/6/2019

A class Bird meant to create Bird objects or Birds with the client being allowed
to name the Bird and change it's default parameters from false domestic and
predator to true. These parameters are inherited from the Animal class. Other parameters that can be edited
are whther or not it is airborne, aquatic.
*/

class Bird: public Animal {
public:
  Bird();
  Bird(std::string name, bool domestic = false, bool predator = false);
  bool isAirborne() const;
  bool isAquatic() const;
  void setAirborne();
  void setAquatic();
  virtual void display() const override;

private:
  bool airborne_;
  bool aquatic_;
};
