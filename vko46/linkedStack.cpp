#include "linkedStack.h"
Stack::Stack()
{
  top_node = NULL;
  count = 0;
}


Error_code Stack::push(const Stack_entry &item)
/*
Post: Stack_entry item is added to the top of
      the Stack; returns success or returns a code
      of overflow if dynamic memory is exhausted.
*/
{
   Node *new_top = new Node(item, top_node);
   if (new_top == NULL) return overflow;
   top_node = new_top;
   count++;
   return success;
}


Error_code Stack::pop()
/*
Post: The top of the Stack is removed.  If the Stack
      is empty the method returns underflow; otherwise it returns success.
*/
{
   Node *old_top = top_node;
   if (top_node == NULL) return underflow;
   top_node = old_top->next;
   delete old_top;
   count--;
   return success;
}

Error_code Stack::top(Stack_entry& item) const
{
  if(top_node == NULL)
  {
    return underflow;
  }
  item = top_node->entry;
  return success;
}

int Stack::size()
{
  Node *ptr;
  int i = 0;
  if(top_node!=NULL)
  {
    ptr=top_node;
    while(ptr!=NULL)
    {
      ptr = ptr->next;
      i++;
    }
  }
  return i;
}

int Stack::getCount()
{
  return count;
}
