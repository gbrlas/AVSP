#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <cmath>
#define eps 0.000001
using namespace std;
int main(){
	double c,f,x;
	int T;
	bool flag;
	double tym, rate, prevtym;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		scanf("%lf %lf %lf",&c,&f,&x);
		rate=2;
		tym=c/rate;
		prevtym = 0;
		while(prevtym + x/rate >= tym + x/(rate+f)){
			prevtym = tym;
			tym = prevtym + c/(rate+f);
			rate += f;
		}
		printf("Case #%d: %.7lf\n",k+1,prevtym+x/rate);
	}
	return 0;
}