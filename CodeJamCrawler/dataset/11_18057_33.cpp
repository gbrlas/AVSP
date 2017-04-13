#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;
const int maxr = 10000 + 10;

int a[maxn], len[maxn], head[maxn], tail[maxn];
bool used[maxn];
int num[maxr], tot[maxr];
int n;

bool check(int ans) {
	int cnt = 0;
	memcpy(num, tot, sizeof(tot));
	for (int i = 0; i < maxr; ++i)
		while (num[i]) {
			len[cnt] = 0;
			head[cnt] = i;
			int j = i;
			while (len[cnt] < ans && j < maxr && num[j]) {
				tail[cnt] = j;
				++len[cnt];
				--num[j];
				++j;
			}
			++cnt;
		}
	memset(used, 0, sizeof(used));
	for (int i = 0; i < cnt; ++i)
		if (!used[i] && len[i] < ans) {
			for (int j = 0; j < i; ++j)
				if (!used[j] && tail[j] + 1 == head[i]) {
					tail[j] = tail[i];
					len[j] += len[i];
					used[i] = 1;
					break;
				}
		}
	for (int i = 0; i < cnt; ++i)
		if (!used[i] && len[i] < ans) return 0;
	return 1;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		memset(tot, 0, sizeof(tot));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			++tot[a[i]];
		}

		int ans = n;
		while (ans > 1 && !check(ans)) --ans;

		printf("Case #%d: %d\n", nCase, ans);
	}

	return 0;
}
