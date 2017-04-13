// gcj.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <cstdio>
#include <cmath>
#include <stdlib.h>
using namespace std; 

int main()
{
	freopen ( "C-small-attempt2.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	int t,n;
	int c[1005];
	int nb[25];
	scanf("%d",&t);
	for(int turn=1;turn<=t;++turn)
	{
		for(int i=0;i<25;++i) nb[i] = 0;
		scanf("%d",&n);
		int sum = 0;
		int min = 999999;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&c[i]);
			if(min > c[i]) min = c[i];
			sum+=c[i];
			int tot = 0,cp = c[i];
			while(cp!=0)
			{
				nb[tot++] += cp%2;
				cp/=2;
			}
		}
		bool can = true;
		for(int i=0;i<25;++i)
		{
			if(nb[i] %2 != 0) {can = false;break;}
		}
		if(!can) printf("Case #%d: NO\n",turn);
		else  printf("Case #%d: %d\n",turn,sum-min);
	}
	return 0;
}

