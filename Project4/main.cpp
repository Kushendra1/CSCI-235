#include <iostream>
#include "Animal.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "PrecondViolatedExcep.hpp"
#include "ZooRecord.hpp"

int main() {
  // Mammal mone("pooh", false, true);
  // mone.display();
  ZooRecord object1("zoo.csv");
  //std::cout << object1.getLength() << std::endl;
  object1.display();
  return 0;
}
