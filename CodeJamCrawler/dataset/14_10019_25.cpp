#include <stdio.h>
int main()
{
	int T;
	double c, f, x;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		double unit = 2, ans = 0;
		scanf("%lf%lf%lf", &c, &f, &x);
		while(1){
			double a = x / unit;
			double b = (c / unit) + (x / (unit + f));
			if(b > a + 1e-9){
				ans = ans + a;
				break;
			}
			ans = ans + c / unit;
			unit = unit + f;
		}
		printf("Case #%d: %.9lf\n", t, ans);
	}
	return 0;
}
