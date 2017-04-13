#include <cstdio>
int main() {
	int t;
	double c, f, x;
	scanf("%d", &t);
	for(int cn=1; cn<=t; ++cn) {
		scanf("%lf %lf %lf", &c, &f, &x);
		int n;
		double ans=1e9, tmp;
		for(n=0; 1; ++n) {
			double speed=2;
			tmp=0;
			for(int i=0; i<n; ++i) {
				tmp+=c/speed;
				speed+=f;
			}
			tmp+=x/speed;
			if( tmp<ans ) ans=tmp;
			else break;
		}
		printf("Case #%d: %.7lf\n", cn, ans);
	}
}