#include "ZooRecord.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
/*Kushendra Ramrup
Tiziana Ligorio
CSCI 235
10/04/2019

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
  bool domestic, predator, airborne, aquatic, hair, teeth, fins, tail, venomous;
  int legs;
  std::string junk;
  std::string second_line;
  getline(fin, junk);           //first line from csv file is titles, so its junk
  while (getline(fin, second_line)){     //while i'm accessing the second and subsequent lines to get the 3 pieces of info
    std::stringstream ss(second_line);   //first i need to convert the stream to a stringstream, easier to traverse
    std::string str, pre, dom, air, aqu, shair, tee, fin, stail, ven, slegs, sclass;
    getline(ss, str, ',');               //allows to to specifically get one string from stream, first one is animal name
    animal_name = str;                   // i pull out animal name from the stream and store it in my variable
    getline(ss, shair, ',');             //allows to to specifically get one string from stream,
    if (shair == "1"){                   // i pull out hair from the stream and store it in my variable
      hair = true;                       //since I can't directly convert from string to bool, if statements allow me
    }                                    //to store the value into my bool
    if (shair == "0"){
      hair = false;
    }
    for (int i = 0; i < 3; i++){         //the for loop allows me to go through the rest of the stream up to right before
      getline(ss, junk, ',');            //next wanted characteristic
    }
    getline(ss, air, ',');               //repeat steps from hair
    if (air == "1"){
      airborne = true;
    }
    if (air == "0") {
      airborne = false;
    }
    getline(ss, aqu, ',');              //repeat steps from hair
    if (aqu == "1"){
      aquatic = true;
    }
    if (aqu == "0") {
      aquatic = false;
    }
    getline(ss, pre, ',');              //repeat steps from hair
    if (pre == "1"){
      predator = true;
    }
    if (pre == "0") {
      predator = false;
    }
    getline(ss, tee, ',');             //repeat steps from hair
    if (tee == "1"){
      teeth = true;
    }
    if (tee == "0") {
      teeth = false;
    }
    for (int i = 0; i < 2; i++){       //the for loop allows me to go through the rest of the stream up to right before
      getline(ss, junk, ',');          //next wanted characteristic
    }
    getline(ss, ven, ',');             //repeat steps from hair
    if (ven == "1"){
      venomous = true;
    }
    if (ven == "0") {
      venomous = false;
    }
    getline(ss, fin, ',');             //repeat steps from hair
    if (fin == "1"){
      fins = true;
    }
    if (fin == "0") {
      fins = false;
    }
    getline(ss, slegs, ',');
    legs = std::stoi(slegs);           //can't convert directly from string to int, so use the stoi function
    getline(ss, stail, ',');
    if (stail == "1"){                 //repeat steps from hair
      tail = true;
    }
    if (stail == "0") {
      tail = false;
    }
    getline(ss, dom, ',');            //repeat steps from hair
    if (dom == "1"){
      domestic = true;
    }
    if (dom == "0") {
      domestic = false;
    }
    for (int i = 0; i < 1; i++){     //the for loop allows me to go through the rest of the stream up to right before
      getline(ss, junk, ',');        //next wanted characteristic
    }
    getline(ss, sclass);             //get the class type variable
    //std::cout << sclass << sclass.length() << std::endl;
    if (sclass[0] == '1'){           //if the value is 1 then create a mammal object using the stored characteristics
      Mammal *mammal = new Mammal(animal_name, domestic, predator);  //dynamically stored mammal object
      if (hair){
        mammal->setHair();
      }
      if (airborne){
        mammal->setAirborne();
      }
      if (aquatic){
        mammal->setAquatic();
      }
      if (teeth){
        mammal->setToothed();
      }
      if (fins){
        mammal->setFins();
      }
      if (tail){
        mammal->setTail();
      }
      mammal->setLegs(legs);
      Animal *animal = mammal;  //animal pointer pointing to the mammal object
      //std::cout << "hi im inserting mammal" << std::endl;
      insert(item_count_, animal);  //adding the animal pointer to the list using list function
      //insert into list
    }
    if (sclass[0] == '2'){    //if the value is 2 then create a bird object using the stored characteristics
      Bird *bird = new Bird(animal_name, domestic, predator);  //dynamically stored bird object
      if (airborne){
        bird->setAirborne();
      }
      if (aquatic){
        bird->setAquatic();
      }
      Animal *animal = bird;   //animal pointer pointing to the bird object
      //std::cout << "hi im inserting bird" << std::endl;
      insert(item_count_, animal);  //adding the animal pointer to the list
      //insert into list
    }
    if (sclass[0] == '4'){  //if the value is 4 then create a fish object
      Fish *fish = new Fish(animal_name, domestic, predator);   //dynamically stored fish object
      if (venomous){
        fish->setVenomous();
      }
      Animal *animal = fish;   //animal pointer pointing to the bird object
      //std::cout << "hi im inserting fish" << std::endl;
      insert(item_count_, animal);   //adding the animal pointer to the list
      //insert into list
    }
  }
  fin.close();
}

/**@post displays all animals in record, one per line by calling animal's
display method” **/
void ZooRecord::display() {
  for (int i = 0; i < item_count_; i++){
    getItem(i) -> display();
  }
}
