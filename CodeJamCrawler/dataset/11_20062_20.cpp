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
	freopen ( "A-small-attempt0.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	bool can;
	int t,n,pd,pg;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		scanf("%d%d%d",&n,&pd,&pg);
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