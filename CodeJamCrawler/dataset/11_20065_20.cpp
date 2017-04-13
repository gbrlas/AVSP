// gcj2.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <string.h>
using namespace std; 

int main()
{
	freopen ( "A-large.in", "r", stdin );
	freopen ( "out1.out", "w",stdout);
	bool can;
	__int64 n;
	int t,pd,pg;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		scanf("%lld%d%d",&n,&pd,&pg);
		if(n>100) n=100;
		printf("Case #%d: ",tt);
		can = false;
		if(pg == 0 && pd !=0) {printf("Broken\n");continue;}
		if(pg==100 && pd != 100){printf("Broken\n");continue;}
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				double tp = (double)j/(double)i;
				if(tp == (double)pd/100) {can = true;break;}
			}
			if(can) break;
		}
		if(!can){printf("Broken\n");continue;}
		else {printf("Possible\n");continue;}
	}
	return 0;
}