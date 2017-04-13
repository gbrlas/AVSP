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

typedef  int I;

I Max(I a,I b)
{
	return a>b?a:b;
}
I Min(I a,I b)
{
	return a<b?a:b;
}

//................................
int r,c,g[109][109],rm[109],cm[109];
int main()
{
	freopen("b.in","r",stdin);
	freopen("B_Outpur.txt","w",stdout);
	I i,j,test,cas=1;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&r,&c);
		I Mx,flag=true;
		for(i=0;i<r;i++)
		{
			Mx=-99;
			for(j=0;j<c;j++)
			{
				scanf("%d",&g[i][j]);
				Mx=Max(Mx,g[i][j]);
			}
			rm[i]=Mx;
		}

		for(i=0;i<c;i++)
		{
			Mx=-99;
			for(j=0;j<r;j++)
			{
				Mx=Max(Mx,g[j][i]);
			}
			cm[i]=Mx;
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				if(g[i][j]<rm[i] && g[i][j]<cm[j] )
				{
					flag=false;
					break;
				}
			if(flag==false)break;
		}
		if(flag==true)printf("Case #%d: YES\n",cas++);
		else printf("Case #%d: NO\n",cas++);

	}


	return 0;
}