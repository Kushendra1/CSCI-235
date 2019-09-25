#include <iostream>
#include "Animal.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/6/2019

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

/**@post displays animal data in the form:
 "animal_name is [not] domestic and [it is / is not] a predator\n"
 Since there are just 4 combinations of isDomestic and isPredator in the
 sentce to be printed, I just wrote 4 different sentences to be printed
 dependent on what combination is fullfilled
 **/
 void Animal::display(){
   if (isDomestic() == true && isPredator() == true){
     std::cout << getName() << " is domestic and it is a predator" << std::endl;
   }
   if (isDomestic() == true &&  isPredator() == false){
     std::cout << getName() << " is domestic and is not a predator" << std::endl;
   }
   if (isDomestic() == false && isPredator() == true){
     std::cout << getName() << " is not domestic and it is a predator" << std::endl;
   }
   if (isDomestic() == false && isPredator() == false){
     std::cout << getName() << " is not domestic and is not a predator" << std::endl;
   }
 }

 /*overload operator to prevent confusion when
 comparing 2 animal classes to each other*/
bool operator==(const Animal& animal_1, const Animal& animal_2) {
   if (animal_1.getName() == animal_2.getName() && animal_1.isDomestic() == animal_2.isDomestic() && animal_1.isPredator() == animal_2.isPredator()) {
     return true;               //if all attributes of the two animal classe - name, domestic, predator- are the same, then they are equal
   }
   else {
     return false;              //otherwise they are not equal
   }
 }
