/***********************************************************

  SimpleCalc.cpp

  @author Ryan Morehouse
  @license MIT

  A very simple, 2 argument, 1 operator calculator.

  **********************************************************/

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include "SimpleCalc.h"

double SimpleCalc::run(std::string equation) {
  double arg1, arg2;
  std::string op;
  std::string words[3];

  // parse arguments from user input
  std::stringstream ss(equation);
  for(int i = 0; i < 3; i++) 
    ss >> words[i];
  
  // get operator
  op = words[1];
  // validate operator
  if(op == "+" || op == "-" || op == "*" || op == "/") {
    // continue
  } else {
    throw std::invalid_argument("invalid operator");
    return 0;
  }

  // get and verify arguments
  char *ptr;
  const char *arg1_str = words[0].c_str();
  arg1 = std::strtod(arg1_str, &ptr);
  if(arg1_str == ptr)
    throw std::invalid_argument("arg1 is not a valid number.");

  ptr = NULL;
  const char *arg2_str = words[2].c_str();
  arg2 = std::strtod(arg2_str, &ptr);
  if(arg2_str == ptr)
    throw std::invalid_argument("arg2 is not a valid number.");

  // check for divide by zero error
  if(op == "/" && arg2 == 0.0)
    throw std::invalid_argument("divided by zero");

  double answer;
  switch(op[0]) {
    case '+':
      answer = arg1 + arg2;
      break;
    case '-':
      answer = arg1 - arg2;
      break;
    case '*':
      answer = arg1 * arg2;
      break;
    case '/':
      answer = arg1 / arg2;
      break;
  }

  return answer;
}
