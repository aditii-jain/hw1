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
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr) {
    return;
  }
  // in = 4->5->1->2
  // curr = 4->5->1->2, in = 5->1->2, evens = NULL
  // curr = 4->null, evens = 4->null
  // split(5->1->2, null, 4->null)
  Node* temp = in->next;
  if (in->value % 2 == 0) {
    in->next = evens;
    evens = in;
  } else {
    in->next = odds;
    odds = in;
  }
  in = temp;
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
