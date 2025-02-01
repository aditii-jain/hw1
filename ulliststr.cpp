#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std;
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

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val) {
    if (empty()) {
        // Create first item if list is empty
        Item* newItem = new Item();
        head_ = tail_ = newItem;
        tail_->first = 0;
        tail_->last = 0;
    }
    else if (tail_->last >= ARRSIZE) {
        // Create new item if current tail is full
        Item* newItem = new Item();
        newItem->prev = tail_;
        tail_->next = newItem;
        tail_ = newItem;
        tail_->first = 0;
        tail_->last = 0;
    }
    
    // Add the new value
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back() {
  if (!empty()) {
      tail_->last--;
      size_--;

      if (tail_->last == tail_->first) { // The item is now empty
          Item* temp = tail_;
          tail_ = tail_->prev;

          if (tail_ != NULL) {
              tail_->next = NULL;
          } else {
              head_ = NULL;  // both head and tail are NULL when the list is empty
          }

          delete temp;
      }
  }
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
*/
void ULListStr::push_front(const std::string& val) {
  if (empty() || head_->first == 0) {
      Item* newItem = new Item();
      newItem->next = head_;
      if (head_ != NULL) {
          head_->prev = newItem;
      } else {
          tail_ = newItem;
      }
      head_ = newItem;
      newItem->first = ARRSIZE;
      newItem->last = ARRSIZE;
  } 
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front() {
    if (!empty()) {
        head_->first++;
        size_--;

        if (head_->first == head_->last) { // The item is now empty
            Item* temp = head_;
            
            head_ = head_->next;

            if (head_ != NULL) {
                head_->prev = NULL;
            } else {
                tail_ = NULL;  // both head and tail are NULL when the list is empty
            }

            delete temp;
            
        }
    }
}
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return tail_->val[tail_->last - 1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head_->val[head_->first];
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
  Item *temp = head_;
  while(head_ != NULL) {
    temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const {
    size_t index = 0;
    Item* temp = head_;

    while (temp != NULL) {
        size_t numElements = temp->last - temp->first;
        if (loc < index + numElements) return &temp->val[temp->first + (loc - index)];
        index += numElements;
        temp = temp->next;
       
    }
  return NULL;
}
