#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define SIZE 6020
#define OFF 3010

#define LOTS 100000

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

#define LEFT(x) (((x)+3)%4)
#define RIGHT(x) (((x)+1)%4)

int top[SIZE], bottom[SIZE];
int left[SIZE], right[SIZE];

void update_ver(int x, int y) {
	left[OFF+y] = min(left[OFF+y], x);
	right[OFF+y] = max(right[OFF+y], x);
}
void update_hor(int x, int y) {
	top[OFF+x] = max(top[OFF+x], y);
	bottom[OFF+x] = min(bottom[OFF+x], y);
}

int solve() {
	fill(top, top+SIZE, -LOTS);
	fill(bottom, bottom+SIZE, LOTS);
	fill(left, left+SIZE, LOTS);
	fill(right, right+SIZE, -LOTS);
	int L, T;
	char S[35];
	scanf("%d", &L);
	int x = 0, y = 0, d = 0;
	int area = 0;
	for (int i = 0; i < L; ++i) {
		scanf(" %s%d", S, &T);
		for (int t = 0; t < T; ++t)
			for (int j = 0; S[j]; ++j) {
				if (S[j] == 'L')
					d = LEFT(d);
				else if (S[j] == 'R')
					d = RIGHT(d);
				else {
					area += x * dy[d] - y * dx[d];
					if (d % 2)
						update_hor(min(x, x+dx[d]), y);
					else
						update_ver(x, min(y, y+dy[d]));
					x += dx[d];
					y += dy[d];
				}
			}
	}
	int p = min_element(bottom, bottom+SIZE) - bottom;
	for (int i = 1; i < p; ++i)
		if (bottom[i] > bottom[i-1])
			bottom[i] = bottom[i-1];
	for (int i = SIZE - 2; i > p; --i)
		if (bottom[i] > bottom[i+1])
			bottom[i] = bottom[i+1];
	p = max_element(top, top+SIZE) - top;
	for (int i = 1; i < p; ++i)
		if (top[i] < top[i-1])
			top[i] = top[i-1];
	for (int i = SIZE - 2; i > p; --i)
		if (top[i] < top[i+1])
			top[i] = top[i+1];
	int total = 0;
	for (int i = 0; i < SIZE; ++i) {
		if (top[i] >= bottom[i])
			total += top[i] - bottom[i];
	}
	return total - abs(area/2);
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		printf("%d\n", solve());
	}
	return 0;
}
