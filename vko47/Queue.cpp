#include "Queue.h"

Queue::Queue()
{
  front = rear = NULL;
}

Error_code Queue::append(const Queue_entry &item)
/*
Post: Add item to the rear of the Queue and return a code of success
      or return a code of overflow if dynamic memory is exhausted.
*/
{
   Node *new_rear = new Node(item);
   if (new_rear == NULL) return overflow;
   if (rear == NULL) front = rear = new_rear;
   else {
      rear->next = new_rear;
      rear = new_rear;
   }
   return success;
}

Error_code Queue::serve()
/*
Post: The front of the Queue is removed.  If the Queue
      is empty, return an Error_code of underflow.
*/
{
   if (front == NULL) return underflow;
   Node *old_front = front;
   front = old_front->next;
   if (front == NULL) rear = NULL;
   delete old_front;
   return success;
}

bool Queue::empty()
{
  return(front == NULL && rear == NULL);
}

//presuming this is supposed to retrieve the item at the front of the
//queue, so acting on that basis
Error_code Queue::retrieve(Queue_entry &item) const
{
  if(empty())
  {
    return underflow;
  }
  item = front->entry;
  return success;
}
