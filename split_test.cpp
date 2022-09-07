#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    //Create head pointer
  Node* initial = new Node(1, nullptr);
  Node* init_head = initial;
  int i = 2;
  while(i<=100){
    initial->next = new Node(i, nullptr);
    initial = initial->next;
    i+=3;
  }

  Node* evens = nullptr;
  Node* odds = nullptr;

  cout << "initial list ( initial :-) ): ";
  printLists(init_head);

  split(init_head, odds, evens);  

  cout << "initial list ( final ): ";
  printLists(init_head);

  cout << "odds:";
  printLists(odds);

  cout << "evens:";
  printLists(evens);  

  return 0;
}


