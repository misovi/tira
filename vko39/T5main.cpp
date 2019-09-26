#include "Stack.h"


int main()
{
  Stack storage;
  bool assertion = false;
  for(int i=0;i<10;i++)
  {
    std::cout << "Loop index " << i << std::endl;
    assertion = i==storage.size();
    std::cout << assertion << std::endl;
    storage.push(1);
    assertion = i+1==storage.size();
    std::cout << assertion << std::endl;
  }

  assertion = storage.full() == true;

  std::cout << "Stack is full: " << assertion << std::endl;

  std::cout << "running clear..." << std::endl;

  storage.clear();

  assertion = storage.empty();

  std::cout << "empty() is true: " << assertion << std::endl;

  assertion = storage.size() == 0;

  std::cout << "size() returns 0: " << assertion << std::endl;
}
