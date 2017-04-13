#include <cstdio>
#include <cstring>
int c[2000010];
int main() {
	int testnum, a, b, tmp, t, min, cur;
	long long ret = 0;
	scanf("%d", &testnum);
	for (int test = 1; test <= testnum; test++) {
		scanf("%d%d", &a, &b);
		memset(c, 0, sizeof(c));
		ret = 0;
		for (int i = a; i <= b; i++) {
			tmp = 1; t = 0; min = i; cur = i;
			while (tmp <= i) tmp *= 10, t++; tmp /= 10; t--;
			for (int j = 0; j <= t; j++) {
				cur = (cur % tmp) * 10 + (cur / tmp);
				if (cur < min) min = cur;
			}
			c[min]++;
		}
		for (int i = 0; i <= b; i++) if (c[i]) ret += ((long long)c[i] * (c[i] - 1)) / 2;
		printf("Case #%d: %lld\n", test, ret);
	}
	return 0;
}