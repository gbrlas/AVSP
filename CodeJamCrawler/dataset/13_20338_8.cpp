// GCJ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <cstdio>
#include <iostream>
#define PI 3.14159265358

bool yuany[500];
int main()
{
	int n,T;
char input[500];
	freopen ( "A-small-attempt0.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	scanf("%d",&T);
	for(int xx=1;xx<=T;++xx)
	{
		memset(yuany,false,sizeof(yuany));
		
		scanf("%s%d",input,&n);
		int len = strlen(input);
		for(int i=0;i<len;++i)
			if(input[i] == 'a' ||
				input[i] == 'e' ||
				input[i] == 'i' ||
				input[i] == 'o' ||
				input[i] == 'u' )
				yuany[i] = true;
		int out = 0;
		int last = -1;
		for(int i=0;i<=len - n;++i)
		{
			int j;
			bool can = true;
			for(j=0;j<n;++j)
				if(yuany[i+j] == true)
				{
					can = false;break;
				}
			if(can)
			{
				int hani = i-last;
				int hanj = len+1-i-j;
				out += hani*hanj;
				last = i;
			}
		}
		printf("Case #%d: %d\n",xx, out);
	}
	return 0;
}

