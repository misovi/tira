#include<iostream>
#include "life.h"
#include<limits.h>
#include<fstream>

int Life::neighbor_count(int row, int col)
/*
Pre:  The Life object contains a configuration, and the coordinates
      row and col define a cell inside its hedge.
      EDIT 6.9.2019 14:30: NOT INSIDE HEDGE BUT INSIDE FIELD
Post: The number of living neighbors of the specified cell is returned.
*/

{
   int i = row;
   int j=col;
   int count = 0;
   int i_limit = 0;
   int j_limit = 0;
   if(row==0 && col==0)
   {
     i_limit = j_limit = 1;
   }
   else if(row==maxrow-1 && col==maxcol-1)
   {
     i = row-1;
     j = col - 1;
     i_limit = row;
     j_limit = col;
   }
   else if(row == 0)
   {
     i = 0;
     j = col-1;
     i_limit = 1;
     j_limit = col+1;
   }
   else if(row == maxrow-1)
   {
     i = row-1;
     j = col-1;
     i_limit = row;
     j_limit = col+1;
   }
   else if(col == 0)
   {
     i = row-1;
     j = 0;
     i_limit = row + 1;
     j_limit = 1;
   }
   else if(col == maxcol-1)
   {
     i = row-1;
     j = col - 1;
     i_limit = row+1;
     j_limit = col;
   }
   else
   {
     i=row-1;
     j=col-1;
     i_limit = row+1;
     j_limit = col+1;
   }
   for (i; i <= i_limit; i++)
      for (j; j <= j_limit; j++)
         count += grid[i][j];  //  Increase the count if neighbor is alive.
   count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.

   /*for (i = row - 1; i <= row + 1; i++)
      for (j = col - 1; j <= col + 1; j++)
         count += grid[i][j];  //  Increase the count if neighbor is alive.
   count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.*/
   return count;
}

void Life::update()
/*
Pre:  The Life object contains a configuration.
Post: The Life object contains the next generation of configuration.
*/

{
   int row, col;
   int new_grid[maxrow][maxcol];

   for (row = 0/*1*/; row < maxrow; row++)
      for (col = 0 /*1*/; col < maxcol; col++)
         switch (neighbor_count(row, col)) {
         case 2:
            new_grid[row][col] = grid[row][col];  //  Status stays the same.
            break;
         case 3:
            new_grid[row][col] = 1;                //  Cell is now alive.
            break;
         default:
            new_grid[row][col] = 0;                //  Cell is now dead.
         }

   for (row = 0; row < maxrow; row++)
      for (col = 0; col < maxcol; col++)
         grid[row][col] = new_grid[row][col];
}

void Life::initialize()
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
EDIT 9.9.2019 15:47 THE USER IS EXPECTED TO INPUT BASED ON 1 START INDEXING
*/

{
   int row, col;
   std::vector<int> column;
   /*for (row = 0; row <= maxrow; row++)
      for (col = 0; col <= maxcol; col++)
         grid[row][col] = 0;*/
   for(row = 0; row < maxrow; row++)
   {
     for(col = 0; col < maxcol; col++)
     {
       column.push_back(0);
     }
     grid.push_back(column);
   }
   std::cout << "List the coordinates for living cells." << std::endl;
   std::cout << "Terminate the list with the special pair -1 -1" << std::endl;
   std::cin >> row >> col;

   while (row != -1 || col != -1) {
      if (row >= 1 && row <= maxrow)
         if (col >= 1 && col <= maxcol)
            grid[row-1][col-1] = 1;
         else
            std::cout << "Column " << col << " is out of range." << std::endl;
      else
         std::cout << "Row " << row << " is out of range." << std::endl;
      std::cin >> row >> col;
   }
}

void Life::print()
/*
Pre:  The Life object contains a configuration.
Post: The configuration is written for the user.
*/

{
   int row, col;
   std::cout << "\nThe current Life configuration is:" << std::endl;
   for (row = 0; row < maxrow; row++) {
      for (col = 0; col < maxcol; col++)
         if (grid[row][col] == 1) std::cout << '*';
         else std::cout << ' ';
      std::cout << std::endl;
   }
   std::cout << std::endl;
}

void Life::instructions()
/*
Pre:  None.
Post: Instructions for using the Life program have been printed.
*/

