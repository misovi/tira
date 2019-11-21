#include "Queue.h"

Queue::Queue()
{
  front = rear = NULL;
}

Queue::~Queue()
{
  Queue_entry *executioner = front;
  Queue_entry *nextOnBlock;
  while(executioner)
  {
    nextOnBlock = executioner->next;
    delete executioner;
    executioner = nextOnBlock;
    //std::cout << "DEBUG" << '\n';
  }
}

Queue::Queue(const Queue &old)
{
  Queue_entry *entry;
  old.retrieve(*entry);
  front = entry;
  entry=entry->next;
  while(entry)
  {
    append(*entry);
    rear = entry;
    entry=entry->next;
  }
}

void Queue::operator = (const Queue &original)
{
  Node *newFront;
  newCopy, origNode, origFront;
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

bool Queue::empty() const
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
  item = *front;
  return success;
}
