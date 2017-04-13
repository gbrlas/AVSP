// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>

int hash[1001];

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T,N,ret;
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		scanf("%d",&N);
		ret=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&hash[i]);
			ret=ret^hash[i];
		}
		if(ret!=0) {
			printf("Case #%d: NO\n",j);
			continue;
		}
		int sum=0;
		int min=hash[0];
		for(int i=0;i<N;i++)
		{
			sum+=hash[i];
			if(min>hash[i])
				min=hash[i];
		}
		printf("Case #%d: %d\n",j,sum-min);
	}
	return 0;
}

