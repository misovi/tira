#include <iostream>
#include "Utility.h"
using namespace std;

bool user_says_yes()
{
	int c;
	bool initial_response = true;

	do {  //  Loop until an appropriate input is received.
		if (initial_response)
			cout << " (y,n)? " << flush;

		else
			cout << "Respond with either y or n: " << flush;

		do { //  Ignore white space.
			c = cin.get();
		} while (c == '\n' || c == ' ' || c == '\t');
		initial_response = false;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	return (c == 'y' || c == 'Y');
}

int readInt()
{
  /*
  Pre:  None.
  Post: User has inputted an integer
  */
  std::string str = "";
  bool inputOK = false;
  int out = 0;
  while(!inputOK)
  {
    std::cin >> str;
    try
    {
      out = std::stoi(str);
      inputOK = true;
    }
    catch(const std::invalid_argument& e)
    {
      std::cout << "Not an integer!" << std::endl;
    }
    catch(const std::out_of_range& e)
    {
      std::cout << "Inputted number is way too large!" << std::endl;
    }
    catch(std::exception& e)
    {
      std::cout << "Something went terribly wrong!" << std::endl;
    }
  }
  return out;
}

char readChar()
{
  /*
  Pre:  None.
  Post: User has inputted a character
  */
  std::string str = "";
  char out;
	bool cont = true;
  while(cont)
  {
    std::cin >> str;
    if(str.length() == 1)
    {
      out = str.at(0);
    }
    else
    {
      std::cout << "input a single character." << std::endl;
    }
  }

	return out;
}

char readChar(std::string acceptedChars)
{
  /*
  Pre:  acceptedChars is NOT EMPTY.
  Post: User has inputted one of the accepted characters
  */
  std::string str = "";
	bool cont = true;
  char out;
  while(cont)
  {
    std::cin >> str;
    if(str.length() == 1 && characterExists(str.at(0), acceptedChars))
    {
      out = str.at(0);
			cont = false;
    }
    else
    {
      std::cout << "wrong character. Input a new one:" << std::endl;
    }
  }
	return out;
}

bool characterExists(char c, std::string acceptedChars)
{
  for(int i = 0; i<acceptedChars.length();i++)
  {
    if(acceptedChars.at(i) == c)
    {
      return true;
    }
  }
  return false;
}
