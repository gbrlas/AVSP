#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
  int i,j,T,N,total,least,k,m,p,q;
  int value[20],index[20];
  double l;
  double y;
  FILE* f1 = fopen("candyresult.txt","w");
  for(i=0;i<20;i++)
    {
      y=(double)(i);
      value[i]=(int) (pow(2.0,y));
    }
  scanf("%d",&T);
  for(i=1;i<=T;i++)
    {
      for(j=0;j<20;j++)
	{
	  index[j]=0;
	}
      scanf("%d",&N);
      scanf("%d",&k);
      least=k;
      total=k;
      l= log2((double)k);
      m= (int)(l);
      for(p=m;p>=0;p--)
	{
	  if(value[p]<= k)
	    {
	      q=1;
	    }
	  else
	    {
	      q=0;
	    }
	  k=k-(q*value[p]);
	  index[p]=(index[p]+q)%(2);
	}
      fprintf(f1,"Case #%d: ",i);
      for(j=1;j<N;j++)
	{
	  scanf("%d", &k);
	  total=total+k;
	  if(least>k)
	    {
	      least=k;
	    }
	  l= log2(k);
	  m= (int)(l);
	  for(p=m;p>=0;p--)
	    {
	      if(value[p]<= k)
		{
		  q=1;
		}
	      else
		{
		  q=0;
		}
	      k=k-(q*value[p]);
	      index[p]=(index[p]+q)% 2;
	    }
	}
      q=0;
      for(j=0;j<20;j++)
	{
	  q=q+index[j];
	}
      if(q > 0)
	{
	  fprintf(f1,"NO\n");
	}
      else
	{
	  fprintf(f1,"%d\n",(total-least));
	}
    }
}
