/* Ryan Kelly
rpk2kn
2/3/2018
filename: postfixCalculator.h
*/
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
using namespace std;

class PostfixCalculator{
 public:
  PostfixCalculator();
  //PostfixCalculator(const PostfixCalculator& source);
  //~PostfixCalculator();
  //PostfixCalculator& operator=(const PostfixCalculator source);
  void pushNum(int num);
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  int getTopValue();

 private:
  Stack *numbers;
};

#endif

