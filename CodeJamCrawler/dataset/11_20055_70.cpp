// gcj.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <string.h>
using namespace std; 

int main()
{
	freopen ( "B-large.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	int t,n,c,d;
	char str[105];
	char daiti[200][200];
	bool chongtu[200][200];
	scanf("%d",&t);
	for(int turn=1;turn<=t;++turn)
	{
		memset(chongtu,false,sizeof(chongtu));
	memset(daiti,0,sizeof(daiti));
		scanf("%d",&c);
		for(int i=0;i<c;++i)
		{
			scanf("%s",str);
			daiti[str[0]][str[1]] = str[2];
			daiti[str[1]][str[0]] = str[2];
		}
		scanf("%d",&d);
		for(int i=0;i<d;++i)
		{
			scanf("%s",str);
			chongtu[str[0]][str[1]] = true;
			chongtu[str[1]][str[0]] = true;
		}
		scanf("%d",&n);
		scanf("%s",str);

		for(int i=1;i<n;++i)
		{
			if(daiti[str[i]][str[i-1]] != 0) 
			{str[i] = daiti[str[i]][str[i-1]];str[i-1] = '#';}
			for(int j=i-1;j>=0;--j)
			{
				if(chongtu[str[i]][str[j]])
				{
					for(int k =0;k<=i;++k)
						str[k] = '#';
					break;
				}
			}
		}
		printf("Case #%d: [",turn);
		bool first= true;
		for(int i=0;i<n;++i)
		{
			if(str[i] != '#')
			{
				if(first){printf("%c",str[i]);first = false;}
				else printf(", %c",str[i]);
			}
		}
		printf("]\n");
	}
	return 0;
}

