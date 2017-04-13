#include<stdio.h>
int main()
{
	int re;
	int n;
	int a[1001],t,k,i;
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&re);
	k=1;
	while(re--)
	{	
		int min,sum;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		min=a[0];
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			if(a[i]<min)min=a[i];
		}
		t=a[0];
		for(i=1;i<n;i++)
		{
			t=t^a[i];
		}
		printf("Case #%d: ",k++);
		if(t==0)
			printf("%d\n",sum-min);
		else
			printf("NO\n");
	}
	return 0;
}