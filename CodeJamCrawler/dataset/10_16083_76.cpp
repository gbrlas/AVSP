#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int times,l,r,c,now,re,t;

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		scanf("%d%d%d",&l,&r,&c);
		int now=0,t=l;
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
