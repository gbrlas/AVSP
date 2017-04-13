#include <stdio.h>
#define getMin(a,b)(((a)>(b))?(b):(a))

int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){
		double a,b,c;
		scanf("%lf %lf %lf",&a,&b,&c);

		double elp=0;
		double mx=c/2.0;
		double result=c;

		int i=0;

		while( true ){
			if( i > 0 )
				elp=elp+a/(2.0+b*(i-1));
			//printf("%lf\n",elp);
			if(  elp+c/(2.0+b*i) - result > -1e-9 ) break;
			result=elp+c/(2.0+b*i);
			//result=getMin(result,elp+c/(2.0+b*i));
			i++;
		}

		printf("Case #%d: %.7lf\n",++T,result);
	}
	return 0;
}
