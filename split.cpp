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
    return;
  }else{
    if(in->value %2 == 0){//Even case
      if(evens == nullptr){//Check if evens list is empty
        evens = in;//Make evens point at the node in list with the even value
        Node* temp_save = in;
        cout << "Even starting value was: " << evens->value << endl;
        split(in->next, odds, evens);//Note evens->next and in->next are the exactly same node
        evens = temp_save;//I created this variable so that the original in value of this call could be used for the header node of evens
        //Otherwise, the header node of evens would have been 3 since that is what would have came out of the above function call
      }else{//If the evens list has already been started
        evens->next = in;//Add element to the end of evens list
        split(in->next, odds, evens->next);
      }
    }else{//Odd case
      if(odds == nullptr){
        odds = in;//Make odds point at the node in list with the odd value
        split(in->next, odds, evens);
        odds = in; //Make odds point to the original "in" node of this call wich should be smaller than is value after returning from the function call
      }else{
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