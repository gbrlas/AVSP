#include<string.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

int main()
{
	int t,m,n,i,j,k,l,err;
	char a[51][51];
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small.txt","w",stdout);
	scanf("%d\n",&t);

	for(i=0;i<t;i++)
	{
		scanf("%d %d",&m,&n);
		printf("Case #%d:\n",i+1);
		for(j=0;j<m;j++)
			scanf("%s",a[j]);
		err=0;
		if(m == 1)
		{
			for(j=0;j<n;j++)
				if(a[0][j] == '#')
					err=1;
		}
		for(j=0;j<m-1;j++)
		{
			err=0;
			for(k=0;k<n;k++)
			{
				if(a[j][k] == '#')
				{
					if(a[j][k+1] == '#' && a[j+1][k] == '#' && a[j+1][k+1] == '#')
					{
						a[j][k] = '/';
						a[j][k+1] = '\\';
						a[j+1][k] = '\\';
						a[j+1][k+1] = '/';
					}
					else
					{
						err=1;
						break;
					}
				}
			}
			if(err == 1) break;
		}
		if(err == 1)
			printf("Impossible\n");
		else
		{
			for(j=0;j<m;j++)
				printf("%s\n",a[j]);
		}
	}	
}

