
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

int a[2000];
int main(){

	int t;
	scanf("%d",&t);
	FOR(test,1,t+1)
	{
		int n,s,p,ans=0;
		scanf("%d%d%d",&n,&s,&p);
		REP(i,n)
			scanf("%d",&a[i]);
		REP(i,n)
		{
			a[i]-=p;
			if(a[i]<0)
				continue;
			if(a[i]/2>=p-2)
			{
				if(a[i]/2==p-2)
				{
					if(s>0)
					{
						s--;
						ans++;
					}
					continue;
				}
				else
					ans++;
			}

		}
		printf("Case #%d: %d\n",test,ans);


	}
	return 0;
}
