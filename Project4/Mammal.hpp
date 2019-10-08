#pragma once
#include <iostream>
#include <string>
#include "Animal.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/6/2019

A class Mammal meant to create Mammal objects or Mammals with the client being allowed
to name the Mammal and change it's default parameters from false domestic and
predator to true. These parameters are inherited from the Animal class. Other parameters that can be edited
are hair, airborne, aquatic, toothed, fins, tail, legs.
*/

class Mammal: public Animal {
public:
  Mammal();
  Mammal(std::string name, bool domestic = false, bool predator = false);
  bool hasHair() const;
  bool isAirborne() const;
  bool isAquatic() const;
  bool isToothed() const;
  bool hasFins() const;
  bool hasTail() const;
  int legs() const;
  void setHair();
  void setAirborne();
  void setAquatic();
  void setToothed();
  void setFins();
  void setTail();
  void setLegs(int legs);
  virtual void display() const override;

private:
  bool hair_;
  bool airborne_;
  bool aquatic_;
  bool toothed_;
  bool fins_;
  bool tail_;
  int legs_;
};
