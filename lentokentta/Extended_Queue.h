#include "Queue.h"


class Extended_Queue: public Queue
{
public:
  bool full() const;
  int size() const;
  void clear();
  Error_code serve_and_retrieve(Queue_entry &item);
};
