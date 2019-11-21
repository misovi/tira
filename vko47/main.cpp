#include "Queue.h"

int main()
{
  Queue q;
  for(int i=0;i<9;i++)
  {
    q.append(i);
    //std::cout << "DEBUG1" << '\n';
  }
  return 0;
}
