#include<iostream>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

int main()
{
  int cas, mn, t, n, a, xr ,tt;
  scanf("%d",&t);

  for(cas=1;cas<=t;cas++)
    {
      scanf("%d",&n);
      tt=xr=0;
      mn=1<<30;
      while(n--)
	{
	  scanf("%d",&a);
	  xr^=a;
	  tt+=a;
	  if(mn>a)mn=a;
	}
      if(xr)
	{
	  printf("Case #%d: NO\n",cas);
	}
      else
	{
	  printf("Case #%d: %d\n",cas,tt-mn);
	}
    }
}
