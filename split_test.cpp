#include "split.h"
#include <iostream>
using namespace std;

void printLists(Node* list);

int main(int argc, char* argv[])
{
    //Create head pointer
  Node* initial = new Node(1, nullptr);
  initial->next = new Node(2, nullptr);
  initial->next->next = new Node(3, nullptr);
  initial->next->next->next = new Node(4, nullptr);
  initial->next->next->next->next = new Node(5, nullptr);

  Node* evens = nullptr;
  Node* odds = nullptr;

  cout << "initial list: ";
  printLists(initial);

  split(initial, odds, evens);

  

  cout << "odds:";
  printLists(odds);

  cout << "evens:";
  printLists(evens);  

cout<< "Odds->next: " << odds->next->value;
  return 0;
}

void printLists(Node* list){
    if(list == nullptr){
        return;
    }
    cout << list->value << " ";
    printLists(list->next);
}
