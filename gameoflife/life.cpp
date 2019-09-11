#include<iostream>
#include "life.h"

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
   for (row = 0; row <= maxrow; row++)
      for (col = 0; col <= maxcol; col++)
         grid[row][col] = 0;
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
