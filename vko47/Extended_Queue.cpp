#include "Extended_Queue.h"

int Extended_Queue::size() const
/*
Post: Return the number of entries in the Extended_queue.
*/
{
   Node *window = front;
   int count = 0;
   while (window != NULL) {
      window = window->next;
      count++;
   }
   return count;
}
//answer to question: Because making it a function allows
//for testing of the condition in a clean manner
bool Extended_Queue::full() const
{
  Node *test = new Node();
  if(test==NULL)
  {
    delete test;
    return true;
  }
  else
  {
    delete test;
    return false;
  }
}

void Extended_Queue::clear()
{
  Queue_entry *executioner = front;
  Queue_entry *nextOnBlock;
  while(executioner)
  {
    nextOnBlock = executioner->next;
    delete executioner;
    executioner = nextOnBlock;
  }
  front=NULL;
  rear=NULL;
}

Error_code serve_and_retrieve(Queue_entry &item)
{
  Error_code ret = retrieve(item);
  ret = serve();
  return ret;
}
