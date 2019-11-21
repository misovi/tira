typedef char Node_entry;
#include <iostream>
struct Node
{
//data members
  Node_entry entry;
  Node *next;

  //constructors
  Node();
  Node(Node_entry item, Node *add_on= NULL);
};
