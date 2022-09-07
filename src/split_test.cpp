#include "split.h"
#include <iostream>
using namespace std;

void printLists(Node* list);

int main(int argc, char* argv[])
{
  //Create head pointer
  Node* initial = new Node(1, nullptr);
  Node* init_head = initial;
  // initial->next = new Node(2, nullptr);
  // initial->next->next = new Node(3, nullptr);
  // initial->next->next->next = new Node(4, nullptr);
  // initial->next->next->next->next = new Node(5, nullptr);


  int i = 2;
  while(i <= 10){
    intitial->next = new Node(i, nullptr);
    intitial = intitial->next;
  }

  Node* evens = nullptr;
  Node* odds = nullptr;

  cout << "initial list: ";
  printLists(initial);

  split(initial, odds, evens);  

  cout << "odds:";
  printLists(odds);

  cout << "evens:";
  printLists(evens);  

  return 0;
}

void printLists(Node* list){
    if(list == nullptr){
        return;
    }
    cout << list->value << " ";
    printLists(list->next);
}
