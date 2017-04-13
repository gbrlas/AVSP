#include<stdio.h>
int main()
{
	int t,T,N,K,i;
	unsigned a[32]={0};
	freopen("A-small-attempt1.in","r",stdin);
	freopen("result1.txt","w",stdout);
	for(i=1;i<32;i++)a[i]=1+(a[i-1]<<1);
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d",&N,&K);
		printf("Case #%d: %s\n",t,(K&a[N])==a[N]?"ON":"OFF");
	}
}
