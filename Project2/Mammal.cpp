#include <iostream>
#include "Mammal.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/6/2019

A class Mammal meant to create Mammal objects or Mammals with the client being allowed
to name the Mammal and change it's default parameters from false domestic and
predator to true. These parameters are inherited from the Animal class. Other parameters that can be edited
are hair, airborne, aquatic, toothed, fins, tail, legs.

First parameterized constructor creates object with specific characteristics of domestic and predator.
All other characteristics are defaulted to false and 0 for int legs.
@pre Mammal has no name and is not domesticated nor a predator
@post Mammal recieves a name and indications of boolean output to be true OR false
@param name of Mammal
@param domestic Mammal or not
@param predator Mammal or not
*/

Mammal::Mammal(std::string name, bool domestic, bool predator) {
  name_ = name;
  domestic_ = domestic;
  predator_ = predator;
  hair_ = false;
  airborne_ = false;
  aquatic_ = false;
  toothed_ = false;
  fins_ = false;
  tail_ = false;
  legs_ = 0;
}

/*
Creates an Mammal Object with specific characteristics of domestic or predator
All other characteristics are defaulted to empty string, false, and 0 for int legs.
@pre Mammal has no name and is not domesticated nor a predator
@post Mammal has no name and indications of boolean output to be false
*/
Mammal::Mammal() {
  name_ = "";
  domestic_ = false;
  predator_ = false;
  hair_ = false;
  airborne_ = false;
  aquatic_ = false;
  toothed_ = false;
  fins_ = false;
  tail_ = false;
  legs_ = 0;
}

bool Mammal::hasHair() const {         //shows whether or not the mammal has hair
  return hair_;
}

bool Mammal::isAirborne() const {     //shows whether or not the mammal is airborne
  return airborne_;
}

bool Mammal::isAquatic() const {      //shows whether or not the mammal is aquatic
  return aquatic_;
}

bool Mammal::isToothed() const {     //shows whether or not the mammal has teeth
  return toothed_;
}

bool Mammal::hasFins() const {       //shows whether or not the mammal has fins
  return fins_;
}

bool Mammal::hasTail() const {       //shows whether or not the mammal has a tail
  return tail_;
}

int Mammal::legs() const {           //shows int value of legs that the mammal has
  return legs_;
}

void Mammal::setHair() {             //allows to change bool value from default to true. Mammal now has hair
  hair_ = true;
}

void Mammal::setAirborne() {        //allows to change bool value from default to true. Mammal is now airborne
  airborne_ = true;
}

void Mammal::setAquatic() {         //allows to change bool value from default to true. Mammal is now aquatic
  aquatic_ = true;
}

void Mammal::setToothed() {        //allows to change bool value from default to true. Mammal is now aquatic
  toothed_ = true;
}

void Mammal::setFins() {          //allows to change bool value from default to true. Mammal now has fins
  fins_ = true;
}

void Mammal::setTail() {          //allows to change bool value from default to true. Mammal now has a tail
  tail_ = true;
}

void Mammal::setLegs(int legs) { //allows to change set value of 0 to any int. Mammal now has legs
  legs_ = legs;
}
