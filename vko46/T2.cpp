#include<iostream>
#include"linkedStack.h"



void printChain(Node *start)
{
  int i=0;
  Node *head = start;
  do
  {
    std::cout << "Node " << i << std::endl;
    std::cout << "Entry: " << head->entry << std::endl
    << "Next: " << head->next << std::endl << std::endl;
    i++;
    if(head->next != NULL)
    {
      std::cout << "DEBUG";
      head=head->next;
    }
  }
  while(start->next!=NULL && i<7);
}

int main()
{
  char a = '0';
  char b = '1';
  Node *p1 = new Node(b);
  Node *p0 = new Node(a, p1);
  printChain(p0);
  p0->entry = a;
  p0->next = NULL;
  p1->entry=b;
  Node *p2 = p1;
  p2->next = p0;
  return 0;
}
