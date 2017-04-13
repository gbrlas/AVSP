#include<stdio.h>
int a[1000],b[1000];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int tt=1;tt<=t;tt++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
		int r=0;
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if((a[i]-a[j])*(b[i]-b[j])<0)r++;
		printf("Case #%d: %d\n",tt,r);
	}
}
