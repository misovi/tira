typedef char Stack_entry;
#include"Stack.h"

int main()
{
  std::string input;
  Stack storage;
  int size = 0;
  char c = 'A';
  std::cout << "Input a string: ";
  cin >> input;
  size = input.length();
  for(int i= 0; i<size;i++)
  {
    storage.push(input.at(i));
  }

  while(!storage.empty())
  {
    storage.top(c);
    std::cout << c;
    storage.pop();
  }
}
