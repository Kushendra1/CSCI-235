#include <iostream>
#include "Fish.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/6/2019

A class Fish meant to create Fish objects or Fish with the client being allowed
to name the Fish and change it's default parameters from false domestic and
predator to true. These parameters are inherited from the Animal class. One other parameter that can be edited
is whether or not it is venomous.

First parameterized constructor creates object with specific characteristics of domestic and predator.
All other characteristics are defaulted to false.
@pre Fish has no name and is not domesticated nor a predator
@post Fish recieves a name and indications of boolean output to be true OR false
@param name of Fish
@param domestic Fish or not
@param predator Fish or not
*/

Fish::Fish(std::string name, bool domestic, bool predator) {
  name_ = name;
  domestic_ = domestic;
  predator_ = predator;
  venomous_ = false;
}

/*
Creates an Fish Object with specific characteristics of domestic or predator
All other characteristics are defaulted to false or empty string.
@pre Fish has no name and is not domesticated nor a predator
@post Fish has no name and indications of boolean output to be false
*/
Fish::Fish() {
  name_ = "";
  domestic_ = false;
  predator_ = false;
  venomous_ = false;
}

bool Fish::isVenomous() const {     //shows whether or not fish is venomous
  return venomous_;
}

void Fish::setVenomous() {         //allows to change bool value from default to true. Fish is now venomous
  venomous_ = true;
}

/*
@Pfuncton that prints out 3 sentences to display the mammal and all of its characteristics
domestic, predator, venomous*/
void Fish::display() const{
  std::string dom = " is not domestic";    //defaults domestic part of string to false
  std::string pre = "is not a predator";   //defaults predator part of string to false
  std::string ven = "it is not venomous";  //defaults venomous part of string to false

  if (isDomestic()){
    dom = " is domestic";     //sets characteristic to positive if the mammal has it
  }
  if (isPredator()){
    pre = "it is a predator"; //sets characteristic to positive if the mammal has it
  }
  if (isVenomous()){
    ven = "it is venomous";   //sets characteristic to positive if the mammal has it
  }

  std::cout << getName() << dom << ", " << pre << ",\n";
  std::cout << "and " << ven << ".\n\n";
}
