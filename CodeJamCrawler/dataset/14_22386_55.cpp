#include<stdio.h>

int a[5][5];
int b[5][5];

int main()
{
	int t,p;
	int i,j;
	int aa,bb;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&aa);
		for (i=1;i<=4;i++)
			for (j=1;j<=4;j++)
				scanf("%d",&a[i][j]);		
		scanf("%d",&bb);
		for (i=1;i<=4;i++)
			for (j=1;j<=4;j++)
				scanf("%d",&b[i][j]);
		int flag=0;
		for (i=1;i<=4;i++)
		{
			for (j=1;j<=4;j++)
				if (a[aa][i]==b[bb][j]) break;
			if (j<=4)
			{
				if (flag>0)
				{
					printf("Case #%d: Bad magician!\n",p);
					break;
				}
				flag=a[aa][i];
			}
		}
		if (i==5)
		{
			if (flag==0) printf("Case #%d: Volunteer cheated!\n",p);
			else printf("Case #%d: %d\n",p,flag);
		}
	}
	return 0;
}
