#include<stdio.h>
#include<memory.h>
#include<string.h>
int main()
{
	freopen("test.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,s,q,i,j,k,l,min,t,a[102][1024];
	char c[102][110],d[110];
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(l=1;l<=n;l++)
	{
		scanf("%d\n",&s);		
		for(i=0;i<s;i++)
		{
			gets(c[i]);		
		}
		scanf("%d\n",&q);
		for(i=1;i<=q;i++)
		{
			gets(d);			
			for(j=0;j<s;j++)
			{
				if(strcmp(d,c[j])==0){t=j;break;}
			}
			for(j=0;j<s;j++)
			{
				min=100000;
				for(k=0;k<s;k++)
				{
					if(k!=j && a[i-1][k]<min) min=a[i-1][k];
				}
				min++;
				if(j==t)
				{					
					a[i][j]=min;
				}
				else
				{					
					if(a[i-1][j]<min) a[i][j]=a[i-1][j];
					else a[i][j]=min;
				}
			}
		}
		min=1000000;
		for(i=0;i<s;i++)if(a[q][i]<min)min=a[q][i];
		printf("Case #%d: %d\n",l,min);
	}
	return 1;
}