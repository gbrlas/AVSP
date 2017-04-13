#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	double a[1002],b[1002];
	int n,i;
	int j;
	scanf("%d",&t);
	int l=1;
	while(t--)
	{
		int m1[1002]={0},m2[1002]={0};
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		for(i=0;i<n;i++)
			scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		j=-1;
		for(i=0;i<n;i++)
		{
			for(j=j+1;j<n;j++)
			{
				if((m1[j]==0) && (b[j]>a[i]))
				{
					m1[j]=1;
					break;
				}
			}
			if(j==n)
			break;
		}
		int y=0,z=0;
		for(i=0;i<n;i++)
		if(m1[i]==0)
		z++;
		j=0;
		for(i=0;i<n;i++)
		{
			for(j;j<n;j++)
			{
				if(b[j]>a[i])
				break;
				if((a[i]>b[j])&&(m2[j]==0))
				{
					m2[j]=1;
					break;
				}
					
			}
			if(j==n)
			break;
		}
		for(i=0;i<n;i++)
		if(m2[i]==1)
		y++;
		printf("Case #%d: %d %d\n",l++,y,z);
	}
	return 0;
}
