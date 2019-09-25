#include "ZooRecord.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
/*Kushendra Ramrup
Tiziana Ligorio
CSCI 235
9/19/2019

constructor reads through file and stores the name, domestic, and predator
*/

ZooRecord::ZooRecord() {
  item_count_ = 0;        //default constructor sets record to zero/empty record
}

ZooRecord::ZooRecord(std::string input_file_name) {
  std::ifstream fin(input_file_name.c_str());
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;  //error message to be displayed if file can't be read/opened
    exit(1);
  }

  std::string animal_name;
  bool domestic, predator;
  std::string junk;
  std::string second_line;
  getline(fin, junk);           //first line from csv file is titles, so its junk
  while (getline(fin, second_line)){     //while i'm accessing the second and subsequent lines to get the 3 pieces of info
    std::stringstream ss(second_line);   //first i need to convert the stream to a stringstream, easier to traverse
    std::string str, pre, dom;
    getline(ss, str, ',');               //allows to to specifically get one string from stream, first one is animal name
    animal_name = str;                   // i pull out animal name from the stream and store it in my variable
    for (int i = 0; i < 6; i++){         //the for loop allows me to go through the rest of the stream up to right before predator
      getline(ss, junk, ',');            // since i dont need these pieces of info, they are all pulled out as junk
    }
    getline(ss, pre, ',');               //now the first piece in stream is my predator value. I need to pull this out
    if (pre == "1"){                     //since I can't directly convert from string to bool
      predator = true;                   //the if statements allows me to store the bool value provided in a new variable
    }                                    //this new variable is what i'll use for the animal object
    if (pre == "0") {
      predator = false;
    }
    for (int i = 0; i < 7; i++){         //the same process as above for the predator value
      getline(ss, junk, ',');            //it's just repeated for the domestic value
    }
    getline(ss, dom, ',');               //same process as the predator value was repeated here
    if (dom == "1"){
      domestic = true;
    }
    if (dom == "0") {
      domestic = false;
    }
    getline(ss, junk, ',');

    Animal animal(animal_name, domestic, predator);   //now that I've extracted the 3 pieces of date needed, I can create all animal classes within the while loop
    add(animal);                                      //adds all animal objects to the items_ array in ArrayBay
  }
  fin.close();
}

/**@post displays all animals in record, one per line by calling animal's
display method” **/
void ZooRecord::display() {
  for (int i = 0; i < item_count_; i++) {
    items_[i].display();
  }
}
