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
  cout << "Split ran \n";
  if(in == nullptr){//Determine if you are at the end of the list
    return;
  }else{
    if(in->value %2 == 0){//Even case
      if(evens == nullptr){//Check if evens list is empty
        cout << "Starting evens list with " << in->value << "\n";
        evens = in;//Make evens point at the node in list with the even value
      }else{//If the evens list has already been started
        cout << "Adding " << in->value << " to evens list\n";
        evens->next = in;//Add element to the end of evens list
        //(odds and evens should always be the last node in the list)
      }
    }else{//Odd case
      if(odds == nullptr){//Check if odds list is empty
      cout << "Starting odds list with " << in->value << "\n";
        odds = in;//Make odds point at the node in list with the odd value
      }else{//If the evens list has already been started
        cout << "Adding " << in->value << " to odds list\n";
        odds->next = in;//Add element to the end of evens list
        //(odds and evens should always be the last node in the list)
      }
    }
    //Call function on next item in original list (which should be in either 
    //evens or odds)
    split(in->next, odds, evens);
    //in = nullptr;
  }

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE