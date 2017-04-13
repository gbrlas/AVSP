#include <cstdio>
#include <string>
using namespace std;

struct SS {int len, id[128], flg[128];} a[128];

inline int cnt_dig(int k) {
	int s = 0;
	while (k) {
		s += (k&1);
		k >>= 1;
	}
	return s;
}

int main() {
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	int T, i, m, n, j, mk, tmp, best, bestmk, ca = 0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&m);
		for (i = 0 ; i < m ; i++) {
			scanf("%d",&a[i].len);
			for (j = 0 ; j < a[i].len ; j++) {
				scanf("%d%d",&a[i].id[j],&a[i].flg[j]);
				--a[i].id[j];
			}
		}
		best = 100100100; bestmk= -1;
		for (mk = 0 ; mk < (1<<n) ; mk++) {
			for (i = 0 ; i < m ; i++) {
				for (j = 0 ; j < a[i].len ; j++) {
					if (a[i].flg[j] && (mk&(1<<a[i].id[j])) ||
						!a[i].flg[j] && (!(mk&(1<<a[i].id[j]))))
						break;
				}
				if (j == a[i].len) break;
			}
			//printf("mk:%d i:%d\n",mk,i);
			if (i == m) {
				tmp = cnt_dig(mk);
				if (tmp < best) {
					best = tmp;
					bestmk = mk;
				}
			}
		}
		printf("Case #%d:",++ca);
		if (bestmk != -1)
		for (i = 0 ; i < n ; i++) {
			printf(" %d",bestmk&1);
			bestmk >>= 1;
		}
		else printf(" IMPOSSIBLE");
		printf("\n");
	}
	return 0;
}
