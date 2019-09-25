#include <iostream>
#include "Animal.hpp"
#include "ArrayBag.hpp"
#include "ZooRecord.hpp"
using std::cout;
using std::endl;

/* Kushendra Ramrup
CSCI 235
Tiziana Ligorio
9/17/2019 */

int main(){
  // ArrayBag<int> first_array;
  // ArrayBag<int> second_array;
  // first_array.add(3);
  // second_array.add(5);
  // first_array.add(4);
  // second_array.add(3);
  // first_array.display();
  // first_array.operator /=(second_array);
  // first_array.display();

  ZooRecord object1("zoo.csv");
  object1.display();

  return 0;
}
