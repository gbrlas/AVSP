#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

const int MAXH = 1000000;
const int MAXN = 5018;
struct EE {int h, w; char c;} e[MAXN];
int n, m;

inline int fit(int h1, int h2, int w1, int w2) {
	int i;
	for (i = 0 ; i < n ; i++) {
		if (e[i].c == 'B') {
				if (!(e[i].h >= h1 && e[i].h <= h2
				&& e[i].w >= w1 && e[i].w <= w2)) return 0;

		} else {
			if ((e[i].h >= h1 && e[i].h <= h2
				&& e[i].w >= w1 && e[i].w <= w2)) return 0;

		}
	}
	return 1;
}

int hlist[MAXN], wlist[MAXN];

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T, i, ph, pw, ca = 0, tot, cnt, qx, qy;
	char buf[16];
	int h1, h2, w1, w2;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		ph = pw = 0;
		for (i = 0 ; i < n ; i++) {
			scanf("%d%d%s",&e[i].h,&e[i].w,buf);
			e[i].c = buf[0];
			if (buf[0] == 'N') scanf("%s",buf);
			hlist[ph++] = e[i].h;
			wlist[pw++] = e[i].w;
			hlist[ph++] = e[i].h - 1;
			hlist[ph++] = e[i].h + 1;
			wlist[pw++] = e[i].w - 1;
			wlist[pw++] = e[i].w + 1;
		}
		hlist[ph++] = 1;
		hlist[ph++] = MAXH;
		wlist[pw++] = 1;
		wlist[pw++] = MAXH;

		sort(hlist, hlist+ph);
		ph = (int*)unique(hlist, hlist+ph) - hlist;
		sort(wlist, wlist+pw);
		pw = (int*)unique(wlist, wlist+pw) - wlist;

		printf("Case #%d:\n",++ca);
		scanf("%d",&m);
		while (m--) {

			scanf("%d%d",&qx,&qy);
			tot = cnt = 0;
			for (h1 = 0; h1 < ph ; h1++)
				for (h2= h1 ; h2 < ph ; h2++)
					for (w1 = 0; w1 < pw ; w1++)
						for (w2 = w1 ; w2 < pw ; w2++)
							if (fit(hlist[h1],hlist[h2],wlist[w1],wlist[w2])) {
								//printf("[%d %d %d %d] qx:%d qy:%d\n",hlist[h1],hlist[h2],wlist[w1],wlist[w2],qx,qy);
								if (qx >= hlist[h1] && qx <= hlist[h2] && qy >= wlist[w1] && qy <= wlist[w2]) {
									++cnt;
								}
								++tot;
							}

			//printf("cnt:%d tot:%d\n",cnt,tot);
			if (cnt == 0) printf("NOT BIRD\n");
			else if (cnt < tot) printf("UNKNOWN\n");
			else printf("BIRD\n");
		}
	}
    return 0;
}
