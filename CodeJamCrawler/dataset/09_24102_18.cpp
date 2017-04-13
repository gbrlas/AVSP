#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int inf = 1000000;

int n, m, a[105][30];
int cnt[105], g[105][105];
bool vis[105], used[105];
int l, b[105];
int h[105];
bool good[100000];
int ans[100005];

void dfs(int k) {
	if(k == -1) return;
	vis[k] = 1;
	int x = -1;
	for(int i = 0; i < n; i++) {
		if(! vis[i] && g[k][i] && (x == -1 || h[x] < h[i])) {
			x = i;
		}
	}
	dfs(x);
}

bool check(int x) {
	int i, j, k = 0;
	int a[20];
	for(i = 0; i < n; i++) {
		if(x & (1 << i)) {
			a[k++] = i;
		}
	}

	while(k > 0) {
		bool q = 0;
		for(i = 0; i < k; i++) {
			int cnt = 0;
			for(j = 0; j < k; j++) {
				if(i != j && g[a[i]][a[j]]) {
					cnt++;
				}
			}
			if(cnt == k-1) {
				q = 1;
				break;
			}
		}
		if(! q) {
			return false;
		}
		swap(a[i], a[k-1]);
		k--;
	}

	return true;
}

int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, k, l, t;

	scanf("%d", &t);
	for(int T = 1; T <= t; T++) {
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		memset(cnt, 0, sizeof(cnt));
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));

		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(i != j) {
					bool q = 1;
					for(k = 0; k < m; k++) {
						if(a[j][k] >= a[i][k]) {
							q = 0;
							break;
						}
					}
					if(q) {
						g[i][j] = 1;
						cnt[j] += q;
					}
				}
			}
		}

		for(i = 0; i < (1 << n); i++) {
			good[i] = check(i);
			ans[i] = inf;
		}

		ans[0] = 0;
		for(i = 1; i < (1 << n); i++) {
			for(j = i; j > 0; j = (j-1)&i) {
				if(good[j]) {
					ans[i] = min(ans[i], ans[i-j]+1);
				}
			}
		}


/*		int sol = 0;
		l = 0;
		for(int x = n; x > 0; ) {
			k = 0;
			memset(used, 0, sizeof(used));
			for(i = 0; i < n; i++) {
				if(! vis[i] && cnt[i] == 0 && ! used[i]) {
					k++;
					vis[i] = 1;
					b[l++] = i;
					h[i] = x;
					for(j = 0; j < n; j++) {
						if(! vis[j] && g[i][j] == 1) {
							cnt[j]--;
							used[j] = 1;
						}
					}
				}
			}

			sol = max(sol, k);
			x -= k;
		}

		sol = 0;
		memset(vis, 0, sizeof(vis));
		for(i = 0; i < n; i++) {
			if(! vis[b[i]]) {
				sol++;
				dfs(b[i]);
			}
		} */

		printf("Case #%d: %d\n", T, ans[(1 << n)-1]);
	}

	exit(0);
}