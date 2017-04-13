#include<stdio.h>
int main()
{
	int t,z,i,j,n,a[1000],yn,yn1,sum1,sum2,max;
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		scanf("%d",&n);
		for(i=0,yn=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			yn=yn^a[i];
		}
		if(yn)
		{
			printf("Case #%d: NO\n",z);
		}
		else
		{
			for(i=1,max=0;i<(1<<n)-1;i++)
			{
				for(j=0,yn=0,yn1=0,sum1=0,sum2=0;j<n;j++)
				{
					if((i&(1<<j))>>j)
					{
						yn=yn^a[j];
						sum1+=a[j];
					}
					else
					{
						yn1=yn1^a[j];
						sum2+=a[j];
					}
				}
				if(yn=yn1)
				{
					int temp=sum1>sum2?sum1:sum2;
					if(max<temp)
						max=temp;
				}
			}
			printf("Case #%d: %d\n",z,max);
		}
	}
	return 0;
}
