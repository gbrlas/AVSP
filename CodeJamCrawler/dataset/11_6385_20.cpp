#include<stdio.h>
int main()
{
	int re;
	int n,m,pd,k,i,j;
	char a[100][100];
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&re);
	k=1;
	while(re--)
	{	
		scanf("%d%d",&n,&m);
		pd=0;
		getchar();
		for(i=0;i<n;i++)
			scanf("%s",&a[i]);
		getchar();
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='#')
				{
					if(a[i][j+1]=='#'&&a[i+1][j]=='#'&&a[i+1][j+1]=='#')
					{
						a[i][j]='/';
						a[i][j+1]='\\';
						a[i+1][j]='\\';
						a[i+1][j+1]='/';
					}
					else
					{
						pd=1;break;
					}
				}
				if(pd)break;
			}
		printf("Case #%d:\n",k++);
		if(pd)printf("Impossible");
		else
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
					printf("%c",a[i][j]);
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}