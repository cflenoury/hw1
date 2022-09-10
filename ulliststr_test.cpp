/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
#include <stdexcept>
using namespace std;
#include <string>

void push_front_test();
void push_back_test();
void pop_back_test();
void pop_front_test();
void front_back_test();

int main(int argc, char* argv[])
{
  cout << "Starting test\n";
 
  ULListStr dat;

  //Push front when empty
  dat.push_front("new");

  //Push_front() when there is no space in the head_ to add a value to the front of its array
  dat.push_front("spanking");

  //push_front() when there is space before the first element in the head item
  dat.push_front("brand");
  dat.push_front("is");
  dat.push_front("It");

  //Check size while priting list
  for(size_t i = 0; i < dat.size(); i++){
    cout << dat.get(i) << " ";
  }
  cout << endl;
 
  //pop_back() when there is 1 item in the tail
  dat.pop_back();

  //pop_back() when there are multiple items in the tail
  dat.pop_back();

  for(size_t i = 0; i < dat.size(); i++){
    cout << dat.get(i) << " ";
  }

  cout << endl;

  //push_back() when the tail has space for more items
  dat.push_back("spanking");

  //push_back() when there is no spcae in the tail for more items
  dat.push_back("new");

  //pop_front() when there are mulitple items in the head
  for(size_t i = 1; i < dat.size()-1; i++){
    dat.pop_front();
  }

  for(size_t i = 0; i < dat.size(); i++){
    cout << dat.get(i) << " ";
  }

  cout << endl;

  //pop_front() when there is 1 item in head
  dat.pop_front();

  for(size_t i = 0; i < dat.size(); i++){
    cout << dat.get(i) << " ";
  }

  cout << endl;
  
  dat.pop_front();
  
  try{
    //front() and back() when there is nothing in the list
    dat.front();
    dat.back();

    //pop_front() when there is nothing in the list
    dat.pop_front();

    //pop_back() when there is nothing in the list
    dat.pop_back();
  }

  catch (std::invalid_argument& e){
    cerr << e.what() << endl;
  }

  if(dat.empty()){
    cout << "There is currently nothing in the list\n";
  }

  //push_back() when there is nothing in the list
  dat.push_back("It's");
  dat.push_back("brand");
  dat.push_back("spanking");
  dat.push_back("new");

  for(size_t i = 0; i < dat.size(); i++){
    cout << dat.get(i) << " ";
  }

  cout << endl;

  //Test front and back
  cout << "\"" << dat.front() <<"\" is at the front of the list and \"" << dat.back() << "\" is at the back of the list.\n";

  return 0;
}

void push_front_test()
 {//Testing push_front: Create list backwards
    ULListStr dat;
    for(int i = 1; i <= 10; i++){
      dat.push_front(std::to_string(i));
    }
    dat.push_front("hard!");
    dat.push_front("of");
    dat.push_front("kind");
    dat.push_front("is");
    dat.push_front("104");
    dat.push_front("CSCI");
    dat.push_front("cool.");
    dat.push_front("is");
    dat.push_front("Caleb");

    cout << "This is the size after using push_front: " << dat.size() << endl;

    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    cout << endl;
  }

void push_back_test()
{//Testing push_back(): Create list, push to the back of it, print everytihng you added
    ULListStr dat;

    dat.push_back("Caleb");
    dat.push_back("is");
    dat.push_back("cool.");
    dat.push_back("CSCI");
    dat.push_back("104");
    dat.push_back("is");
    dat.push_back("kind");
    dat.push_back("of");
    dat.push_back("hard!");

    for(int i = 1; i <= 10; i++){
      dat.push_back(std::to_string(i));
    }

    cout << "This is the size after using push_back: " << dat.size() << endl;

    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    cout << endl;
  }

void pop_back_test()
{
    ULListStr dat;

    dat.push_back("Caleb");
    dat.push_back("is");
    dat.push_back("cool.");
    dat.push_back("CSCI");
    dat.push_back("104");
    dat.push_back("is");
    dat.push_back("kind");
    dat.push_back("of");
    dat.push_back("hard!");
    dat.push_back("But");
    dat.push_back("w/e");

    cout << "Current list contains: ";
    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    for(size_t i = 0; i < 4; i++){
      dat.pop_back();
    }

    cout << "\nThis is the list after 4 pop_backs: ";
    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    cout << endl;

  }

void pop_front_test()
{
    cout << "Why are we not making it?\n";
    ULListStr dat;

    dat.push_back("Caleb");
    dat.push_back("is");
    dat.push_back("cool.");
    dat.push_back("CSCI");
    dat.push_back("104");
    dat.push_back("is");
    dat.push_back("kind");
    dat.push_back("of");
    dat.push_back("hard!");
    dat.push_back("But");
    dat.push_back("w/e");

    cout << "Current list contains: ";
    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    for(size_t i = 0; i < 10; i++){
      dat.pop_front();
    }

    cout << "\nThis is the list after 10 pop_fronts: ";
    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    cout << endl;

  }

void front_back_test()
{
     ULListStr dat;

    dat.push_back("Caleb");
    dat.push_back("is");
    dat.push_back("cool.");
    dat.push_back("CSCI");
    dat.push_back("104");
    dat.push_back("is");
    dat.push_back("kind");
    dat.push_back("of");
    dat.push_back("hard!");
    dat.push_back("But");
    dat.push_back("w/e.");

    cout << "Current list contains: ";
    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    cout << "\n\"" << dat.front() <<"\" is at the front of the list and \"" << dat.back() << "\" is at the back of the list.\n";
  }
