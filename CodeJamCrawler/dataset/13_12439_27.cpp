#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------
#define MAXN 15
#define MAXP 500
#define MIDP (MAXP/2)
#define MAXD 676070
int N;
int d[MAXN];
int n[MAXN];
int e[MAXN];
int w[MAXN];
int s[MAXN];
int dp[MAXN];
int dd[MAXN];
int ds[MAXN];

int wall[MAXP];

struct S{
	int d, w, e, s;
	bool operator < (const S &in)const{
		return in.d < d;
	}
};
struct W{
	int w, e, s;
};
vector<S> a;

int main() {

	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		a.clear();

		seta(wall, 0);

		scanf("%d", &N);
		forn(i, N){
			scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);

			forn(j, n[i]){
				S st;
				st.d = (d[i] + (j) * dd[i]);
				st.w = (w[i] + (j) * dp[i]) + MIDP;
				st.e = (e[i] + (j) * dp[i]) + MIDP;
				st.s = (s[i] + (j) * ds[i]);
				a.pb(st);

				//printf("%d: [%d %d] => %d\n", i, w[i] + (j) * dp[i], e[i] + (j) * dp[i], s[i] + (j) * ds[i]);
			}
		}

		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());

		int ans = 0;
		int lastday = -1;
		vector<W> wtmp;
		wtmp.clear();
		forn(i, (int)a.size()){
			if(lastday == -1){
				lastday = a[i].d;
			}

			if( lastday != a[i].d ){
				lastday = a[i].d;
				for(int j = 0; j < (int)wtmp.size(); j++){
					for(int k = wtmp[j].w; k <= wtmp[j].e; k++){
						wall[k] = max(wall[k], wtmp[j].s);
					}
				}
				wtmp.clear();
			}

			bool isOK = false;

			W ww;
			ww.w = a[i].w;
			ww.e = a[i].e - 1;
			ww.s = a[i].s;
			wtmp.pb(ww);

			for(int j = a[i].w; j <= a[i].e - 1; j++){
				if(wall[j] < a[i].s){
					//printf("ATT!!!! %d %d %d\n", i, wall[j], a[i].s);
					isOK = true;
				}
			}
			if(isOK) ans++;

			//printf("%d: (d %d )[%d %d] => %d\n", i, a[i].d, a[i].w-MIDP, a[i].e-MIDP, a[i].s);
		}

		//printf("%d\n", (int)wtmp.size());


		printf("Case #%d: %d\n", casenum++, ans);
		fflush(stdout);
	}
	return 0;
}
