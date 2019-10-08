#pragma once
#include <iostream>
#include <string>
#include "Animal.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/6/2019

A class Fish meant to create Fish objects or Fish with the client being allowed
to name the Fish and change it's default parameters from false domestic and
predator to true. These parameters are inherited from the Animal class. One other parameter that can be edited
is whther or not it is venomous.
*/

class Fish: public Animal {
public:
  Fish();
  Fish(std::string name, bool domestic = false, bool predator = false);
  bool isVenomous() const;
  void setVenomous();
  virtual void display() const override;

private:
  bool venomous_;
};
