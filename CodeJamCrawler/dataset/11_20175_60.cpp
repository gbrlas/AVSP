#include<iostream>
#include<cmath>
#include "stdlib.h"
#include "stdio.h"

using namespace std;
int main()
{
  int cas,i,t,n,a;

  freopen("D-large.in","r",stdin);
  freopen("output4.txt","w",stdout);

  scanf("%d",&t);
  for(cas=1;cas<=t;cas++)
    {
      scanf("%d",&n);
      double res=0.0;
      for(i=1;i<=n;i++)
	{
	  scanf("%d",&a);
	  if(a!=i)
	    {
	      res+=1.0;
	    }
	}
      printf("Case #%d: %.6f\n",cas,res);
    }
  scanf("%*d");

}
