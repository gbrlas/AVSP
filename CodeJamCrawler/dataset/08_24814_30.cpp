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
	

	long long  solve() 
	{
		int P, K, L;
		VI f;
		cin >> P >> K >> L;
		REP(i, L)
		{
			int f_;
			cin >> f_;
			f.PB(f_);
		}


		LL res = 0;


		VI keys(K);
		int k_it = 0;
		sort(ALL(f));
		reverse(ALL(f));
		REP(i, f.size())
		{
			int num = ++keys[k_it];
			++k_it; k_it %= K;
			res += num*f[i];
		}


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
