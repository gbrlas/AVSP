#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

struct Pt {int x, y, r;} pt[128];

double calc(Pt a, Pt b) {
	return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)) + a.r + b.r) / 2;
}

int main() {
	freopen("D-small.in","r",stdin);
	freopen("D-small.out","w",stdout);
	int T, n, i;
	int ca = 0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (i = 0 ; i < n ; i++)
			scanf("%d%d%d",&pt[i].x,&pt[i].y,&pt[i].r);
		printf("Case #%d: ",++ca);
		if (n == 1) {
			printf("%d\n",pt[0].r);
		} else if (n == 2) {
			printf("%d\n",max(pt[0].r,pt[1].r));
		} else {
			double ans = max(calc(pt[0], pt[1]), (double)pt[2].r);
			ans <?= max(calc(pt[0], pt[2]), (double)pt[1].r);
			ans <?= max(calc(pt[1], pt[2]), (double)pt[0].r);
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}
