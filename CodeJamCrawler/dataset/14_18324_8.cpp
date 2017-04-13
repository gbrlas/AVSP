#include <stdio.h>

long int solve(long int A,long int B,long int K){
	int i,j,c=0;
	for(i=0;i<A;i++)
		for(j=0;j<B;j++)
			if((i&j)<K)
				c++;

	return c;
}

main(){
	long int T,i,A,B,K;
	scanf("%ld",&T);
	for(i=0;i<T;i++)
		{
			scanf("%ld%ld%ld",&A,&B,&K);
			printf("Case #%d: %ld\n",i+1, solve(A,B,K));
		}
}