#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef _WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;
const int64 MOD = 1000000007;

vector<string> g[MAXN];
string a[MAXN];
int n, m;

pair<int, int64> cmp(const pair<int, int64> &a, const pair<int, int64> &b) {
	if (a.first > b.first) return a;
	if (a.first < b.first) return b;
	return mp(a.first, (a.second + b.second) % MOD);
}

int solve(const vector<string> &a) {
	set<string> st;
	forn(i, a.size()) {
		for(int l = 0; l <= int(a[i].size()); l++) {
			st.insert(a[i].substr(0, l));
		}
	}

	return int(st.size());
}

pair<int, int64> gen(int v, int gr) {
	if (gr > m || n - v < m - gr) {
		return mp(-1, 0LL);
	}

	if (v == n) {
		assert(gr == m);
		int ans = 0;
		forn(i, m) {
			ans += solve(g[i]);
		}

		return mp(ans, 1);
	}

	pair<int, int64> ans(0, 0);
	forn(i, gr + 1) {
		g[i].pb(a[v]);
		ans = cmp(ans, gen(v + 1, max(gr, i + 1)));
		g[i].pop_back();
	}
	return ans;
}

pair<int, int64> stupid() {
	return gen(0, 0);
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = nextInt();
		m = nextInt();
		forn(i, n) {
			cin >> a[i];
		}

        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        // generate test.
    }

    pair<int, int64> ans = gen(0, 0);
	forn(i, m) {
		ans.second = (ans.second * (i + 1)) % MOD;
	}

	cout << ans.first << " " << ans.second << endl;
    cerr << "\tclever answer is '" << ans.first << " " << ans.second << "'." << endl;
    if (n <= 10) {
        pair<int, int64> stupidAnswer = stupid();
		forn(i, m) {
			stupidAnswer.second = (stupidAnswer.second * (i + 1)) % MOD;
		}
        cerr << "\tstupid answer is '" << stupidAnswer.first << " " << stupidAnswer.second << "'." << endl;
        assert(ans == stupidAnswer);
    }
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

    int minTest = 1, maxTest = INF;
    if (argc == 3) {
        minTest = atoi(argv[1]);
        maxTest = atoi(argv[2]);
    }

    cout.precision(10);
    cout.setf(ios::fixed);

    cerr.precision(10);
    cerr.setf(ios::fixed);

    srand((unsigned int)time(0));
    int tests = nextInt();
    clock_t totalStartTime = clock();
    for(int test = 1; test <= tests; test++) {
        clock_t startTime = clock();
        cerr << "Case #" << test << endl;
        bool skipThisTest = (test < minTest || test > maxTest);
        if (!skipThisTest) cout << "Case #" << test << ": ";
        solve(skipThisTest);

        char formattedTime[100];
        clock_t time = clock() - startTime;
        sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
        cerr << "time for test is " << formattedTime << " s." << endl << endl;
    }

    char formattedTime[100];
    clock_t totalTime = clock() - totalStartTime;
    sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
    cerr << string(20, '=') << endl;
    cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;

    return 0;
}
