#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b;
char matrix[100][100];
int f[101];
int n,ans;
int main()
{
	int i,j,tst=0,jj,t;
	freopen("A.in","r",stdin);
	freopen("fuck.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    tst++;
	    memset(f,-1,sizeof(f));
	    for(i=0;i<n;i++)
	    {
    	   scanf("%s",matrix[i]);
	       for(j=0;j<n;j++)
	       {
	          if(matrix[i][j]=='1')
	          	  f[i]=j;
		   }
	    }
        ans=0;
		for(i=0;i<n;i++)
		{
			if(f[i]>i)
		    {
		    	for(j=i+1;j<n;j++)
		    	{
		    		if(f[j]<=i)
		    		   break;
		    	} 
		    	for(jj=i+1;jj<=j;jj++)
		    	  swap(f[i],f[jj]);
		    	ans+=j-i;
		    }
		}
		printf("Case #%d: ",tst);
		printf("%d\n",ans);
	}
	return 0;
}
