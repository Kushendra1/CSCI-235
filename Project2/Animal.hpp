#pragma once
#include <iostream>
#include <string>

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
8/30/2019

A class Animal meant to create Animal objects or Animals with the client being allowed
to name the Animal and change it's default parameters from false domestic and
predator to true.
*/

class Animal {
public:
  Animal(); // default constructor of class
  Animal(std::string name, bool domestic = false, bool predator = false); //parameterized constructor
  std::string getName() const;
  bool isDomestic() const;
  bool isPredator() const;
  void setName(std::string name);
  void setDomestic();
  void setPredator();

protected:
  std::string name_;
  bool domestic_;
  bool predator_;
};
