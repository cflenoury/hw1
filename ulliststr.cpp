#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
        temp->next = head_;//Make new node's next point to old head
        head_->prev = temp;//Make current head's prev point to newly created node
        head_ = temp;//Make head_ point to this new node
        head_->first = ARRSIZE-1;//Set first of this node to the index where the string was placed (end of array)
        head_->last = ARRSIZE;    //Set last to the place after where the string was placed (ARRSIZE)
      }
    }    

    //Increment size
    size_++;
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
      Item* temp = new Item;
      temp->val[0] = val;
      temp->prev = tail_;
      tail_->next = temp;
      tail_ = temp;
      tail_->last=1;
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
  //Check if loc is valid
  if(loc < 0 || loc >= size_){
    return nullptr;
  }else{//If loc is valid
    if(loc <= (ARRSIZE - head_->first-1)){ //Is loc in head?
      //Item of interest is in the head_
      return &head_->val[head_->first + loc];
    }else{//Item is not in head    
      //How many items are in head_? Subtract that from loc
      int items_in_head = ARRSIZE - head_->first;
      loc -= (items_in_head);

      //Int divide loc w/ ARRSIZE to find how many nodes ahead of head_ it is in
      int num_item_jumps = ((int)loc / (int)ARRSIZE) + 1;

      //Go forward in list by number of item jumps
      Item* temp = head_;

      for(int i = 0; i < num_item_jumps; i++){
        temp = temp->next;
      }

      return &temp->val[(int)loc % 10];
    }
  }
}

void ULListStr::pop_back(){
  
  if(size_== 0){//If there is nothing in the list, return an error
    throw std::invalid_argument("List is empty");
  }else{//Delete the last item in the list (which would be in the tail)
    if(tail_->last == 1){//Only one item is in the tail (@ index 0)
      Item* temp = tail_;//Create a temp Item* to reference the current tail
      tail_ = tail_->prev;//Make the previous item the new tail
      delete temp;//Delete original tail Item
    }else{//Multiple items are in the tail
      //Go to the tail_'s array and replace the last element with an empty string
      tail_->val[tail_->last-1] = "\0";
      tail_->last--;//Decrement last
    }
    size_--;//Decrement the size of the list
  }
}

void ULListStr::pop_front(){
  if(size_== 0){//If there is nothing in the list, return an error
    throw std::invalid_argument("List is empty");
  }else{//Delete the first item in the head
    if(head_->first == ARRSIZE-1){//There is only 1 item in the head
      Item* temp = head_;
      head_ = head_->next;
      delete temp;
    }else{//If there are multiple items in head_
      head_->val[head_->first] = "\0";
      head_->first++;
    }
    size_--;
  }
}

std::string const & ULListStr::front() const{
  if(size_==0){
    throw std::invalid_argument("List is empty");
  }else{
    return head_->val[head_->first];
  }
}

std::string const & ULListStr::back() const{
  if(size_==0){
    throw std::invalid_argument("List is empty");
  }else{
    return tail_->val[tail_->last-1];
  }
}