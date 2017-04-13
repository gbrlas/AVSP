#include<cstdio>
int main()
{
	int t, T, A, B, K, i, j, count, m;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		count=0;
		scanf("%d %d %d",&A,&B,&K);
		for(i=0;i<A;i++)
		{
			for(j=0;j<B;j++)
			{
				m=i&j;
				if(m<K)
					count++;
			}
		}
		printf("Case #%d: ",t);
		printf("%d\n",count);
	}
	return 0;
}
