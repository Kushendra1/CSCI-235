#include <iostream>
#include "SortingComparison.hpp"

int main() {
  SortingComparison test = SortingComparison(10);
  std::cout<< "----------Testing Size 10----------" << "\n\n";
  std::cout << "-----------------RANDOM-----------------" << "\n";
  test.runComparison(RANDOM);
  std::cout << "---------------INCREASING---------------" << "\n";
  test.runComparison(INCREASING);
  std::cout << "---------------DECREASING---------------" << "\n";
  test.runComparison(DECREASING);
  return 0;
}
