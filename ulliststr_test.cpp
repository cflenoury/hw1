/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;

////Clean up
#include <string>
////


int main(int argc, char* argv[])
{
  cout << "Starting test\n";

  {
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

    for(int i = 1; i <= 10; i++){
      dat.push_back(std::to_string(i));
    }

    cout << "This is the size after using push_back: " << dat.size() << endl;

    for(size_t i = 0; i < dat.size(); i++){
      cout << dat.get(i) << " ";
    }

    cout << endl;
  }

  return 0;
}
