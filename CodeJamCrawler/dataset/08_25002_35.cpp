#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define CLEAR(a,v) memset((a), (v), sizeof(x))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
const double eps = 1e-9;
const int INF = 1000000000;
const LL LLINF = (LL)INF * INF;
const double PI = 2 * acos(.0);
const int MOD = 10007;

int mp[128][128];
int fb[128][128];
const int dir[][2] = {{1,2},{2,1}};

int main() {
	freopen("D-small.in","r",stdin);
	freopen("D-small.out","w",stdout);
	int T, ca = 0;
	int t1, t2, H, W, n, i, j, ti, tj, d;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&H,&W,&n);
		memset(mp, 0, sizeof(mp));
		memset(fb, 0, sizeof(fb));
		while (n--) {
			scanf("%d%d",&t1,&t2);
			fb[t1][t2] = 1;
		}
		mp[1][1] = 1;
		for (i = 1 ; i <= H ; i++)
			for (j = 1 ; j <= W ; j++)
				for (d = 0 ; d < 2 ; d++) {
					ti = i + dir[d][0];
					tj = j + dir[d][1];
					if (ti > H || tj > W || fb[ti][tj]) continue;
					mp[ti][tj] += mp[i][j];
					mp[ti][tj] %= MOD;
				}
		printf("Case #%d: %d\n",++ca,mp[H][W]);
	}
	return 0;
}
