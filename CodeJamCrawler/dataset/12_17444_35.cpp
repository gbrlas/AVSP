#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10101;
int d[maxn], c[maxn], l[maxn];
int main() {
	freopen("output.txt", "w", stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas) {
		int n; scanf("%d", &n);
//		printf("n=%d\n", n);
		++n;
		memset(c, -1, sizeof c);
		for (int i = 1; i < n; ++i) scanf("%d%d", d + i, l + i);
		scanf("%d", d + n); l[n] = 0;
		int r = 2; 
		c[1] = d[1];
		for (int i = 1; i < n; ++i) {
			if (c[i] == -1) break;
			while (r <= n && c[i] >= d[r] - d[i]) {
				c[r] = min(d[r] - d[i], l[r]);
				++r;
			}
		}
		printf("Case #%d: ", cas);
		if (c[n] >= 0) puts("YES");
			else puts("NO");
	}
	return 0;
}
