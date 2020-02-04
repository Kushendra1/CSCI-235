#include <iostream>
#include <regex>
#include <queue>
#include <vector>
#include <stack>

class CodewordGenerator{
public:
  CodewordGenerator();  //default constructor
  std::string generateShortestWord(std::string pattern);
  /* takes a string pattern and returns the shortest string that matches the pattern
  exploring the space of possible alphabet permutations in Breadth First Search
  order.
  The input string pattern is guaranteed to represent a valid regular expression
  pattern */
  std::string generateLengthWord(std::string pattern, int length);
  /* takes a string pattern and an integer n and returns a string of length n that
  matches the pattern exploring the space of possible alphabet permutations in
  Depth First Search order.
  Here too, the input string pattern is guaranteed to represent a valid regular
  expression pattern */
};
