#include <cstdio>

const int MAX=60;

long long int p2[MAX];

long long int min(long long int x,long long int y)
{
	return x<y?x:y;
}

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	p2[0]=1;
	for(int i=1;i<MAX;i++)
		p2[i]=p2[i-1]*2;

	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		int n;
		long long int p;
		scanf("%d%lld",&n,&p);
		int i;
		long long rank=0;
		printf("Case #%d: ",c);
		if(p==p2[n])
			printf("%lld ",p2[n]-1);
		else
		{
			for(i=1;;i++)
			{
				rank+=p2[n-i];
				if(rank+1>p)
					break;
			}
			//rank-=p2[n-i];
		
			printf("%lld ",min(p2[i]-2,p2[n]-1));
		}
		for(i=1;;i++)
		{
			rank=p2[i];
			if(rank>p)
				break;
		}
		//rank=p2[i-1];
		printf("%lld\n",p2[n]-p2[n-i+1]);

	}
	return 0;
}