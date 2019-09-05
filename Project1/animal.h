#pragma once
#include <iostream>

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
8/30/2019 */

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

private:
  std::string name_;
  bool domestic_;
  bool predator_;
};
