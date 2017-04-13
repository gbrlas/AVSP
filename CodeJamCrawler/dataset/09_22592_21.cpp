/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
char a[50][50];
int num[50];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-out.txt","w",stdout);
	int cas,i,j,n,t;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		memset(a,NULL,sizeof(a));
		memset(num,-1,sizeof(num));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		   scanf("%s",&a[i]);
   		for(i=0;i<n;i++)
		{
		   int ok=0;
		   for(j=n-1;j>=0 && ok==0;j--)
		   {
		   	   if(a[i][j]=='1')
		   	   {
		   	   	   num[i]=j;
		   	   	   ok=1;
			   }
		   }
		}
		//for(i=0;i<n;i++) printf("%d  ",num[i]);printf("\n");
		int cnt=0;
		for(i=0;i<n;i++)
		{
          if(num[i]>i)
		  {
			int ok=0;
			for(j=i;j<n && ok==0;j++)
			{
				if(num[j]<=i)
				{
					int k;
					for(k=j-1;k>=i;k--)
					{
						int tmp=num[k+1];
						num[k+1]=num[k];
						num[k]=tmp;
						cnt++;
						//for(int l=0;l<n;l++)
						//   printf("%d  ",num[l]);
			            //printf("\n");
					}
					ok=1;
				}
			}
		  }
		}
		printf("Case #%d: %d\n",cas,cnt);
	}
	return 0;
}
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b;
double x[1001],y[1001],r[1001];
int n,ans;

double low,high,mid,eps=1e-8;
bool check(double R)
{
	int i,j;
	double x1,y1,x2,y2,xx1,yy1,xx2,yy2;
	bool used[44]={0};
	for(i=0;i<n;i++)
	{
	    if(R<r[i])
		   return false;	
	}
    if(n<=2)
       return true;
    if((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1])<=(R-r[0]+R-r[1])*(R-r[0]+R-r[1]))
         return true;
    if((x[0]-x[2])*(x[0]-x[2])+(y[0]-y[2])*(y[0]-y[2])<=(R-r[0]+R-r[2])*(R-r[0]+R-r[2]))
         return true;
    if((x[2]-x[1])*(x[2]-x[1])+(y[2]-y[1])*(y[2]-y[1])<=(R-r[2]+R-r[1])*(R-r[2]+R-r[1]))
         return true;
    return false;
}
int main()
{
	int i,j,tst=0,jj,t;
	freopen("D-small-attempt1.in","r",stdin);
	freopen("fuck.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
		   scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
	    low=0;
	    tst++;
	    high=(double)1000000000*(double)1000000000;
	    while(low<high-eps)
	    {
	    	 mid=(low+high)/2.000;
	    	 if(check(mid))
	    	    high=mid;
  	         else
  	            low=mid+eps;
	    }
		printf("Case #%d: ",tst);
		if(n==1)
		   low=r[0];
		  printf("%.5f\n",low);
	}
	return 0;
}

