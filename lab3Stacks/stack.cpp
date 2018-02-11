/* Ryan Kelly
rpk2kn
2/6/18
filename: stack.cpp */

#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack(){
  entries = new int[100];
  topIndex = 0;
}

void Stack::push(int x){
  entries[topIndex] = x;
  topIndex++;
  if(topIndex == (sizeof(entries)/sizeof(entries[0]))){
    int *newEntries = new int[2*topIndex];
    for(int i = 0; i < topIndex; i++){
      newEntries[i] = entries[i];
    }
    delete [] entries;
    entries = newEntries;
  }
}

void Stack::pop(){
  if(topIndex != 0)
    topIndex--;
}

int Stack::top(){
  if(topIndex == 0)
    return 0;
  return entries[topIndex-1];
}
  
bool Stack::empty(){
  return topIndex == 0;
}
