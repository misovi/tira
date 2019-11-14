#include<iostream>
#include "linkedStack.h"

void print(Stack s);

int main()
{
  Stack test;
  print(test);
  for(int i = 0; i < 10; i++)
  {
    test.push('a');
    print(test);
  }
  for(int i = 0; i < 10; i++)
  {
    test.pop();
    print(test);
  }
}

void print(Stack s)
{
  using namespace std;
  std::cout << "===========" << '\n';
  std::cout << "size = " << s.size() << '\n'
  << "Count = " << s.getCount() << '\n';
  std::cout << "===========" << '\n';
}
