#include <cstdio>
using namespace std;

int main()
{
	double t, a, b, c, f, cost, x;
	int T, N = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%lf%lf%lf", &cost, &f, &x);
		c = 2.0;
		t = 0.0;
		while(1) {
			a = (cost / c) + (x / (c + f));
			b = x / c;
			//printf("%lf %lf\n", a, b);
			if(b < a) {
				t += b;
				break;
			} else {
				//printf("Built another farm, time increased by %lf\n", cost / c);
				//printf("Cookie speed up to %lf\n", c + f);
				t += cost / c;
				c += f;
			}
		}
		printf("Case #%d: %.7lf\n", N++, t);
	}
	return 0;
}


