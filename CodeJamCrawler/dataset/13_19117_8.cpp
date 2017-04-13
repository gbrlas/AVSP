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

char name[N];
vector<int>v1,v2;
bool visit[101][101];
bool con(char c)
{
	if(c!='a' && c!='e' && c!='i' &&c!='o' &&c!='u')return true;
	return false;
}
int main()
{
    freopen("i.in","r",stdin);
    freopen("o.txt","w",stdout);
	I i,j,k,test,cas=1,n;
	scanf("%d",&test);

	while(test--)
	{
		scanf("%s %d",&name,&n);
		memset(visit,0,sizeof visit);
		v1.clear();
		I l=strlen(name),cnt=0;
		for(i=0;i<l;i++)
		{
			if(con(name[i])==true)
			{
				cnt++;
			}
			else cnt=0;
			if(cnt>=n)
				v1.push_back(i);
		}
		I ans=0;
		for(i=0;i<v1.size();i++)
			for(j=0;j<=v1[i]-n+1;j++)
				for(k=v1[i];k<l;k++)
					if(visit[j][k]==0)
					{
						ans++;
						visit[j][k]=1;
					}

		printf("Case #%d: %d\n",cas++,ans);
	}

	return 0;
}
