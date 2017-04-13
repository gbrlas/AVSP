#include<stdio.h>

int main(){
	int nt;
	scanf("%d",&nt);
	for(int t=0;t<nt;t++){
		double c,f,x;
		double speedNow = 2.0;
		double timeNow = 0.0;
		scanf("%lf %lf %lf",&c,&f,&x);

		while(true){
			if( x/speedNow < ((c/speedNow) + x/(speedNow+f)) ){
				timeNow+=x/speedNow;
				break;
			}
			else{
				timeNow+=(c/speedNow);
				speedNow+=f;
			}
		}
		printf("Case #%d: %.7lf\n",t+1,timeNow);
	}

	return 0;
}