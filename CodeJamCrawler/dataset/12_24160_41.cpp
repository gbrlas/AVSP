#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <functional>
#include <utility>
using namespace std;
#define INP(s...) scanf(s)
#define OUP(s...) printf(s)
#define DEB(s...) fprintf(stderr,s)
#define PB push_back
#define MP make_pair
#define SZ(x) (int((x).size()))
#define REP(i,n,s...) for(int(i)=s+0;(i)<(int)(n);++(i))
#define EACH(i,s) for(typeof(s.begin())i=s.begin();i!=s.end();i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
const int MAXN = 10005;
int d[MAXN], l[MAXN], far[MAXN];
int main() {
	int testnum, D, n;
	INP("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		INP("%d", &n);
		REP(i, n) {
			INP("%d%d", &d[i], &l[i]);
		}
		INP("%d", &D);
		/*REP(i, n)
			if (l[i] >= d[i]) {
				far[i] = d[i] + d[i];
			} else {
				far[i] = -1;
			}*/
		memset(far, -1, sizeof(far));
		far[0] = d[0] + d[0];
		REP(i, n) if (far[i] >= 0) {
			for (int j = i + 1;j < n;j++) if (far[i] >= d[j]) {
				int t = min(d[j] - d[i], l[j]);
				far[j] = max(far[j], d[j] + t);
			}
		}
		bool suc = false;
		REP(i, n) if (far[i] >= D) {
			suc = true; break;
		}
		//REP(i, n) OUP("%d ", far[i]); puts("");
		printf("Case #%d: ", test);
		if (suc) puts("YES"); else puts("NO");
	}
	return 0;
}