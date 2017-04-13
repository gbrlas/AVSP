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
int M[1024];
int kst = 0;


void rec(int a, int b)
{
	bool flag = false;
	for(int i=a;i<=b;i++)
		if(M[i]!=0)
		{
			flag = true;
			break;
		}
	if(!flag)
		return;
	for(int i=a;i<=b;i++)
		if(M[i]!=0)
			M[i]--;
	kst++;
	int delta = b - a +1;
	if(delta==1)
		return;
	delta/=2;
	rec(a,a+delta-1);
	rec(b-delta+1,b);
}


int main()
{
	if(!BigTest)
	{
		freopen("B-small.in","r",stdin);
		freopen("Result-small.txt","w",stdout);
	}
	else
	{
		freopen("B-large.in","r",stdin);
		freopen("Result-large.txt","w",stdout);
	}
	int T;
	scanf("%d",&T);
	for(int testCase = 1;testCase<=T;testCase++)
	{
		int P,temp;
		kst = 0;
		scanf("%d",&P);
		for(int i=0;i<1<<P;i++)
		{
			scanf("%d",&M[i]);
			M[i] = P-M[i];
			if(M[i]<0)
				M[i] = 0;
		}
		for(int i=0;i<P;i++)
			for(int j=0;j<1<<(P-1-i);j++)
				scanf("%d",&temp);
		rec(0,(1<<P)-1);
		printf("Case #%d: %d\n",testCase,kst);
	}
	return 0;
}