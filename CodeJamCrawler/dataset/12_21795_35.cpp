#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

#ifdef ILIKEGENTOO
#define Eo(x) { cerr << #x << " = " << (x) << endl; }
#define E(x) { cerr << #x << " = " << (x) << "   "; }
#else
#define Eo(x)
#define E(x)
#endif
#if defined ILIKEGENTOO || !(defined __GNUC__ ) || (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 6))
template<typename T, size_t N> struct array { T val[N]; T& operator[](size_t n) { if(n >= N) assert(false); return val[n]; } T* begin() { return &val[0]; } T* end() { return &val[0]+N; } };
#else
#include <array>
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

typedef double real;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const real eps = 1e-8;

const int maxn = 10050;
int vs[maxn][2];
int dp[maxn];

int main() {
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	for(int _=1; _<=T; _++) {
		int n; cin >> n;
		for(int i=0; i<n; i++) cin >> vs[i][0] >> vs[i][1];
		int d; cin >> d;

		memset(dp, 0xc0, sizeof(dp));
		dp[0] = vs[0][0];

		bool ok = false;
		for(int i = 0; i < n; i++) if(dp[i] >= 0) {
			int dist = vs[i][0] + dp[i];
			E(i); Eo(dist);
			if(dist >= d) {
				ok = true;
				break;
			}
			for(int j = i + 1; j < n && vs[j][0] <= dist; j++) {
				int nlen = min(vs[j][0] - vs[i][0], vs[j][1]);
				dp[j] = max(dp[j], nlen);
			}
		}

		cout << "Case #" << _ << ": " << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}
