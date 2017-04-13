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
	vector<int> pr;
	pr.pb(2);
	for (int i=3; i<1010; i++)
	{
		bool p=true;
		rept(j,sz(pr))
		{
			if ((i%pr[j])==0) p=false;
		}
		if (p) pr.pb(i);
	}
	int tst;
	scanf("%d",&tst);
	rept(t,tst)
	{
		int n;
		scanf("%d",&n);
		int mi,ma;
		mi=lower_bound(all(pr),n)-pr.begin();
		ma=mi+1;
		if (mi==0) mi++;
		VI ps(pr.begin(),pr.begin()+mi);
		int to=mi;
		for (int st=2;;st++)
		{
			for (int j=0; j<to; j++)
			{
				if (pow(pr[j]+0.,st+0.)<=(double)n) ma++;
				else {to=j;break;}
			}
			if (to==0) break;
		}
		printf("Case #%d: %d\n",t+1,ma-mi);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}