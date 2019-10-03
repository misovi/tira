#include"Stack.h"

Error_code Stack::push(const Stack_entry &item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
      of the Stack.  If the Stack is full,
      an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
   Error_code outcome = success;
   if (count >= maxstack)
      outcome = overflow;
   else
      entry[count++] = item;
   return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else --count;
   return outcome;
}


Error_code Stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if(count == 0)
   {
     outcome = underflow;
   }
   else
   {
     item = entry[count-1];
   }
   return outcome;
}


bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/

{
   bool outcome = true;
   if (count > 0) outcome = false;
   return outcome;
}

bool Stack::full()
{
  return(count==maxstack);
}

int Stack::size()
{
  return count;
}

void Stack::clear()
{
  count = 0;
}

Error_code Stack::copy_stack_A(Stack &dest, Stack &src)
{
  dest = src;
  return success;
}

Error_code Stack::copy_stack_B(Stack &dest, Stack &src)
{
  Stack temp;
  Stack_entry entry;
  Error_code err;
  if(!dest.empty())
  {
    while(!dest.empty())
    {
      dest.pop();
    }
  }
  while(!src.empty())
  {
    src.top(entry);
    err = temp.push(entry);
    if(err == overflow)
    {
      return overflow;
    }
    src.pop();
  }

  while(!temp.empty())
  {
    temp.top(entry);
    src.push(entry);
    dest.push(entry);
    temp.pop();
  }

  return success;
}

Error_code copy_stack_C(Stack &dest, Stack &src)
{
  dest.count = src.count;
  for(int i = 0; i<dest.count;i++)
  {
    dest.entry[i] = src.entry[i];
  }
  return success;
}

bool Stack::full(Stack &s)
{
  Stack_entry probe;
  if(s.push(probe)==overflow)
  {
    return true;
  }
  else
  {
    s.pop();
    return false;
  }
}

Error_code Stack::pop_top(Stack &s, Stack_entry &e)
{
  Error_code err;
  err = s.top(e);
  err = s.pop();
  if(err == underflow || err == fail)
  {
    return fail;
  }
  else
  {
    return success;
  }
}

void Stack::clear(Stack &s)
{
  while(!s.empty())
  {
    s.pop();
  }
}


Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
   count = 0;
}
