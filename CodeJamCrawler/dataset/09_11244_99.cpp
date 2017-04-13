#include <stdio.h>
#define L 20
#define D 5010
#define N 510
int t[D][L], p[N][L], cnt[N];
int main()
{
	int l, d, n;
	char tmp;

	//freopen("A-small-attempt1.in", "r", stdin);
	//freopen("A-small-attempt1.out", "w", stdout);
	scanf("%d%d%d", &l, &d, &n);
	for (int i = 1; i <= d; i++)
		for (int j = 1; j <= l; j++) {
			scanf(" %c", &tmp);
			t[i][j] = 1 << (tmp-'a');
		}
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
		for (int j = 1; j <= l; j++) {
			p[i][j] = 0;
			scanf(" %c", &tmp);
			if (tmp == '(') {
				scanf(" %c", &tmp);
				while (tmp != ')') {
					p[i][j] |= 1 << (tmp-'a');
					scanf(" %c", &tmp);
				}
			}
			else
				p[i][j] = 1 << (tmp-'a');
		}
		for (int k = 1; k <= d; k++) {
			int cur;
			for (cur = 1; cur <= l; cur++)
				if ((t[k][cur] & p[i][cur]) == 0)
					break;
			if (cur > l) cnt[i]++;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("Case #%d: %d\n", i, cnt[i]);
	return 0;
}