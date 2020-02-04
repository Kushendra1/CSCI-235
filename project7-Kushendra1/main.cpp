#include <iostream>
#include "PostfixCalculator.hpp"

int main(){
  PostfixCalculator a;
  a.testCalculator("input.txt");
  return 0;
}

// std::ifstream input(input_file_name);
// std::ofstream output;
// std::ofstream resultsfile;
// std::string infix, postfix, results;
// output.open("postfix.txt");
// resultsfile.open("results.txt");
// while (getline(input, infix)) {
//   try {
//     postfix = convertToPostfix(infix);
//     output << postfix;
//     output << endl;
//   }
//   catch (PrecondViolatedExcep problem) {
//     output << problem.what();
//     output << endl;
//   }
//   results = calculatePostfix(postfix);
//   resultsfile << results;
//   resultsfile << endl;
// }
// output.close();
// resultsfile.close();
