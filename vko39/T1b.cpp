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
   stack<char> input;  //  declares and initializes a stack of numbers

   cout << " Type in a string." << endl
        << " The string will be printed in reverse order." << endl;
   cin  >> str;
   n = str.length();

   for (int i = 0; i < n; i++) {
      input.push(str.at(i));
   }

   cout << endl << endl;
   while (!input.empty()) {
      cout << input.top() << " ";
      input.pop();
   }
   cout << endl;
}
