#include"Stack.h"
#include"Utility.h"

//make sure Stack.h has typedef int Stack_entry

int main()
{
  std::string input;
  Stack storage;
  int n = 0;
  int prev = 0;
  int i = 1;
  std::string suffix;
  bool keepGoing = true;
  std::cout << "Input numbers." << std::endl;
  std::cout << "Each number has to be greater than the last." << std::endl;
  std::cout << "End by inputting a smaller number." << std::endl;
  std::cout << "The program also proceeds if enough numbers are inputted." << std::endl;

  while(!storage.full() && keepGoing)
  {
    switch (i) {
      case 1: suffix = "st"; break;
      case 2: suffix = "nd"; break;
      case 3: suffix = "rd"; break;
      default: suffix = "th"; break;
    }
    std::cout << "Please input " << i << suffix << " number: ";
    if(storage.empty())
    {
      n = readInt();
      storage.push(n);
    }
    else
    {
      n = readInt();
      storage.top(prev);
      if(n<prev)
      {
        keepGoing = false;
      }
      else
      {
        storage.push(n);
      }
    }
    i++;
  }

  std::cout << "numbers in reverse order:" << std::endl;

  while(!storage.empty())
  {
    storage.top(n);
    std::cout << n << std::endl;
    storage.pop();
  }

}