{
   std::cout << "Welcome to Conway's game of Life." << std::endl;
   std::cout << "This game uses a grid of size "
        << maxrow << " by " << maxcol << " in which" << std::endl;
   std::cout << "each cell can either be occupied by an organism or not." << std::endl;
   std::cout << "The occupied cells change from generation to generation." << std::endl;
   std::cout << "according to the number of neighboring cells which are alive."
        << std::endl;
}

bool Life::user_says_yes()
{
  std::cout << "DEBUG";
   int c;
   bool initial_response = true;

   do {  //  Loop until an appropriate input is received.
      if (initial_response)
         std::cout << " (y,n)? " << std::flush;

      else
         std::cout << "Respond with either y or n: " << std::flush;

      do { //  Ignore white space.
         c = std::cin.get();
      } while (c == '\n' || c ==' ' || c == '\t');
      initial_response = false;
   } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
   return (c == 'y' || c == 'Y');
}

void Life::setUp()
{
  /*
  Pre:  None.
  Post: User has inputted the desired play field proportions
  */
  //variable definitions
  int maxw = 70;
  int maxh = 23;
  int minh = 6;
  int minw = 6;
  int width = 0;
  int height = 0;
  std::string inputErr = "Try again! minimum value is " + std::to_string(minw) + " and maximum value is " + std::to_string(maxw);

  //*****************functionality: start************************************

  std::cout << "Before we get started, you need to provide some initial info." << std::endl;
  do {
    std::cout << "what do you want the width of the game board to be?" << std::endl;
    try
    {

      width = readInt();
      if(width>maxw || width < minw)
      {
        std::cout << inputErr << std::endl;
      }
      else
      {
        maxcol=width;
      }
    }
    catch(std::exception e)
    {
      width = 0;
      std::cout << inputErr << std::endl;
    }
  } while(width>maxw || width<minw);
  do {
    std::cout << "what about the height?" << std::endl;
    try
    {
      //std::cout << "DEBUG2" << '\n';
      //std::cin >> height;
      height = readInt();
      if(height>maxh || height < minh)
      {
        std::cout << inputErr << std::endl;
      }
      else
      {
        maxrow = height;
      }
    }
    catch(std::exception e)
    {
      std::cout << inputErr << std::endl;
      height = 0;
    }
  } while(height>maxh || height<minh);
}

int Life::readInt()
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

char Life::readChar()
{
  /*
  Pre:  None.
  Post: User has inputted a character
  */
  std::string str = "";
  char out = '';
  while(out == '')
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
}

char Life::readChar(std::string acceptedChars)
{
  /*
  Pre:  acceptedChars is NOT EMPTY.
  Post: User has inputted one of the accepted characters
  */
  std::string str = "";
  char out = '';
  while(out == '')
  {
    std::cin >> str;
    if(str.length() == 1 && characterExists(str.at(0), acceptedChars))
    {
      out = str.at(0);
    }
    else
    {
      std::cout << "wrong character. Input a new one:" << std::endl;
    }
  }
}

bool Life::characterExists(char c, std::string acceptedChars)
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

void Life::save()
{
  std::fstream save;
  save.open("sav.txt", std::ios::trunc);
  for(int i=0;i<maxrow;i++)
  {
    for(int j=0;j<maxcol;j++)
    {
      save << grid[i][j];
    }
    if(i!= maxrow-1)
    {
      save << std::endl;
    }
  }
  save.close();
}

bool Life::load()
{
  std::string line;
  std::fstream save;
  int live = 0;
  try
  {
    save.open("sav.txt", std::ios::in);
    grid.clear();
    std::vector<int> cols;
    while(std::getline(save, line))
    {
      for(int i = 0; i<line.length();i++)
      {
        if(line.at(i)==' ')
        {
          cols.push_back(0);
        }
        else
        {
          cols.push_back(1);
        }
      }
      grid.push_back(cols);
    }
    maxrow = grid.size();
    maxcol = grid[0].size();
    std::cout << "Load succesful. The grid is " << maxrow << " times " << maxcol
    << " spaces in total, and has" << live << " live cells in it." << std::endl;
    return true;
  }
  catch(std::exception& e)
  {
    std::cout << "file not found!";
    return false;
  }

}
