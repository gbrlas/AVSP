#include <stdio.h>
#include <math.h>

int reverse(int a){
	int c=0,ex=1;
	if (a>10){
		while(a>0){
			c*=10;
			c=c+(a%10);
			a/=10;
			ex*=10;
		}
	}
	else c=a;
	return c;
	
}
int checkpal(int a){
	if (a<10) return 1;
	else if (reverse(a)==a) return 1;
	else return 0;
	}
	
int checksqr(int a,int b){
	if ((sqrt(a)*sqrt(a))==(b*b)) return 1;
	else return 0;
}

main(){
	int c[100]={0},i,t,a,b,res,ex=1;
	scanf("%d", &t);
	for (i=0;i<t;i++){
		scanf("%d %d", &a, &b);
		for(;a<=b;a++){
			if ((checkpal(a)&&checksqr(a,sqrt(a)))==1)
				if((checkpal(sqrt(a)))==1)
				c[i]++;
		}
		printf("Case #%d: %d\n", i+1, c[i]);
	}
	
}
