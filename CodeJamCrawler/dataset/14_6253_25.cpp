#include <stdio.h>
#include <math.h>
#include <assert.h>

double a[10000];
int main()
{
	int t, k, i;	
	double c, f, x;
	int try;
	double res, val;

	freopen("pb.in", "r", stdin);
	freopen("pb.out", "w", stdout);

	scanf("%d", &t);
	for (k = 1; k <= t; k++) {
		scanf("%lf %lf %lf", &c, &f, &x);
		a[0] = x / 2;	
		for (try = 1; try < 10000; try++) {
			res = 0;
			for (i = 0; i < try; i++) {
				res += c / (2 + i * f);
			}
			res += x / (2 + try * f);
			a[try] = res;
			if (fabs(a[try] > a[try - 1]) > (double) 0.00000001) {
				val = a[try - 1];
				break;
			}		
		}
		assert(try < 10000);
		printf("Case #%d: %.07lf\n", k, val);
	}
	return 0;
}

