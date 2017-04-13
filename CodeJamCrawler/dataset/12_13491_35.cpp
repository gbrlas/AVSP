#include<stdio.h>
int main()
{
	int T,N,S,p,i,j,n,c,c1,t;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		c=0;c1=0;
		scanf("%d%d%d",&N,&S,&p);
		for(j=1;j<=N;j++){
		scanf("%d",&n);
		if(n%3==0)
		{
			if(n/3>=p) c++;
			else if(c1<S && (n/3+1)>=p && (n/3)>=1) {c++;c1++;}
		}
		else if(n%3==1)
		{
			if((n/3+1)>=p) c++;
		}
		else
		{
			if((n/3+1)>=p) c++;
			else if(c1<S && (n/3+2)>=p) {c++;c1++;}
		}
		}
		printf("Case #%d: %d\n",i,c);
	}
	return 0;
}
