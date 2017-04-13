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

const int MAXN = 110;
const int MAXM = 21010;
const int L = MAXM - 10;

int n, P, Q, hits[MAXN], score[MAXN], d[MAXN][MAXM];

int up(int a, int b) {
	int ans = a / b;
	if (a % b != 0) ans++;
	return ans;
}

int get(int pos, int have) {
	have = min(have, L);
	if (pos == n) return 0;
	int &ans = d[pos][have];
	if (ans != -1) return ans;

	ans = get(pos + 1, have + up(hits[pos], Q));
	int limit = min(have, up(hits[pos], P));
	forn(i, limit + 1) {
		int r = (hits[pos] - i*P) % (P + Q);
		if (0 < r && r <= Q) continue;

		int cur = get(pos + 1, have - i) + score[pos];
		ans = max(ans, cur);
	}

	limit = up(hits[pos], Q);
	forn(i, limit + 1) {
		if (i*Q >= hits[pos]) continue;
		int r = (hits[pos] - i*Q) % (P + Q);
		if (0 < r && r <= Q) continue;

		int cur = get(pos + 1, have + i) + score[pos];
		ans = max(ans, cur);
	}

	return ans;
}

int stupid() {
	return 0;
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
		P = nextInt();
		Q = nextInt();
        n = nextInt();
		forn(i, n) {
			hits[i] = nextInt();
			score[i] = nextInt();
		}
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        // generate test.
    }

	memset(d, 255, sizeof d);
    int ans = get(0, 1);

	cout << ans << endl;
    cerr << "\tclever answer is '" << ans << "'." << endl;
    if (false) {
        int stupidAnswer = stupid();
        cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
        assert(ans == stupidAnswer);
    }
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
  //  freopen("input.txt", "rt", stdin);
  //freopen("output.txt", "wt", stdout);
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
