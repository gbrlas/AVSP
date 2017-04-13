#include<stdio.h>
#include<stdlib.h>
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("hi.txt","w",stdout);
	int t,n;
	int x[1000],y[1000];
	int i,j,k,a=1;
	scanf("%d",&t);
	while(a<=t)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
		}
		for(i=0;i<n;i++)
			scanf("%d",&y[i]);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(x[i]>x[j])
				{
					k=x[i];x[i]=x[j];x[j]=k;
				}
				if(y[i]<y[j])
				{
					k=y[i];y[i]=y[j];y[j]=k;
				}
			}
		}
		int s=0;
		for(i=0;i<n;i++)
		{
			s+=x[i]*y[i];
		}
		printf("Case #%d: %d\n",a,s);
		a++;
	}
}