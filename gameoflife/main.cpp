#include<iostream>
#include"life.h"

int main()  //  Program to play Conway's game of Life.
/*
Pre:  The user supplies an initial configuration of living cells.
Post: The program prints a sequence of pictures showing the changes in
      the configuration of living cells according to the rules for
      the game of Life.
Uses: The class Life and its methods initialize(), print(), and update().
      The functions  instructions(),  user_says_yes().
*/

{
   Life configuration;
   configuration.setUp();
   configuration.instructions();
   configuration.initialize();
   configuration.print();
   std::cout << "Continue viewing new generations?" << std::endl;
   //std::cout << "DEBUG";
   while (configuration.user_says_yes())
   {
     configuration.update();
     configuration.print();
     std::cout << "Continue viewing new generations? " << std::endl;
   }
}
