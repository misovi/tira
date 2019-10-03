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
   Error_code copy_stack_A(Stack &dest, Stack &src);
   Error_code copy_stack_B(Stack &dest, Stack &src);
   friend Error_code copy_stack_C(Stack &dest, Stack &src);
   bool full(Stack &s);
   Error_code pop_top(Stack &s, Stack_entry &e);
   void clear(Stack &s);

private:
   int count;
   Stack_entry entry[maxstack];
};
