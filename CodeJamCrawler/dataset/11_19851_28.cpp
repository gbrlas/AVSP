#include <cstdio>

int data[105];
inline void solve(const int &tc) {
	int N, L, H;
	int i, j;
	scanf("%d %d %d", &N, &L, &H);
	for (i = 0; i < N; i++)
		scanf("%d", &data[i]);
	printf("Case #%d: ", tc + 1);
	for (i = L; i <= H; i++) {
		bool bisa = true;
		for (j = 0; j < N; j++) {
			if (!( (i % data[j] == 0) || (data[j] % i == 0))) {
				bisa = false;
				break;
			}
		}
		if (bisa) {
			printf("%d\n", i);
			return;
		}
	}
	puts("NO");
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
		solve(i);
	return 0;
}
