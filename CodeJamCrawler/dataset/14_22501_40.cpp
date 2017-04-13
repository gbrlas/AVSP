#include <bits/stdc++.h>
using namespace std;
int TC, N, a[1005], o[1005];
bool cmp (int x, int y) { return a[x] < a[y]; }
int main () {
	freopen("updown.in", "r", stdin);
	freopen("updown.out", "w", stdout);
	
	scanf("%d", &TC);
	for (int T = 1; T<=TC; ++T) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &a[i]);
			o[i] = i;
		}
		sort(o+1, o+N+1, cmp);
		int s = 1, e = N, ans = 0;
		for (int i = 1; i <= N; ++i) {
			if (o[i]-s <= e-o[i]) {
				ans += o[i]-s;
				for (int k = i+1; k <= N; ++k) {
					if (o[k] < o[i]) ++o[k];
				}
				++s;
			}
			else {
				ans += e-o[i];
				for (int k = i+1; k <= N; ++k) {
					if (o[k] > o[i]) --o[k];
				}
				--e;
			}
		}
		printf("Case #%d: %d\n", T, ans);
	}
}
