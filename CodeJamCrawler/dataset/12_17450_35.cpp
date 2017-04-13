#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int W, L;
struct circle{
	int x, y;
	int num, R;
	bool done;
} a[maxn];

int n, k, finish;

void work(int W, int L, int x0, int y0, bool first = false) {
	if (k > n) return;
	int ym = 0, l = -a[k].R;
	bool done = false;
	if (first) {
		while (k <= n && a[k].R + l <= W) {
			a[k].x = l + x0 + a[k].R;
			a[k].y = y0;
			ym = max(ym, a[k].R);
			l += a[k].R * 2;
			++k;
			done = true;
		}
	} else {
		while (k <= n && a[k].R + l <= W) {
			a[k].x = l + x0 + a[k].R;
			a[k].y = y0 + a[k].R;
			ym = max(ym , a[k].R * 2);
			l += a[k].R * 2;
			++k;
			done = true;
		}
	}
	if (done)
	work(W, L - ym, x0, ym + y0);
}

int ansx[maxn], ansy[maxn];
bool cmp(const circle &a, const circle &b) {
	return a.R > b.R;
}

int main() {
	freopen("BOUT.txt", "w", stdout);
	int task; scanf("%d", &task);
	for (int cas = 1; cas <= task; ++cas) {
		scanf("%d", &n); finish = 0;
		scanf("%d%d", &W, &L);
		k = 1;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i].R);
			a[i].num = i;
			a[i].done=  false;
		}
		sort(a + 1, a + 1 + n, cmp);
		work(W, L, 0, 0, true);
		printf("Case #%d:", cas);
//		printf("%d\n", k);
		if (k > n) {
			for (int i = 1; i <= n; ++i){ 
				ansx[a[i].num] = a[i].x;
				ansy[a[i].num] = a[i].y;
			}
			for (int i = 1; i <= n; ++i) 
				printf(" %d.0 %d.0", ansx[i], ansy[i]);
			puts("");
		}
	}
	for (int i = 1; i <= n; ++i) 	if (a[i].x > W || a[i].y > L) {	puts("BAD"); break;}
	return 0;
}

