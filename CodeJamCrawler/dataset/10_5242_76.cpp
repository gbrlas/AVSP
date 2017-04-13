//google jam p1 2010-05-08

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int t;
int r;
int k;
int n;
int a[1010];

int cost[1010];
int next[1010];
int f[1010];
int ff[1010];

#define Bigint int
void get_list()
{	
	  int i;
	  int j;
	  int p;
	  int t;
 	  for(i=0;i<n;i++)
	   {
	      t=0;
	      p=i;
	      for(j=0;j<n;j++)
	      {
 			  if( t+a[p] <= k && t+a[p] >=0)
		      {
			   	  t=t+a[p];
			   	  p++;
			   	  if( p==n )
			   	  {
				     p=0;
				  }
	  		  }else
			  {
			   	   break;
		      }  
		  }
		  cost[i]=t;
		  next[i]=p;
	   }
     for(i=0;i<n;i++)
     {
	  				 cout<<i<<" cost="<<cost[i]<<" next="<<next[i]<<endl;
     }
}

Bigint get_ans()
{
 	   get_list();
 	   Bigint ans=0;
	   int i;
	   int p=0;
	   for(i=0;i<n;i++) f[i]=-1;
	   f[0]=0;
	   ff[0]=0;
	   i=1;
	   int step;
	   int cost_step;
	   int rr=r;
	   while(i<=r)
	   {
           ans+=cost[p];
           p=next[p];
           rr--;
		   if( f[p]>=0 )
           {
		   	   step=i-f[p];
		   	   cost_step=ans-ff[p];
 	   		   if( rr >=step )
		   	   {
			   	  int d=rr / step;
				  ans+=d*cost_step;
				  rr-=d*step;
				  i+=d*step;
			   }
		   }else
		   {
		   		f[p]=i;
		   		ff[p]=ans;
		   }
   	   	   i++;
	   }  
 	   return ans;
}

int main()
{
    ifstream fin("C-small-attempt0.in");
    ofstream fout("C-small-attempt0.out");
    fin>>t;     
	for(int i=1;i<=t;i++)
    {
        fin>>r>>k>>n;
        for(int j=0;j<n;j++)
        {
		 		fin>>a[j];
        }
	  	fout<<"Case #"<<i<<": "<<get_ans()<<endl;
    }
    fout.close();
   // while (1);
    return 0;
}
