#include <stdio.h>

int main() {
	int t,i,j,m;
	double c,f,x,k,s,t1,t2,a;
	
	scanf("%d",&t);
	
	for(m=1;m<=t;m++) 
	{
		k = 2.0;
		a = 0.0;
		scanf("%lf%lf%lf",&c,&f,&x);
		t1 = x/k;
		while(1) {
			a = c / k + a;
			k = k + f;
			t2 = a + x / k;
			if(t1 < t2) {
				printf("Case #%d: %.7lf\n",m,t1);
				break;
			}
			t1 = t2;
		}
		
	}
	return 0;
}
