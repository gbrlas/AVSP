#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		int ans,a[5],b[5],x;
		scanf("%d",&ans);
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				if(i==ans)
				scanf("%d",&a[j]);
				else
				scanf("%d",&x);
			}
		}
		scanf("%d",&ans);
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				if(i==ans)
				scanf("%d",&b[j]);
				else
				scanf("%d",&x);
			}
		}
		int count=0;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				if(a[i]==b[j])
				{
					x=a[i];
					count++;
				}
			}
		}
		printf("Case #");
		printf("%d",k);
		printf(": ");
		if(count==1)
		printf("%d\n",x);
		else if(count==0)
		printf("Volunteer cheated!\n");
		else
		printf("Bad magician!\n");
	}
	return 0;
}
