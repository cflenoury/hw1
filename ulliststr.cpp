#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

////clean up
#include <iostream>
////

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
  void ULListStr::push_front(const std::string& val){
    //Is this initial push (first item in list)?
    if(empty()){
      head_ = new Item;
      head_->val[0] = val;
      head_->last = 1;
      tail_ = head_;
    }else{
      //Check if there is room before the first string in the head node
      if(head_->first != 0){//If there is room before the first string
        head_->val[head_->first - 1] = val;//Assign val to the space before the first string in array
        head_->first--;//Set first to now be one index less
      }else if (head_->first == 0){//If there is no room before the first string create a new node and store the value there
        Item* temp = new Item;
        temp->val[ARRSIZE-1] = val;
        temp->next = head_;//Make new node point to old head
        head_ = temp;//Make head_ point to this new node
        head_->first = ARRSIZE-1;//Set first of this node to the index where the string was placed (end of array)
        head_->last = ARRSIZE;    //Set last to the place after where the string was placed (ARRSIZE)
      }
    }    

    //Increment size
    size_++;
    //std::cout << "The size is now " << size_ << std::endl;
    //std::cout <<"\"" << head_->val[head_->first]<<"\" is now at the front of the list\n";

  }

void ULListStr::push_back(const std::string& val){
  if(empty()){
    tail_ = new Item;
    tail_->val[0] = val;
    tail_->last = 1;
    head_ = tail_;
  }else{
    //Is there room in the tail_ for another item?
    if(tail_->last == ARRSIZE){//tail_ is full
      //std::cout << "Attempting to create new item\n";
      Item* temp = new Item;
      temp->val[0] = val;
      temp->prev = tail_;
      tail_->next = temp;
      tail_ = temp;
      tail_->last=1;
      //std::cout << "First value in new item is " << tail_->val[0] <<std::endl;
    }else{//tail_ has space for more values
      //Place  val in "last" index
      tail_->val[tail_->last] = val;

      //Increment "last" index
      tail_->last++;
    }
  }
  size_++;//increment size_
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  //std::cout << "Getting value...\n";
  //Check if loc is valid
  if(loc < 0 || loc >= size_){
    return nullptr;
  }else{//If loc is valid
    if(loc <= (ARRSIZE - head_->first-1)){ //Is loc in head?
      //std::cout << (ARRSIZE - head_->first) << " <- should be 2\n";
      //Item of interest is in the head_
      return &head_->val[head_->first + loc];
    }else{//Item is not in head    
      //std::cout << "last iter?\n";
      //How many items are in head_? Subtract that from loc
      int items_in_head = ARRSIZE - head_->first;
      //std::cout << "There are " << items_in_head << " items in head.\n";

      loc -= (items_in_head);

      //Int divide loc w/ ARRSIZE to find how many nodes ahead of head_ it is in
      int num_item_jumps = ((int)loc / (int)ARRSIZE) + 1;
      //std::cout << "You would jump " << num_item_jumps << " times through all items starting at head\n";

      //Go forward in list by number of item jumps
      Item* temp = head_;

      for(int i = 0; i < num_item_jumps; i++){
        temp = temp->next;
      }

      //std::cout << "Returning item at index " << (int)loc % 10 << " of " << num_item_jumps << " (st/nd/rd/th) item after head\n";
      //std::cout << "That item is " << temp->val[(int)loc % 10] << std::endl;
      
      //temp == tail_? std::cout << "we are in the tail\n" : std::cout << "We are not in the tail\n" ;
      //std::cout << "(T/F) We are in the tail: " << fff  << std::endl;

      return &temp->val[(int)loc % 10];
    }
  }
}