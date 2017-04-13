#include<stdio.h>
long double solve(long double cost, long double rateIncrease, long double goal, long double t1, long double t2, int round)
{
	if(t1<t2)
		return t1;

	t1=t2;
	t2=t2-(goal/(round*rateIncrease+2))+cost/(round*rateIncrease+2)+goal/((round+1)*rateIncrease+2);

	return solve(cost,rateIncrease,goal,t1,t2,++round);

}
main(){
	
	int T,i;
	long double C,F,X;
	scanf("%d",&T);

	for(i=0;i<T;i++){
	scanf("%LF %LF %LF ",&C,&F,&X);

	printf("Case #%d: %.7LF\n",i+1, solve(C,F,X,X/2,C/2+X/(F+2), 1) );
}
}