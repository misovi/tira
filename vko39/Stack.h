typedef int Stack_entry;
//If compiling T3 of week 39, make sure typedef is char
//if T4, typedef must be int
#include"Utility.h"
// Section 2.2:

const int maxstack = 10;   //  small value for testing

class Stack {
public:
   Stack();
   bool empty() const;
   Error_code pop();
   Error_code top(Stack_entry &item) const;
   Error_code push(const Stack_entry &item);
   bool full();
   int size();
   void clear();

private:
   int count;
   Stack_entry entry[maxstack];
};
