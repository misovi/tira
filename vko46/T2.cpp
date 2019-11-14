#include<iostream>
#include"linkedStack.h"



void printChain(Node *start, int limit=99)
{
  int i=0;
  Node *head = start;
  while(head!=NULL&&i<limit)
  {
    std::cout << "Node " << i << std::endl;
    std::cout << "Entry: " << head->entry << std::endl
    << "Next: " << head->next << std::endl << std::endl;
    i++;
    head=head->next;
    }
  }

int main()
{
  char a = '0';
  char b = '1';
  char c = '2';
  Node *p1 = new Node(b);
  Node *p0 = new Node(a, p1);
  std::cout << "T2 a)" << std::endl << "==" << std::endl;
  printChain(p0);
  p0->entry = a;
  p0->next = NULL;
  p1->entry=b;
  Node *p2 = p1;
  p2->next = p0;
  std::cout << "T2 b)" << std::endl << "==" << std::endl;
  printChain(p0);
  printChain(p1);
  std::cout << "T2 c)" << std::endl << "==" << std::endl;
  p0->entry=a;
  p0->next=p1;
  p1->entry=b;
  p1->next=p2;
  p2->entry=c;
  p2->next=p1;
  printChain(p0, 10);
  delete p1,p2,p0;
  return 0;
}
