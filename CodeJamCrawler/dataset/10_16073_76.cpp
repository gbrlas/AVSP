#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct person
{
	int x,y;
}lis[1001];
int times,n,f[1001],re;
inline bool cmp(person a1,person a2)
{
	return (a1.x<a2.x);
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		scanf("%d",&n);
		for (int a=1;a<=n;++a)
		{
			scanf("%d%d",&lis[a].x,&lis[a].y);
		}		
		sort(lis+1,lis+1+n,cmp);
		re=0;
		for (int a=1;a<=n;++a)
		{
			f[a]=1;
			for (int b=1;b<a;++b)
			{
				if (lis[a].y<lis[b].y)
				{
					re++;
				}
			}
//			re=max(re,f[a]);
		}
		printf("Case #%d: ",z);
		printf("%d\n",re);
	}
}
