#include <iostream>
#include "Animal.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
8/30/2019

Creates an Animal Object with specific characteristics of domestic or predator
@pre Animal has no name and is not domesticated nor a predator
@post Animal recieves a name and indications of boolean output to be true OR false
@param name of Animal
@param domestic Animal or not
@param predator Animal or not
*/

Animal::Animal(std::string name, bool domestic, bool predator) {
  name_ = name;
  domestic_ = domestic;
  predator_ = predator;
}

/*
Creates an Animal Object with specific characteristics of domestic or predator
@pre Animal has no name and is not domesticated nor a predator
@post Animal has no name and indications of boolean output to be false
*/

Animal::Animal() {
  name_ = "";
  domestic_ = false;
  predator_ = false;
}

std::string Animal::getName() const {
  return name_;
}

bool Animal::isDomestic() const {
  return domestic_;
}

bool Animal::isPredator() const {
  return predator_;
}

void Animal::setName(std::string name) {
  name_ = name;
}

void Animal::setDomestic() {
  domestic_ = true;
}

void Animal::setPredator() {
  predator_ = true;
}
