#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"
#include "List.hpp"
#include "PrecondViolatedExcep.hpp"

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
10/04/2019
*/

class ZooRecord: public List<Animal*> {
public:
  ZooRecord(); //default constructor for empty record
  /**parameterized constructor
@pre the input file is expected to be in CSV (comma separated value) format
as:
"animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,backbo
ne,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
@param input_file_name the name of the input file
@post adds Animal pointers to Animal-derived dynamic objects to record as
per the data in the input file
**/
  ZooRecord(std::string input_file_name);
  /**@post displays all animals in record, one per line by calling animal's
display method” **/
  void display();
};
