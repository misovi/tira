typedef int Stack_entry;
#include "Node.h"
#include "Utility.h"
class Stack {
public:
   Stack();
   bool empty() const;
   Error_code push(const Stack_entry &item);
   Error_code pop();
   Error_code top(Stack_entry &item) const;
   int size();
   int getCount();
protected:
   Node *top_node;
   int count;
};
