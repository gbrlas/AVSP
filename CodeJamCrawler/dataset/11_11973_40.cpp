#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int cases, l, t, n, c;
int data[1000];

bool cmp(const int a, const int b) {
	return a > b;
}

int main() {
//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		scanf("%d%d%d%d", &l, &t, &n, &c);
		for(int i = 0; i < c; ++i)
			scanf("%d", &data[i]);
		for(int i = c; i < n; ++i)
			data[i] = data[i - c];
		int cnt = 0, pt;
		for(pt = 0; pt < n; ++pt)
			if(cnt + 2 * data[pt] <= t)
				cnt += 2 * data[pt];
			else break;
		if(pt < n) {
			data[pt] = (cnt + 2 * data[pt] - t) / 2;
			cnt = t;
			sort(data + pt, data + n, cmp);
			for(int i = 0; i < l && pt < n; ++i, ++pt)
				cnt += data[pt];
			for(; pt < n; ++pt)
				cnt += data[pt] * 2;
		}
		printf("Case #%d: %d\n", I, cnt);
	}
	return 0;
}
