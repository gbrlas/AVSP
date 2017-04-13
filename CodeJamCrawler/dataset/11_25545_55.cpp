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

string res;
string base="QWERASDF";
map<char,int> cd;
map<int,char> val;
int transf[8][8];
vector< VI > g(8);

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	rept(i,t)
	{
		int k;
		scanf("%d",&k);
		char c[3],temp;
		memset(transf,0,sizeof(transf));
		g.clear();
		g.resize(8);
		cd.clear();
		val.clear();
		rept(e,8) cd[base[e]]=e;
		rept(e,8) val[e]=base[e];
		rept(j,k)
		{
			temp=getchar();
			rept(q,3) c[q]=getchar();
			if (cd.find(c[2])==cd.end()) cd[c[2]]=sz(cd),val[sz(cd)-1]=c[2];
			transf[cd[c[0]]][cd[c[1]]]=cd[c[2]];
			transf[cd[c[1]]][cd[c[0]]]=cd[c[2]];
		}
		scanf("%d",&k);
		rept(j,k)
		{
			temp=getchar();
			rept(q,2) c[q]=getchar();
			g[cd[c[0]]].pb(cd[c[1]]);
			g[cd[c[1]]].pb(cd[c[0]]);
		}
		scanf("%d ",&k);
		string s;
		getline(cin,s);
		string res;
		rept(j,(int)s.length())
		{
			if (res.empty()) res.pb(s[j]);
			else
			{
				int t0=cd[res.back()];
				int t1=cd[s[j]];
				if (t1>7) res.pb(s[j]); else
				if (t0<8 && transf[t0][t1]) res.pop_back(),res.pb(val[transf[t0][t1]]);
				else
				{
					rept(q,sz(g[t1]))
					{
						int dng=val[g[t1][q]];
						if (res.find(dng)!=string::npos) res.clear();
					}
					if (!res.empty()) res.pb(s[j]);
				}
			}
		}
		printf("Case #%d: [",i+1);
		rept(j,(int)res.length()-1) printf("%c, ",res[j]);
		if (!res.empty()) printf("%c]\n",res.back());
		else printf("]\n");
	}
	return 0;
}