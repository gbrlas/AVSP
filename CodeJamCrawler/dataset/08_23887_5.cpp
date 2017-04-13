#include <stdio.h>

long long tree[200000][2] = {0};
double center[2] = {0};

int validCenter(long long, long long, long long, long long, long long, long long);

int main() {
	int N, n;
	long long A, B, C, D, M;
	long long x, y;
	
	scanf("%d", &N);
	
	for (int q = 1; q <= N; q++) {
		int ans = 0;
		
		scanf("%d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", &n, &A, &B, &C, &D, &x, &y, &M);
		tree[0][0] = x;
		tree[0][1] = y;
		for (int i = 1; i < n; i++) {
			x = (A * x + B) % M;
			y = (C * y + D) % M;
			tree[i][0] = x;
			tree[i][1] = y;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (validCenter(tree[i][0], tree[i][1], tree[j][0], tree[j][1], tree[k][0], tree[k][1]))
						ans++;
				}
			}
		}

		
		
		printf("Case #%d: %d\n", q, ans);
	}
	return 0;
}

int validCenter(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	
	if (x1 == x2 && y1 == y2) return 0;
	if (x1 == x3 && y1 == y3) return 0;
	if (x2 == x3 && y2 == y3) return 0;

	center[0] = (x1 + x2 + x3) / 3.0;
	center[1] = (y1 + y2 + y3) / 3.0;
	
	if (center[0] == (double)((long long)center[0]) && center[1] == (double)((long long)center[1])) {	
		return 1;
	}
	else return 0;
}

