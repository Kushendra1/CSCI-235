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
  /**@post displays animal data in the form:
 "animal_name is [not] domestic and [it is / is not] a predator\n"
 **/
  void display();
  /*a friend function overload operator to prevent confusion when
  comparing 2 animal classes to each other*/
  friend bool operator==(const Animal& animal_1, const Animal& animal_2);

protected:
  std::string name_;
  bool domestic_;
  bool predator_;
};
