#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
long long times,l,r,c,now,t;
int re;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
	//	scanf("%d%d%d",&l,&r,&c);
		cin>>l>>r>>c;
		long long now=0,t=l;
		while (t<r) 
		{
			t*=c;now++;
		}
		now--;
	//	printf("now=%d,",now);
		re=0;
		while (now)
		{
			now/=2;
			re++;
		}
		printf("Case #%d: ",z);
		printf("%d\n",re);
	}
}
