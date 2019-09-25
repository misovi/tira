typedef double Stack_entry;
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
   bool empty();

private:
   int count;
   Stack_entry entry[maxstack];
};
