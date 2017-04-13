/*
 * GCC version:			4.6
 * Command line:		g++ -std=c++0x -m64 -02 -fno-strict-aliasing -Wl,--stack=268435456 Solution.cpp
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for(int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define CL(a, b)		memset(a, b, sizeof a)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define parallelize if (hocus pokus = true)

template <class hocus = bool> struct Solver {
	
    __int128_t cost(ll d, ll p)
    {
        return (d * (d - 1) / 2) * (__int128_t)p;
    }
    
    void run() {
        int n, m;
		cin >> n >> m;
        __int128_t res = 0;
        vector<int> o(m), e(m), p(m), xs;
        REP (i, m) 
        {
            cin >> o[i] >> e[i] >> p[i];
            res -= cost(e[i] - o[i], p[i]);
            xs.push_back(o[i]);
            xs.push_back(e[i]);
        }
        parallelize
        {
            sort(all(xs));
            xs.push_back(-1u/2);
            xs.erase(unique(all(xs)), xs.end());
            vector<pair<int, ll>> h(1, make_pair(0, -1));
            FOR (i, 1, sz(xs))
            {
                ll cnt = 0;
                REP (j, m)
                {
                    if (o[j] <= xs[i - 1] && xs[i] <= e[j])
                        cnt += p[j];
                }
                int d = xs[i] - xs[i - 1];
                for (; sz(h); )
                {
                    auto hb = h.back();
                    if (hb.second < cnt) break;
                    h.pop_back();
                    ll y = max(h.back().second, cnt);
                    res += cost(hb.first, hb.second - y);
                    (y == h.back().second ? h.back().first : d) += hb.first;
                }
                h.emplace_back(d, cnt);
            }
        }
        cout << (int)(res % 1000002013) << endl;
	}
};

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	cout.precision(12);	
	cout.setf(ios::fixed);
	int i = 0, n;
	for (cin >> n; i < n; ) {
		printf("Case #%d: ", ++i);
		Solver<> *s = new Solver<>;
		s->run();
		delete s;
	}
	return 0;
}
