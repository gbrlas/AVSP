#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

set< pair<int, int> > app;
int c[10];
int A, B;

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);


	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d", &A, &B);

		app.clear();
		long long ans = 0;
		for (int i = A + 1; i <= B; ++i) {
			int y = 1, cnt = 0;
			for (int x = i; x; x /= 10) {
				y *= 10;
				c[cnt++] = x % 10;
			}

			int x = 1, z = 0;
			while (x * 10 <= i) {
				x *= 10;
				y /= 10;
				if (c[z] != 0) {
					int l = i / x, r = i % x;
					if (r * y + l >= A && r * y + l < i && app.find(make_pair(r * y + l, i)) == app.end()) {
						++ans;
						app.insert(make_pair(r * y + l, i));
					}
				}
				++z;
			}
		}

		printf("Case #%d: %I64d\n", nCase, ans);
	}

	return 0;
}
