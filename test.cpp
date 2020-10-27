/*********************************************

  test.cpp

  @author Ryan Morehouse
  @license MIT

  Test cases for the SimpleCalc class, with a precision
  set to 10 places.
  
  Expected error cases:
  1. Bad argument for arg1
  2. Bad argument for arg2
  3. Missing argument for arg1
  4. Missing argument for arg2
  5. Bad argument for operator
  6. Missing argument for operator
  7. Divide by zero error

  Calculation cases:
  1. Addition
  2. Subtraction
  3. Multiplication
  4. Division

  Followed by freeform user input.

*********************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include "SimpleCalc.h"

int main() {
  SimpleCalc calc;

  std::string error_cases[7];
  error_cases[0] = "five + 4";
  error_cases[1] = "5 + four";
  error_cases[2] = " + 4";
  error_cases[3] = "5 + ";
  error_cases[4] = "5 plus 4";
  error_cases[5] = "5 4";
  error_cases[6] = "5 / 0";

  std::string norm_cases[4];
  norm_cases[0] = "1254.365 + 9856.24"; // 11110.605
  norm_cases[1] = "-9954.2 - 22.5";     // −9976.7
  norm_cases[2] = "15 * 14.2";          // 213
  norm_cases[3] = "20 / 4";             // 5

  // expected output
  std::stringstream ss;
  ss << "Expected Output: " << std::endl;
  ss << "Exception: arg1 is not a valid number." << std::endl;
  ss << "Exception: arg2 is not a valid number." << std::endl;
  ss << "Exception: invalid operator" << std::endl;
  ss << "Exception: arg2 is not a valid number." << std::endl;
  ss << "Exception: invalid operator" << std::endl;
  ss << "Exception: invalid operator" << std::endl;
  ss << "Exception: divided by zero" << std::endl;
  ss << "11110.605" << std::endl;
  ss << "-9976.7" << std::endl;
  ss << "213" << std::endl;
  ss << "5" << std::endl;
  std::cout << ss.str() << std:: endl;

  // actual output
  std::cout << "Actual Output:" << std::endl;
  // run exception cases
  for(int i = 0; i < 7; i++) {
    try {
      std::cout << calc.run(error_cases[i]) << std::endl;
    } catch(std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  // run normal calculation cases
  for(int i = 0; i < 4; i++) {
    try {
      double d = calc.run(norm_cases[i]);
      std::cout << std::setprecision(10) << d << std::endl;
    } catch(std::exception& e) {
      std:: cout << "Exception: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl << std::endl;

  // user i/o
  ss.str(std::string());
  ss << "User Input / Output:" << std::endl;
  ss << "note: floating-point precision is set to 10" << std::endl;
  ss << "put spaces between arguments and operator" << std::endl;
  ss << "quit with ctrl+c" << std::endl;
  std::cout << ss.str() << std::endl;

  while(true) {
    std::string prompt = "> "; 
    std::cout << prompt;
    std::string equation;
    getline(std::cin, equation);
    try {
      double d = calc.run(equation);
      std::cout << std::setprecision(10) << d << std::endl;
    } catch (std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  return 0;
}
