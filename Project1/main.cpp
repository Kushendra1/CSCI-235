#include <iostream>
#include "Animal.hpp"
#include "Animal.cpp"
using std::cout;
using std::endl;

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
8/30/2019 */

int main() {
  Animal bear("Winnie The Pooh", true, true);
  cout<< bear.isDomestic() << endl;
  cout<< bear.isPredator() << endl;
  cout<< bear.getName() << endl;

  return 0;
}
