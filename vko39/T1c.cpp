#include   <stack>
#include<iostream>

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in reverse order.
Uses:  The STL class stack and its methods
*/

{
  using namespace std;
   string str;
   int n = 0;
   char c = 'a';
   int i = 0;
   stack<char> input;  //  declares and initializes a stack of numbers

   cout << "Type in a string." << endl
        << "The program determines if the string is a palindrome." << endl;
   cin  >> str;
   n = str.length();

   for (i = 0; i < n; i++)
   {
      input.push(str.at(i));
   }

   //cout << endl << endl;
   i=0;
   while (!input.empty()) {
      c = input.top();
      input.pop();
      if(str.at(i) != c)
      {
        cout << str << " is not a palidrome." << endl;
        return 0;
      }
      i++;
   }
   cout << str << " is a palidrome." << endl;
   return 0;
}
