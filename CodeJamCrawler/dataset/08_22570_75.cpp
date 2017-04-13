#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

__int64 A, B, P, t, t0;
int p[1000000], k, n;
int a[1000001], parent[1000001];
char flag[1000001];

void init() {
	int i, j;
	memset(flag,0,sizeof(flag));
	p[0] = 2;
	k = 1;
	for (i = 3; i < 1000000; i += 2) {
		if (!flag[i]) {
			p[k++] = i;
			for (j = i; j <= 1000000; j += i) flag[j] = 1;
		}
	}
}

int find_root(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_root(parent[x]);
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int i, j, r, testcases;
	scanf("%d", &testcases);
	init();
	for (r = 0; r < testcases; r++) {
		printf("Case #%d:", r + 1);
		scanf("%I64d%I64d%I64d",&A,&B,&P);
		if (P >= 1000000) P = 1000000;
		memset(a, 0, sizeof(a));
		n = (int)(B - A + 1);
		for (i = 0; i < n; i++) parent[i] = i;
		for (i = 0; i < k; i++) {
			j = p[i];
			if (j >= P) {
				t = A / j * j;
				if (t < A) t += j;
				t0 = t;
				while (t <= B) {
					parent[find_root(t - A)] = find_root(t0 - A);
					t += j;
				}
			}
		}
		memset(flag, 0, sizeof(flag));
		for (i = 0; i < n; i++) flag[find_root(i)] = 1;
		j = 0;
		for (i = 0; i < n; i++) {
			if (flag[i]) j++;
		}
		printf(" %d\n",j);
	}
	return 0;
}
