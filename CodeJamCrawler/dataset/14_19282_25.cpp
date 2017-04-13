#include <stdio.h>

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		double c,f,x;
		scanf("%lf%lf%lf",&c, &f, &x);
		double r = x/2, z=2, y=0;
		while (1) {
			double rr = y+c/z+x/(z+f);
			if(rr>r){
				break;
			}
			r=rr;
			y+=c/z;
			z+=f;
		}
		printf("Case #%d: %.9lf\n",tt,r);
	}
}
