#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <ext/hash_set>
#include <string>

using namespace std;
using namespace __gnu_cxx;

hash_set<int> a[2];
int R;

int main() {
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);  freopen("C-small-attempt0.out","w",stdout);
	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		a[0].clear();
		a[1].clear();
		int ans = 0;
		scanf("%d", &R);
		for (int i = 0; i < R; ++i) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			for (int x = x1; x <= x2; ++x)
				for (int y = y1; y <= y2; ++y)
					a[0].insert((x << 16) | y);
		}
		int cur = 0, next = 1;
		for (ans = 1; ; ++ans) {
			a[next].clear();
			for (int i = 1; i <= 100; ++i)
				for (int j = 1; j <= 100; ++j) {
					int key = (i << 16) | j;
					int nkey = (i << 16) | (j - 1);
					int wkey = ((i - 1) << 16) | j;
					bool n = a[cur].find(nkey) != a[cur].end();
					bool w = a[cur].find(wkey) != a[cur].end(); 
					if (n && w || ((n || w) && a[cur].find(key) != a[cur].end()))
						a[next].insert(key);
				}
			if (a[next].size() == 0)
				break;
			swap(cur, next);
		}
		printf("Case #%d: %d\n", t, ans);
		cerr << "Case #" << t << ": "  << ans << endl;
	}
	return 0;
}


