#include"Stack.h"

//make sure Stack.h has typedef char Stack_entry

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

  std::cout << "The reversed string: ";

  while(!storage.empty())
  {
    storage.top(c);
    std::cout << c;
    storage.pop();
  }
  std::cout << std::endl;
  return 0;
}
