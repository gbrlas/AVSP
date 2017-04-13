#include <cstdio>
int main() {
	int n, s, p, task;
	freopen("B-large.in","r", stdin);
	freopen("ans_for_B-large.txt", "w", stdout);
	scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas) {
		scanf("%d%d%d", &n, &s, &p);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int t; scanf("%d", &t);
			int k = t / 3;
			if (3 * k == t){ 
				if (k >= p) ++ ans; else
				if (s > 0 && t > 0 && k + 1 >= p) 
					++ans, --s;
			} else
			if (3 * k + 1 == t) {
				if (k + 1 >= p) ++ans;
			} else  {
				if (k + 1 >= p) ++ans;
				else if (s > 0 && k + 2 >= p) ++ans, --s;
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
