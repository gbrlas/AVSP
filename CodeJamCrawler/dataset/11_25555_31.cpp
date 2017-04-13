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
	int tst;
	scanf("%d",&tst);
	rept(t,tst)
	{
		int L,normsp,runsp,sec,n;
		scanf("%d%d%d%d%d",&L,&normsp,&runsp,&sec,&n);
		vector<pii> pl;
		int freesp=L;
		rept(i,n)
		{
			int t0,t1,sp;
			scanf("%d%d%d",&t0,&t1,&sp);
			pl.pb(mp(sp,t1-t0));
			freesp-=pl.back().Y;
		}
		sort(all(pl));
		double time=0.;
		if (freesp>sec*runsp)
		{
			int canrun=sec*runsp;
			time=sec+(freesp-canrun+0.)/normsp;
			rept(i,sz(pl))
			{
				time+=(pl[i].Y+0.)/(normsp+pl[i].X);
			}
			printf("Case #%d: %lf\n",t+1,time);
		}
		else
		{
			double have=sec;
			time+=(freesp+0.)/runsp;
			have-=time;
			rept(i,sz(pl))
			{
				if (have>0.)
				{
					int now=runsp+pl[i].X;
					if (now*have>pl[i].Y)
					{
						time+=(pl[i].Y+0.)/now;
						have-=(pl[i].Y+0.)/now;
					}
					else
					{
						time+=have;
						time+=(pl[i].Y-have*now+0.)/(normsp+pl[i].X);
						have=0.;
					}
				}
				else
				{
					time+=(pl[i].Y-0.)/(normsp+pl[i].X);
				}
			}
			printf("Case #%d: %lf\n",t+1,time);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}