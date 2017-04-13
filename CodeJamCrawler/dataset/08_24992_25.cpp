#include <cstdio>
#include <string>
using namespace std;

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small.0.out","w",stdout);
	int T, ca = 0;
	int n, m, A, x1, y1, x2, y2, flg;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&n,&m,&A);
		flg = 0;
		for (x1 = 0 ; x1 <= n ; x1++)
			for (y2 = 0 ; y2 <= m ; y2++)
				for (x2 = 1 ; x2 <= n ; x2++) {
					if ((x1 * y2 - A) % x2 == 0) {
						y1 = (x1*y2-A) / x2;
						if (y1 >= 0 && y1 <= m) {
							flg = 1;
							goto out;
						}
					}
				}
out:
		printf("Case #%d: ",++ca);
		if (flg) printf("0 0 %d %d %d %d\n",x1,y1,x2,y2);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
