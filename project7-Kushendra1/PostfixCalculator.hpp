#include <iostream>
#include <stack>
#include <string>
//#include "PrecondViolatedExcep.hpp"
#pragma once

class PostfixCalculator{
public:
  PostfixCalculator();
  /* From PDF
  Takes a string representation of the infix expression, parses it into the
  corresponding postfix expression and returns the postfix expression as a string. In
  the string representation of the postfix expression, operands and operators are
  also separated by a single space. */

  std::string convertToPostfix(std::string infix_expression);
  /*From PDF
  takes a string representation of the postfix expression (in the format described
  above), calculates the result and returns it. It assumes that the postfix expression is
  well formed (don’t forget to specify all pre and post conditions as well s inputs and
  outputs in your comment preambles) */

  double calculatePostfix(std::string postfix_expression);
  /*From PDF
  will implement the file input/output behavior described above:
  Read every infix expression from the input file and:
  • Convert it to postfix (don’t forget to do this in a try-catch block,
  convertToPostfix may throw an exception!)
  • Write the corresponding postfix expression into postfix.txt, but if
  convertToPostfix throws and exception, write the error message
  instead
  • Evaluate the postfix expression if wellformed and write the result in
  results.txt, otherwise write the error message there too
  void testCalculator(std::string input_file_name); */

  void testCalculator(std::string input_file_name);
private:
  std::string input_file_name;
  int precedence_val(char op);
  double calculate(char operation, double operand1, double operand2);
};
