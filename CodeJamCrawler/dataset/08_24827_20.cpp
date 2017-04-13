#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <sstream>

using namespace std;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)

typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI; 

#define PB push_back
#define MP make_pair

struct Task 
{
	LL solve()
	{
		int k; cin >> k;
		string s; cin >> s;
		
		VI perm(k);
		REP(i, k) perm[i] = i;

		LL res = 1000000000;
		do
		{

			string str(s);

			int S = str.size();
			int d = 0;
			REP(j, (S/k))
			{
				REP(i, k)
				{
					str[i+d] = s[d+perm[i]];
				}
				d+=k;
			}

			int r = 1;
			REP(j, S-1)
			{
				if (str[j] !=str[j+1])
					r++;
			}

			res = min<LL>(res, r);


		}
		while(next_permutation(ALL(perm)));

		return res;
	}


};

	int main() 
	{
		freopen("in", "rt", stdin);
		freopen("out", "w", stdout);

		int tc; cin >> tc;
		REP(TC, tc) 
		{
			Task t;
			LL r = t.solve();
			cout << "Case #" << TC+1 << ": " << r << "\n";
			cerr << "Case #" << TC+1 << ": " << r << "\n";

		}

		fclose(stdout);
	}
