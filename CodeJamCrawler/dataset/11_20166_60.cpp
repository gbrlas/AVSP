#include<iostream>
#include<cmath>
#include<string>
#include "stdio.h"
#include "stdlib.h"

using namespace std;
int o_last_p,b_last_p;
int o_last_t,b_last_t;
int work();

int main()
{
  freopen("A-large.in", "r", stdin);
  freopen("output1.txt", "w", stdout);

  int cas,t;
  scanf("%d",&t);
  for(cas=1;cas<=t;cas++)
    {
      printf("Case #%d: %d\n",cas,work());
    }
  return 0;
}


int work()
{
  int n;
  int now_time=0, p, cost, temp;

  o_last_t=b_last_t=0;
  o_last_p=b_last_p=1;
  char ch;
  scanf("%d",&n);
  while(n--)
    {
      do
        {
      scanf("%c",&ch);
        }while(ch!='O'&&ch!='B');
      scanf("%d",&p);
      if(ch=='O')
        {
      cost=abs(p-o_last_p)+1;
      temp=o_last_t+cost;
      if(temp>now_time+1)
            {
          now_time=temp;
          o_last_t=temp;
            }
      else
            {
          o_last_t=now_time+1;
          now_time++;
            }
      o_last_p=p;
        }
      else
        {
      cost=abs(p-b_last_p)+1;
      temp=b_last_t+cost;
      if(temp>now_time+1)
            {
          now_time=temp;
          b_last_t=temp;
            }
      else
            {
          b_last_t=now_time+1;
          now_time++;
            }
      b_last_p=p;
        }
    }
  return now_time;
}

