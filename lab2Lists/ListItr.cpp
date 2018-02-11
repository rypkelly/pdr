/* Ryan Kelly
rpk2kn
1/27/18
Filename: ListItr.cpp
*/

#include <iostream>
#include "ListItr.h"

using namespace std;

// Default Constructor
ListItr::ListItr(){
  current = NULL;
}

// One parameter constructor
ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

// isPastEnd
// true if past end position in list, else false
bool ListItr::isPastEnd() const{
  return current->next == NULL;
}


// isPastBeginning
// true if past beginning position in list, else false
bool ListItr::isPastBeginning() const{
  return current->previous == NULL;
}

//moveForward
// advances current to next position, unless already past end
void ListItr::moveForward() {
  if(!isPastEnd()){
    current = current->next;
  }
}

//moveBackward
// moves current to previous position, unless already past beginning
void ListItr::moveBackward() {
  if(!isPastBeginning()){
    current = current->previous;
  }
}

//retrieve
// returns item in current pos
int ListItr::retrieve() const {
  return current->value;
}
