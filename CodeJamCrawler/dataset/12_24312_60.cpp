/*By Zine.Chant*/
#include<algorithm>
#include<iostream>
#include<iterator>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int v,n,m,k,s,t,x;
int main()
{
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	scanf("%d\n",&v);
	for (int u=1;u<=v;u++)
	{
		scanf("%d %d %d",&n,&m,&k);
		s=0;t=0;
		for (int i=1;i<=n;i++)
		{
			scanf(" %d",&x);
			if (x>=3*k-2&&x>=k) s++;
			else if (x>=3*k-4&&x>=k) t++;
		}
		scanf("\n");
		printf("Case #%d: %d\n",u,s+min(t,m));
	}
	return 0;
}
