#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "PostfixCalculator.hpp"
#include "PrecondViolatedExcep.hpp"

PostfixCalculator::PostfixCalculator() {
}

/* helper method to determine precedence values of operators
@param takes in a character op and
@outputs 5 and 6 if multiply/divide and add/subtract */
int PostfixCalculator::precedence_val(char op){
  if(op == '*' || op == '/'){
    return 5;
  }
  if(op == '+' || op == '-'){
    return 6;
  }
  // if(op == '$' || op == '^'){
  //   return 4;
  // }
  else{
    return 0;
  }
}

/*helper method to perform calculations
@params one character representing operation, and two integer operands
@outputs a calulated value*/
double PostfixCalculator::calculate(char operation, double operand1, double operand2){
  if(operation == '+') return operand1 +operand2;        //simply perform calculation based on char operations
	else if(operation == '-') return operand1 - operand2;
 	else if(operation == '*') return operand1 * operand2;
 	else if(operation == '/') return operand1 / operand2;

 	else std::cout<<"Unexpected Error \n";
 	return 0;
}

/*method to convert string infix expressions to a post fix version
@param a string infix expression
@output a string post fix version */
std::string PostfixCalculator::convertToPostfix(std::string infix_expression){
  std::stack <char> aStack;                                //create all my needed varibles, a stack for operands, operators,
  std::string postfixExp, stream;                          //and parentheses, string variables for output and stringstream
  std::stringstream ss(infix_expression);                  //create the stringstream using the string variable from above
  while(getline(ss, stream, ' ')){
    char ch = stream[0];                                   //first character of the string is now represented as ch
    if (ch >='0' && ch <= '9'){
      postfixExp += stream + " ";                          //if its a variable append it to output with a space
    }
    else if (ch == '('){                                   //Save '(' on stack
      aStack.push(ch);
    }
    else if (precedence_val(ch) >= 5){                     //Process stack operators of greater precedence
      while (!aStack.empty() && aStack.top() != '(' && precedence_val(ch) >= precedence_val(aStack.top())){
        postfixExp += aStack.top();                        //appends the top of stack to output expression
        postfixExp += " ";                                 //with a space
        aStack.pop();                                      //removes variable on the top of stack
      }
      aStack.push(ch);                                     //Save the operator
    }
    else if (ch == ')'){                                   //Pop stack until matching '('
      while (!aStack.empty() && aStack.top() != '('){                         //while top of stack is not an open parenthese add it to
        postfixExp += aStack.top();                        //output expression with a space
        postfixExp += " ";
        aStack.pop();                                      //Remove the open parenthesis
      }
      if (aStack.empty()) {
        throw(PrecondViolatedExcep("Unbalanced parenthesis"));
      }
      aStack.pop();
    }
    else{                     //if it ch is an unknown operator value, throw error message
      throw(PrecondViolatedExcep("Unknown operator"));
    }
  }
  while (!aStack.empty()){                                 //Append to postfixExp the operators remaining in the stack
    if (aStack.top() == '(') {
      throw(PrecondViolatedExcep("Unbalanced parenthesis"));
    }
    postfixExp += aStack.top();
    aStack.pop();
  }
  return postfixExp + " ";
}

/*method to calculate the basic four functions on a calculator on post fix expressions
@param a string post expression
@output a double result of the operations */
double PostfixCalculator::calculatePostfix(std::string postfix_expression){
  std::stack<double> bStack;
  for(int i = 0;i< postfix_expression.length();i++) {
    if(postfix_expression[i] == ' ' || postfix_expression[i] == ',') continue; // Scans each char from left, if char is a delimitter move on.
    else if(precedence_val(postfix_expression[i]) >= 5) {                      // If char is operator, take out two elements from stack, perform operation and push the result back.
      double operand2 = bStack.top(); bStack.pop();                               // Pop two operands.
      double operand1 = bStack.top(); bStack.pop();
      double result = calculate(postfix_expression[i], operand1, operand2);       // Perform operation using helper method from above
      bStack.push(result);   	                                                 //Add the result of operation on top of the stack.
    }
    else if(postfix_expression[i] >= '0' && postfix_expression[i] <= '9'){
      double operand = 0;                                                         //Take operand from  string and keep incrementing i when you have number
      while(i<postfix_expression.length() && postfix_expression[i] >= '0' && postfix_expression[i] <= '9'){//Anytime there is a multi digit number
        operand = (operand*10) + (postfix_expression[i] - '0');                //multiply right digit by 10 and add new second digit to it
        i++;
      }
      i--; //Decrement i to counter the increment in the loop and to avoid skipping non numbers
      bStack.push(operand); // Push operand on stack.
    }
  }
  return bStack.top(); //only thing left in stack should be the result, so return that
}

void PostfixCalculator::testCalculator(std::string input_file_name){
  std::string in_line, ou_line, result;
  std::ifstream fin(input_file_name.c_str());
  std::ofstream output;
  std::ofstream resultfile;
  output.open("postfix.txt");
  resultfile.open("results.txt");
  while (getline(fin, in_line)) {
    try {
      ou_line = convertToPostfix(in_line);
      output << ou_line;
      output << std::endl;
      auto result = calculatePostfix(ou_line);
      resultfile << result;
      resultfile << std::endl;
    }
    catch(PrecondViolatedExcep problem) {
      output << problem.what();
      output << std::endl;
      resultfile << problem.what();
      resultfile << std::endl;
    }
  }
  output.close();
  resultfile.close();
}
