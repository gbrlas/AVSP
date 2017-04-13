#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second

#define INF 1000000000

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int l,d,n;
	cin >> l >> d >> n;
	
	set<string> s;
	string tmp;

	REP(i,d)
	{
		cin >> tmp;
		s.insert(tmp);		
	}

	REP(i,n)
	{
		int ans=0;
		vector<long> pattern;
		string p;

		cin >> p;
		int pp=0;
		REP(j,l)
		{
			long q=0;
			if(p[pp]=='(')
			{
				pp++;
				while(p[pp]!=')')
				{
					q|=1<<(p[pp]-'a');
					pp++;
				}
			}
			else
				q=1<<(p[pp]-'a');
			pattern.pb(q);
			pp++;
		}
		
		set<string>::iterator it;
		for(it = s.begin(); it!=s.end(); it++)
		{
			int k=0;
			while((k<l)&&((1<<((*it)[k]-'a'))&pattern[k]))
				k++;
			if(k==l)
				ans++;
		}

		cout << "Case #" << i+1 << ": " << ans << endl;
	}
	return 0;
}