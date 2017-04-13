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
const int MAXN = 2005, START = 100000000;
int next[MAXN], pos[MAXN];
inline bool work(int l, int r, int end, int k) {
	//DEB("l:%d r:%d end:%d k:%d\n", l, r, end, k);
	int cur = l;
	while (next[cur] <= r) {
		if (next[cur] <= cur) return false;
		pos[cur] = end - (r - cur) * k;
		cur = next[cur];
	}
	for (int i = l;i < r;i++) if (next[i] > r) return false;
	//if (cur > r) return false;
	cur = l;
	while (next[cur] <= r) {
		if (next[cur] > cur + 1) {
			if (!work(cur + 1, next[cur], pos[next[cur]], k + 1)) return false;
		}
		cur = next[cur];
	}
	return true;
}
int main() {
	int testnum, n;
	INP("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		INP("%d", &n);
		for (int i = 0;i + 1 < n;i++) {
			INP("%d", &next[i]);
			next[i]--;
		}
		next[n - 1] = n;
		pos[n - 1] = pos[n] = START;
		bool suc = work(0, n - 1, START, 0);
		printf("Case #%d:", test);
		if (!suc) {
			puts(" Impossible");
		} else {
			REP(i, n) printf(" %d", pos[i]);
			puts("");
		}
	}
	return 0;
}