/*
 * Name 	: GCJ Cookie
 * Author	: DeathEater (pushkar8723@gmail.com)
 */
#include <stdio.h>
int main(){
	int t, k;
	scanf("%d", &t);
	for (k = 1; k <= t; k++) {
		double c, f, x, time = 0, ct, nxt, rate = 2;
		scanf("%lf %lf %lf", &c, &f, &x);
		while(1) {
			if ((x/rate) > (x/(rate + f) + c/rate)) {
				time += c/rate;
				rate += f;
			} else {
				time += x/rate;
				break;
			}
		}
		printf("Case #%d: %.7lf\n", k, time);
	}
	return 0;
}

