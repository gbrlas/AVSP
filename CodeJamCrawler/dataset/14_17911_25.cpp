#include<stdio.h>

int main(void){
	int t, i;
	double c, f, x, rate, sum3, sum1, sum2, scale = 10000000000000 * 1.0;
	scanf("%d",&t);
	double op[t];
	for(i = 0; i < t; i++){
		scanf("%lf %lf %lf",&c, &f, &x);
		rate = 2.0;
		if(c/rate > x/rate){
			op[i] = x/rate;
			continue;	
		}
		sum3 = x/rate;
		sum1 = c/rate;
		rate += f;
		sum1 += x/rate;
		sum2 = sum1 - x/rate + c/rate + x/(rate+f);
		if(sum3 < sum1){
			op[i] = sum3;
			continue;
		}
		while(sum1 > sum2){
			
			sum1 = sum2;
			rate += f;
			sum2 = sum1 - x/rate + c/rate + x/(rate+f);
		}
		op[i] = sum1;
		
	}
		for(i = 0; i < t; i++)
		printf("Case #%d: %.7lf\n",i+1,op[i]);
	return 0;

}
