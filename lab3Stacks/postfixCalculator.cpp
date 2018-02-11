/*Ryan Kelly
rpk2kn
2/3/2018
filename: postfixCalculator.cpp
*/

#include <iostream>
#include "stack.h"
using namespace std;
#include "postfixCalculator.h"

PostfixCalculator::PostfixCalculator(){
  numbers = new Stack();
}
/*
PostfixCalculator::PostfixCalculator(const PostfixCalculator& source){
  numbers = new Stack(*source.numbers);
}

PostfixCalculator::~PostfixCalculator(){
  delete numbers;
}

PostfixCalculator& PostfixCalculator::operator=(const PostfixCalculator source){
  numbers = source.numbers;
  return *this;
}
*/
void PostfixCalculator::pushNum(int num){
  numbers->push(num);
}

void PostfixCalculator::add(){
  int x = numbers->top();
  numbers->pop();
  int y = numbers->top();
  numbers->pop();
  numbers->push(x + y);
}

void PostfixCalculator::subtract(){
  int x = numbers->top();
  numbers->pop();
  int y = numbers->top();
  numbers->pop();
  numbers->push(y - x);
}

void PostfixCalculator::multiply(){
  int x = numbers->top();
  numbers->pop();
  int y = numbers->top();
  numbers->pop();
  numbers->push(x * y);
}

void PostfixCalculator::divide(){
  int x = numbers->top();
  numbers->pop();
  int y = numbers->top();
  numbers->pop();
  numbers->push(y / x);
}

void PostfixCalculator::negate(){
  int x = numbers->top();
  numbers->pop();
  numbers->push(-x);
}

int PostfixCalculator::getTopValue(){
  return numbers->top();
}
