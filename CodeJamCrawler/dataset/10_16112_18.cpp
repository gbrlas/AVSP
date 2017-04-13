#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int times,n,x1,x2,y1,y2,mx,my,re;
bool use[1001][1001],use1[1001][1001];
bool end()
{
	for (int a=1;a<=mx+10;++a)
	for (int b=1;b<=my+10;++b)
	{
		if (use[a][b]) return 0;
	}
	return 1;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		scanf("%d",&n);
		memset(use,0,sizeof(use));
		for (int a=1;a<=n;++a)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for (int b=x1;b<=x2;++b)
			for (int c=y1;c<=y2;++c) 
			{
				use[b][c]=1;
				mx=max(mx,b);
				my=max(my,c);
			}
		}
		re=0;
		while (!end())
		{
			++re;
			for (int a=1;a<=mx+10;++a)
			for (int b=1;b<=my+10;++b)
			{
				if (use[a][b])
				{
					if ((((a>1)&&(!use[a-1][b]))||(a==1))&&(((b>1)&&(!use[a][b-1]))||(b==1)))
					{
						use1[a][b]=0;
					}else use1[a][b]=use[a][b];
				}else
				{
					if (((a>1)&&(use[a-1][b]))&&((b>1)&&(use[a][b-1])))
					{
						use1[a][b]=1;
						mx=max(mx,a);
						my=max(my,b);	
					}else use1[a][b]=use[a][b];
					
				}
			}
			memcpy(use,use1,sizeof(use1));
		}
		printf("Case #%d: %d\n",z,re);
	}
}
