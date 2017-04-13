#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int dataset, t = 1;
	double c, f, x, ans, money, now;
	scanf("%d", &dataset);
	while(dataset--){
		scanf("%lf %lf %lf", &c, &f, &x);
		
		now = 2.0, ans = 0.0;
		while(1){
			if(x/now > c/now + x/(now+f)){ //continue to buy
				ans += c/now;
				//printf("!%lf ", c/now);
				now += f;
			}
			else{
				ans += x/now;
				//printf("~%lf ", x/now);
				break;
			}
		}
		printf("Case #%d: %.7lf\n", t++, ans);
	}
	return 0;
}
