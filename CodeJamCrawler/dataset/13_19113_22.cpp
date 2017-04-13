//////////////////////////////////////////
//   Bismillahir Rahmanir Rahim        //
//   Author      : Shohan Ahmed Sijan //
//   Country     : Bangladesh        //
//   Algorithm   : 
//   Complexity  : %
//   University  : East West University //
/////////////////////////////////////////
#pragma warning(disable:4786)
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define Re(i,n) for(i=0;i<n;i++)
#define inf 999999999
#define PI acos(-1)
#define EPS 1e-12
#define sqrt(x) sqrt(abs(x))
#define P pair<int,int>
#define N 1000009

typedef  __int64 I;

I Max(I a,I b)
{
	return a>b?a:b;
}
I Min(I a,I b)
{
	return a<b?a:b;
}

//................................
I num[1000],n;
I f(I st,I m,I c)
{
	I t;
	if(st==n)
	{
		return c;
	}
	if(num[st]<m)
	{
		
		t=f(st+1,m+num[st],0);

		return Min(n-st,c+t);
	}
	else
	{
		t=f(st,m+m-1,1);
		return Min(n-st,c+t );
	}
}
int main()
{
	freopen("A-small-attempt5.in","r",stdin);	freopen("aout.txt","w",stdout);
	I i,j,test,cas=1,m;
	scanf("%I64d",&test);
	while(test--)
	{
		scanf("%I64d %I64d",&m,&n);
		for(i=0;i<n;i++)
			scanf("%I64d",&num[i]);
		sort(num,num+n);
		if(m==1)
		{
			printf("Case #%I64d: %I64d\n",cas++,n);
			continue;
		}
		printf("Case #%I64d: %I64d\n",cas++,f(0,m,0));
	}

	return 0;
}