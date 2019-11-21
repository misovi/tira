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
