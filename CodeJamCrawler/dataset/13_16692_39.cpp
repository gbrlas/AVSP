#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

typedef long long LL;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define MAXN 1005
#define MO 1000002013

int n, m;
int st[MAXN], ed[MAXN], num[MAXN];


struct node {
	int idx;
	LL s;
};
node f[MAXN * 2];
int tot;
map <int, LL> mat;
LL pay(int head, int tail, int nn) {
	LL ans = tail - head;
	ans = ans * (ans + 1) / 2;
	return ans * nn;
}

int main() 
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cases);
		scanf("%d%d", &n, &m);
		LL out = 0;
		mat.clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &st[i], &ed[i], &num[i]);
			mat[st[i]] = mat[st[i]] + num[i];
			mat[ed[i]] = mat[ed[i]] - num[i];
			LL tmp = pay(st[i], ed[i], num[i]);
			out -= tmp;
			out %= MO;
		}
		tot = 0;
		LL pre = 0;
		for (map<int, LL>::iterator it = mat.begin(); it != mat.end(); it++) {
			f[tot].idx = it->first;
			f[tot++].s = it->second + pre;
			pre = f[tot - 1].s;
		}

		LL ans = 0;
		LL down = 0;
		int preidx = 0;
		for (int i = 0; i < tot; ++i) {
			while (f[i].s != 0) { 
				++i;
			}
			int p = preidx, q = i;
			while (p < q) {
				if (q > p) {
					down = 0;
				} else {
					continue;
				}
				if (f[q].s < f[q - 1].s) {
					down = f[q - 1].s - f[q].s;
				}
				down = min(down, f[p].s);
				LL tmp = pay(f[p].idx, f[q].idx, down);
				out += tmp;
				out %= MO;
				f[q].s += down;
				if (f[q].s == f[q - 1].s) {
					--q;
				}
				f[p].s -= down;
				if (f[p].s == 0) {
					++p;
				}
			}
			preidx = i + 1;
		}
		printf("%lld\n", out);
	}
	return 0;
}

