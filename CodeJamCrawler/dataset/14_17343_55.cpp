#include<stdio.h>
#include <iostream>
using namespace std;
double time(double c,double f,double x)
{
	double result=0,base=0,current=x/2;
	int i=0;
	while(true){
		result=base+x/(2+i*f);
		base=base+c/(2+i*f);
		if(result>current)
			break;
		current=result;
		i++;

	}
	return current;
}

int main() {
	int index, cc = 0;
	double c,f,x;
	freopen("a.in", "r", stdin);
	freopen("out","w",stdout);
	scanf("%d", &index);
	while (index--) {
		scanf("%lf",&c);
		scanf("%lf",&f);
		scanf("%lf",&x);
		double re=time(c,f,x);
		printf("Case #%d: %0.7lf\n", ++cc,re);

	}
	return 0;
}
