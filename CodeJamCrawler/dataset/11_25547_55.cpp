#include <iostream>
#include <cstdio>
#include <utility>
#include <memory>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); i++)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,a-1)
#define INF 999999999

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	rept(num,t)
	{
		int n;
		int ans=-INF;
		scanf("%d",&n);
		VI d(n);
		rept(i,n) scanf("%d",&d[i]);
		int to=1<<n;
		rept(j,to)
		{
			if (j==to-1 || j==0) continue;
			int res1,res2,sum;
			res1=res2=sum=0;
			rept(q,n) if (j&(1<<q)) res1^=d[q],sum+=d[q];
			else res2^=d[q];
			if (res1==res2) ans=max(ans,sum);
		}
		if (ans==-INF) printf("Case #%d: NO\n",num+1);
		else printf("Case #%d: %d\n",num+1,ans);
	}
	return 0;
}