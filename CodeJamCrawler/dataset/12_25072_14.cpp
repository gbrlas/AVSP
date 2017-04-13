#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:260108864")

#include <iostream>
#include <ctime>
#include <cstdio>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>
#include <iterator>
#include <bitset>
#include <sstream>
#include <numeric>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); ++i)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 1000000000
#define PI 3.141592653589
#define eps 0.000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

vector< pii > d;
VI dyn;

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	int t;
	scanf("%d",&t);
	rept(tst,t)
	{
		printf("Case #%d: ",tst+1);
		int n;
		scanf("%d",&n);
		d.clear();
		d.resize(n);
		int dest;
		rept(i,n) scanf("%d%d",&d[i].X,&d[i].Y);
		scanf("%d",&dest);
		dyn.assign(n,-INF);
		dyn[0]=d[0].X;
		bool can(false);
		rept(i,n)
		{
			if (dyn[i]==-INF) continue;
			int maxDist(d[i].X+dyn[i]);
			if (maxDist>=dest) {can=true; break; }
			for (int j=i+1; j<n && d[j].X<=maxDist; ++j)
				dyn[j]=max(dyn[j],min(d[j].Y,d[j].X-d[i].X));
		}
		if (can) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}