#include "Stack.h"
#include<iostream>
#include<math.h>

int main()
{
  Stack dividers;
  int srcnumber = 2100;
  Stack_entry entry;

  while(srcnumber % 2 == 0)
  {
    dividers.push(2);
    srcnumber = srcnumber/2;
    std::cout << "debug1" << '\n';
  }

  for(int i = 3; i <= sqrt(srcnumber); i=i+2)
  {
    while(srcnumber % i == 0)
    {
      dividers.push(i);
      srcnumber = srcnumber/i;
    }
  }

  if(srcnumber>2)
  {
    dividers.push(srcnumber);
  }

  while(!dividers.empty())
  {
    dividers.top(entry);
    std::cout << entry << " ";
    dividers.pop();
  }
}
