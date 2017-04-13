#include <cstdio>

int main()
{
	freopen("A-small.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long N,K;
		scanf("%lld%lld",&N,&K);
		printf("Case #%d: ",i+1);
		if(K%(1<<N)==(1<<N)-1)
			printf("ON\n");
		else
			printf("OFF\n");
	}
	return 0;
}