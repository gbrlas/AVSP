#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

const bool BigTest = 0;

bool Matr[100][100];
bool Matr2[100][100];


int main()
{
	if(!BigTest)
	{
		freopen("C-small.in","r",stdin);
		freopen("Result-small.txt","w",stdout);
	}
	else
	{
		freopen("C-large.in","r",stdin);
		freopen("Result-large.txt","w",stdout);
	}
	int T;
	scanf("%d",&T);
	for(int testCase = 1;testCase<=T;testCase++)
	{
		memset(Matr,0,sizeof(Matr));
		int R;
		scanf("%d",&R);
		for(int i=0;i<R;i++)
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(int j=x1-1;j<x2;j++)
				for(int k=y1-1;k<y2;k++)
					Matr[j][k] = true;
		}
		int kst = 0;
		while(true)
		{
			bool flag = false;
			for(int i=1;i<100;i++)
				for(int j=1;j<100;j++)
				{
					Matr2[i][j] = Matr[i][j];
					if(Matr[i][j]&&!(Matr[i-1][j]||Matr[i][j-1]))
						Matr2[i][j] = 0;
					else if(!Matr[i][j]&&(Matr[i-1][j]&&Matr[i][j-1]))
						Matr2[i][j] = 1;
					if(Matr2[i][j])
						flag = true;
				}
			kst++;
			if(!flag)
				break;
			for(int i=0;i<100;i++)
				for(int j=0;j<100;j++)
					Matr[i][j] = Matr2[i][j];
		}
		printf("Case #%d: %d\n",testCase,kst);
	}
	return 0;
}