#include <iostream>
#include "Animal.hpp"
#include "Animal.cpp"
#include "Mammal.hpp"
#include "Mammal.cpp"
#include "Bird.hpp"
#include "Bird.cpp"
#include "Fish.hpp"
#include "Fish.cpp"
using std::cout;
using std::endl;

int main() {
  Mammal bear("Winnie The Pooh", true, true);
  cout<< bear.getName() << endl;
  cout<< bear.isDomestic() << endl;
  cout<< bear.isPredator() << endl;
  cout<< bear.isAirborne() << endl;
  bear.setTail();
  cout<< bear.hasTail() << endl;

  // Bird gull("Mai", true, true, true);
  // cout<< gull.getName() << endl;
  // cout<< gull.isDomestic() << endl;
  // cout<< gull.isPredator() << endl;
  // cout<< gull.isAquatic() << endl;
  // cout<< gull.isAirborne() << endl;
  // gull.setAquatic();
  // cout<< gull.isAquatic() << endl;
  return 0;
}
