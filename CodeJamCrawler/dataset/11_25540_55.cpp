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
	vector< pii > bl_act,or_act,bl,or;
	VI dyn;
	rept(i,t)
	{
		int k;
		scanf("%d",&k);
		bl_act.clear();
		or_act.clear();
		dyn.clear();
		or.clear();
		bl.clear();
		rept(j,k)
		{
			int a; char b;
			scanf(" %c %d",&b,&a);
			if (b=='O') or_act.pb(mp(j,a));
			else bl_act.pb(mp(j,a));
		}
		or.pb(mp(1,0));
		bl.pb(or.back());
		reverse(all(bl_act));
		reverse(all(or_act));
		rept(j,k)
		{
			if (or_act.empty() || (!bl_act.empty() && bl_act.back()<or_act.back()))
			{
				if (dyn.empty()) dyn.pb(bl_act.back().Y),bl.pb(mp(bl_act.back().Y,dyn.back()));
				else dyn.pb(max(dyn.back()+1,bl.back().Y+abs(bl.back().X-bl_act.back().Y)+1)),bl.pb(mp(bl_act.back().Y,dyn.back()));
				bl_act.pop_back();
			}
			else
			{
				if (dyn.empty()) dyn.pb(or_act.back().Y),or.pb(mp(or_act.back().Y,dyn.back()));
				else dyn.pb(max(dyn.back()+1,or.back().Y+abs(or.back().X-or_act.back().Y)+1)),or.pb(mp(or_act.back().Y,dyn.back()));
				or_act.pop_back();
			}
		}
		printf("Case #%d: %d\n",i+1,dyn.back());
	}
	return 0;
}