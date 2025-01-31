/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
  Node* odds = NULL;
  Node* evens = NULL;
  Node* in = new Node(6, new Node(4, new Node(3, new Node(1, new Node(0, new Node(7, NULL))))));
  
  split(in, odds, evens);
}
