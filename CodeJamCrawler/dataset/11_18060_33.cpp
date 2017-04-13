#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int maxn = 125 + 10;

char s[maxn], st[maxn], ans[maxn];
bool flag;
int n;

void DFS(int dep, long long val) {
	if (flag) return;
	if (dep == n) {
		long long tmp = (long long)sqrt((double)val);
		if (tmp * tmp == val || (tmp + 1) * (tmp + 1) == val) {
			for (int i = 0; i < dep; ++i)
				if (s[i] == '?') ans[i] = st[i];
				else ans[i] = s[i];
			ans[dep] = 0;
			flag = 1;
		}

		return;
	}

	if (s[dep] == '?') {
		st[dep] = '0';
		DFS(dep + 1, val * 2);
		st[dep] = '1';
		DFS(dep + 1,val * 2 + 1);
	}

	if (s[dep] == '0') DFS(dep + 1, val * 2);
	else DFS(dep + 1, val * 2 + 1);
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("d.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%s", s);
		n = strlen(s);

		flag = 0;
		DFS(0, 0);
		printf("Case #%d: %s\n", nCase, ans);
	}

	return 0;
}
