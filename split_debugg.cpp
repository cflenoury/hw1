/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in == nullptr){//Determine if you are at the end of the list
    odds->next = nullptr;
    evens->next = nullptr;
    //cout << "Final odd value: " << odds->value << endl << "Final even value: " << evens->value << endl;
    return;
  }else{
    if(in->value %2 == 0){//Even case
      if(evens == nullptr){//Check if evens list is empty
        cout << "Starting evens list with " << in->value << "\n";
        evens = in;//Make evens point at the node in list with the even value
        Node* temp_save = in;
        cout << "Even starting value was: " << evens->value << endl;
        split(in->next, odds, evens);//Note evens->next and in->next are the exactly same node
        evens = temp_save;
        cout << "Even starting value is: " << evens->value << endl;

      }else{//If the evens list has already been started
        cout << "Adding " << in->value << " to evens list\n";
        evens->next = in;//Add element to the end of evens list
        //cout << "Evens: " << evens->value << " | Evens->next: " << evens->next->value<<"\n";
        split(in->next, odds, evens->next);
      }
    }else{//Odd case
      if(odds == nullptr){
      //cout << "Starting odds list with " << in->value << "\n";
        odds = in;//Make odds point at the node in list with the odd value
        split(in->next, odds, evens);
        odds = in; //Make odds point to the original "in" node of this call wich should be smaller than is value after returning from the function call
      }else{
        //cout << "Adding " << in->value << " to odds list\n";
        odds->next = in;
        split(in->next, odds->next, evens);
      }
    }
  }

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE

void printLists(Node* list){
    if(list == nullptr){
      cout << endl;
        return;
    }
    cout << list->value << " ";
    printLists(list->next);
}