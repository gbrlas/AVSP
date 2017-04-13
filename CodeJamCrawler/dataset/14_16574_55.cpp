#include<stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int a[4][4],b[4][4],p,q,j,k,s=0,r;
		scanf("%d",&p);
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				scanf("%d",&a[j][k]);
			}
		}
		scanf("%d",&q);
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				scanf("%d",&b[j][k]);
			}
		}
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if( a[p-1][j]==b[q-1][k] )
				{
					s++;
					r=a[p-1][j];
				}
				
			}
		}
		if(s==1)
		   printf("Case #%d: %d\n",i+1,r);
		else if(s>1)
		{
	           printf("Case #%d: Bad magician!\n",i+1);
		}
		else if(s==0)
	     	printf("Case #%d: Volunteer cheated!\n",i+1);
	}
	return 0;
}
