#include <iostream>
#include "CodewordGenerator.hpp"

CodewordGenerator::CodewordGenerator() {
}

/*takes a string pattern and returns the shortest string that matches the pattern
exploring the space of possible alphabet permutations in Breadth First Search
order.
The input string pattern is guaranteed to represent a valid regular expression
pattern

@Param a string variable pattern, which provides the pattern of the strings this functon needs to create and match.
Pattern will be turned into a regex expression in order to use the regex_match function which will help us
determine if the two patterns match up.
As soon as it does match, the function will spit out the result, because as soon as it matches it is also the shortest.
@return cur_Str the new string whose pattern matches the input and is the shortest string to do so
*/
std::string CodewordGenerator::generateShortestWord(std::string pattern){
  std::vector<char> U = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  std::string empty;
  std::queue <std::string> aQueue;
  aQueue.push(empty);
  std::regex name(pattern);

  while(!aQueue.empty()) {
    std::string cur_str = aQueue.front(); aQueue.pop();
    if (!std::regex_match(cur_str, name)) {
      for (int i = 0; i < U.size(); i++){
        aQueue.push(cur_str + U[i]);
      }
    }
    else {
      return cur_str;
    }
  }
}

/*takes a string pattern and an integer n and returns a string of length n that
matches the pattern exploring the space of possible alphabet permutations in
Depth First Search order.
Here too, the input string pattern is guaranteed to represent a valid regular
expression pattern

@Param a string variable pattern, which provides the pattern of the strings this functon needs to create and match.
Pattern will be turned into a regex expression in order to use the regex_match function which will help us
determine if the two patterns match up.
@Param an integer variable length, which provides the exact length that our produced string has to be. Unlike last time
where the string has to be the shortest, this time the string has to both match the pattern and the length provided
This time the result is only produced if these two conditions are met
@return cur_Str is the new string produced whose pattern and length matches the parameters provided
*/
std::string CodewordGenerator::generateLengthWord(std::string pattern, int length){
  std::vector<char> U = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  std::string empty;
  std::stack <std::string> aStack;
  aStack.push(empty);
  std::regex name(pattern);

  while(!aStack.empty()) {
    std::string cur_str = aStack.top(); aStack.pop();
      if (!std::regex_match(cur_str, name) && cur_str.length() < length) {
        for (int i = 0; i < U.size(); i++){
          aStack.push(cur_str + U[i]);
        }
      }
    else if (std::regex_match(cur_str, name) && cur_str.length() == length){
      return cur_str;
    }
  }
}
