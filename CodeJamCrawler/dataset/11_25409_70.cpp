#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,num;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		int minnum=0x3f3f3f3f,sum=0,p=0;
		for(int j=0;j!=n;j++)
		{
			scanf("%d",&num);
			sum+=num;
			p^=num;
			if(minnum>num) minnum=num;
		}
		printf("Case #%d: ",i);
		if(p) puts("NO");
		else printf("%d\n",sum-minnum);
	}
}