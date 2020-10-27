/***********************************************************

  SimpleCalc.h

  @author Ryan Morehouse
  @license MIT

  A very simple, 2 argument, 1 operator calculator.

  **********************************************************/

#ifndef SIMPLECALC_H
#define SIMPLECALC_H

#include <string>

class SimpleCalc {
  public:
    double run(std::string equation);
};

#endif
