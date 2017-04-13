#include <cstdio>

int data[1005];
int tc = 0;
inline void solve() {
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &data[i]);
	int res = 0;
	int tmp = 0;
	int min = 2e9;
	for (i = 0; i < N; i++) {
		res += data[i];
		tmp ^= data[i];
		min = data[i] < min ? data[i] : min;
	}
	tc++;
	printf("Case #%d: ", tc);
	if (tmp != 0)
		puts("NO");
	else
		printf("%d\n", res - min);
}
int main() {
	int jtc;
	scanf("%d", &jtc);
	while(jtc--) solve();
	return 0;
}
