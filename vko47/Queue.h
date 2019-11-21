#include "../Utility/Utility.h"
#include "../vko46/Node.h"
typedef Node Queue_entry;
class Queue
{
private:
  /* data */

public:
  Queue();
  bool empty() const;
  Error_code append(const Queue_entry &item);
  Error_code serve();
  Error_code retrieve(Queue_entry &item) const;
  ~Queue ();
  Queue(const Queue &original);
  void operator = (const Queue &original);
protected:
  Node *front, *rear;
};
