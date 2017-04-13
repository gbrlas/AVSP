// gcj.cpp : 定义控制台应用程序的入口点。

//#include "stdafx.h"
#include <cstdio>
#include <cmath>
using namespace std; 

int main()
{
	freopen ( "A-small-attempt0.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	int t,n,res;
	int task[105],taskO[105],taskB[105];
	bool IsB[105];
	int to,tb;
	char tp[10];
	scanf("%d",&t);
	for(int turn=1;turn<=t;++turn)
	{
		scanf("%d",&n);
		res =to = tb= 0;
		for(int i=0;i<n;++i)
		{
			IsB[i] = false;
			scanf("%s%d",tp,&task[i]);
			if(tp[0] == 'B')
			{
				taskB[tb++] = task[i]; 
				IsB[i] = true;
			}
			else taskO[to++] = task[i];
		}

		int no=1,nb=1,tpt=0;
		for(int i=0;i<n;++i)
		{
			bool nowisB = IsB[i];
			bool change = i == 0 || IsB[i] != IsB[i-1];
			if(!change)
			{
				if(nowisB == true)
				{
					res += abs(task[i]-nb)+1;
					tpt +=abs(task[i]-nb)+1;
					nb = task[i];
				}
				else
				{
					res += abs(task[i]-no)+1;
					tpt += abs(task[i]-no)+1;
					no = task[i];
				}
			}
			else
			{
				if(nowisB == true)
				{
					int need = abs(task[i] - nb)+1;
					if(need > tpt)
					{
						res += need - tpt;
						tpt = need - tpt;
					}
					else 
					{
						res++;
						tpt = 1;
					}
					nb = task[i];
				}
				else
				{
					int need = abs(task[i] - no)+1;
					if(need > tpt)
					{
						res += need - tpt;
						tpt = need- tpt;
					}
					else
					{
						res++;
						tpt = 1;
					}
					no = task[i];
				}
			}
		}
		printf("Case #%d: %d\n",turn,res);
	}
	return 0;
}

