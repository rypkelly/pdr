/* Ryan Kelly
rpk2kn
2/6/18
filename: stack.h */
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack{
 public:
  Stack();
  void push(int x);
  void pop();
  int top();
  bool empty();
 private:
  int *entries;
  int topIndex;
};
#endif
