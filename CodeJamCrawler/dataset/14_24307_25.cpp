#include<cstdio>
#include<cstdlib>

#define PP 1000000007


int main()
{
    int T;
    freopen("cj2.in", "r", stdin);
    freopen("cj2.out", "w", stdout);
    
    scanf("%d", &T);
    double c, f, x, ans=0, y=0, e=2;
    for(int t=1; t<=T; t++) {
	scanf("%lf%lf%lf", &c, &f, &x);
	ans = 0, y = 0, e = 2;
	while(true) {
		if((x - y)/e < c/e) {
			ans += (x-y)/e;
			break;
		}
		else {
			ans += c/e;
			y += c;
		}
		if ((x-y) / e < (x-y+c) / (e+f)) {
			ans += (x-y)/e;
			break;
		}
		else {
			e+=f;
			y = 0;
		}
	}
        printf("Case #%d: %lf\n", t, ans);
    }
    return 0;
}
