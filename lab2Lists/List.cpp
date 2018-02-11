/* Ryan Kelly
rpk2kn
1/27/18
Filename: List.cpp
*/
#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

//constructor
List::List() {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
}

//Copy Constructor
List::List(const List& source){
  head=new ListNode;
  tail=new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       // deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

//Destructor
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

//Equals Operator
List& List::operator=(const List& source){
  if(this == &source)
    return *this;
  else{
    makeEmpty();
    ListItr iter(source.head->next);
    while(!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

// isEmpty
bool List::isEmpty() const{
  return count == 0;
}

// makeEmpty
void List::makeEmpty() {
  ListItr iter(head->next);
  while(!iter.isPastEnd()){
    iter.moveForward();
    delete iter.current->previous;
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

// first
// returns an interator pointing to first Listnode
ListItr List::first() {
  ListItr *iterPointer = new ListItr(head->next);
  ListItr iter = *iterPointer;
  return iter;
}

//last
// returns an iterator that points to last ListNode
ListItr List::last(){
  ListItr *iterPointer = new ListItr(tail->previous);
  ListItr iter = *iterPointer;
  return iter;
}

//insertAfter
// inserts x after current itr position p
void List::insertAfter(int x, ListItr position){
  ListNode *temp = new ListNode;
  temp->value = x;
  temp->next = position.current->next;
  temp->previous = position.current;
  position.current->next->previous = temp;
  position.current->next = temp;
  count++;
}


//insertBefore
// inserts x before current itr position p
void List::insertBefore(int x, ListItr position){
  ListNode *temp = new ListNode;
  temp->value = x;
  temp->next = position.current;
  temp->previous = position.current->previous;
  position.current->previous->next = temp;
  position.current->previous = temp;
  count++;
}

//insertAtTail
//inserts x at tail of List
void List::insertAtTail(int x){
  ListNode *temp = new ListNode;
  temp->value = x;
  temp->next = tail;
  temp->previous = tail->previous;
  tail->previous->next = temp;
  tail->previous = temp;
  count++;
}

//remove
//Removes the first occurrence of x
void List::remove(int x){
  ListItr iter(head->next);
  bool cont = true;
  while((!iter.isPastEnd()) && cont){
    if(iter.retrieve() == x){
      iter.current->previous->next = iter.current->next;
      iter.current->next->previous = iter.current->previous;
      delete iter.current;
      cont = false;
      count--;
    }
    iter.moveForward();
  }
}

//find
//Returns itr pointing to the first occurrence of x, else to the dummy tail node
ListItr List::find(int x){
  ListItr *iterPointer = new ListItr(head->next);
  ListItr iter = *iterPointer;
  bool cont = true;
  while(!iter.isPastEnd() && cont){
    if(iter.retrieve() == x){
      cont = false;
      iter.moveBackward();
    }
    iter.moveForward();
  }
  return iter;
}

//size
//Returns number of elements in List
int List::size() const{
  return count;
}

//printList: non-member function
//prints list forwards when direction is true
//or backwards when direction is false
void printList(List& source, bool ddirection){
  cout << endl;
  if(ddirection){
    ListItr iter = source.first();
    while(!iter.isPastEnd()){
      cout << iter.retrieve() << " ";
      iter.moveForward();
    }
  }
  else{
    ListItr iter = source.last();
    while(!iter.isPastBeginning()){
      cout << iter.retrieve() << " ";
      iter.moveBackward();
    }
  }
  cout << endl;
}
