#include <iostream>
#include "Bird.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/6/2019

A class Bird meant to create Bird objects or Birds with the client being allowed
to name the Bird and change it's default parameters from false domestic and
predator to true. These parameters are inherited from the Animal class. Other parameters that can be edited
are whether or not it is airborne, aquatic.

First parameterized constructor creates object with specific characteristics of domestic and predator.
All other characteristics are defaulted to false.
@pre Bird has no name and is not domesticated nor a predator
@post Bird recieves a name and indications of boolean output to be true OR false
@param name of Bird
@param domestic Bird or not
@param predator Bird or not
*/

Bird::Bird(std::string name, bool domestic, bool predator) {
  name_ = name;
  domestic_ = domestic;
  predator_ = predator;
  airborne_ = false;
  aquatic_ = false;
}

/*
Creates an Bird Object with specific characteristics of domestic or predator
All other characteristics are defaulted to false or empty string.
@pre Bird has no name and is not domesticated nor a predator
@post Bird has no name and indications of boolean output to be false
*/
Bird::Bird() {
  name_ = "";
  domestic_ = false;
  predator_ = false;
  airborne_ = false;
  aquatic_ = false;
}

bool Bird::isAirborne() const {     //shows whether or not the bird is airborne
  return airborne_;
}

bool Bird::isAquatic() const {     //shows whether or not the bird is aquatic
  return aquatic_;
}

void Bird::setAirborne() {         //allows to change bool value from default to true. Bird is now airborne
  airborne_ = true;
}

void Bird::setAquatic() {          //allows to change bool value from default to true. Bird is now aquatic
  aquatic_ = true;
}

/*
@Pfuncton that prints out 3 sentences to display the mammal and all of its characteristics
domestic, predator, airborne, aquatic*/
void Bird::display() const{
  std::string dom = " is not domestic";   //defaults domestic part of string to false
  std::string pre = "is not a predator";  //defaults predator part of string to false
  std::string air = "is not airborne";    //defaults airborne part of string to false
  std::string aqu = "it is not aquatic";  //defaults aquatic part of string to false

  if (isDomestic()){
    dom = " is domestic";      //sets characteristic to positive if the mammal has it
  }
  if (isPredator()){
    pre = "it is a predator";  //sets characteristic to positive if the mammal has it
  }
  if (isAirborne()){
    air = "it is airborne";    //sets characteristic to positive if the mammal has it
  }
  if (isAquatic()){
    aqu = "it is aquatic";     //sets characteristic to positive if the mammal has it
  }

  std::cout << getName() << dom << " and " << pre << ",\n";
  std::cout << air << " and " << aqu << ".\n\n";
}
