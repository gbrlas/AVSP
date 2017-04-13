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

LL GCD(LL a, LL b)
{
	return (b?GCD(b,a%b):a);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	rept(tst,t)
	{
		LL n,pd,pg;
		scanf("%lld%lld%lld",&n,&pd,&pg);
		LL gcd1=GCD(pd,100LL);
		if ((pg==100 && pd==100) || (pd==0 && pg==0))
		{
			printf("Case #%d: Possible\n",tst+1);
			continue;
		}
		if (pg==100 || pg==0)
		{
			printf("Case #%d: Broken\n",tst+1);
			continue;
		}
		if (100LL/gcd1<=n)
		{
			printf("Case #%d: Possible\n",tst+1);
			continue;
		}
		printf("Case #%d: Broken\n",tst+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}