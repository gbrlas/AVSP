#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int x[810],y[810];
int comp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	int t,i,j,k;
	long long jum;
	
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&x[j]);
		}
		for(j=0;j<n;j++)
		{
			scanf("%d",&y[j]);
		}
		qsort(x,n,sizeof(int),comp);
		qsort(y,n,sizeof(int),comp);
		jum=0;
		k=n-1;
		for(j=0;j<n;j++)
		{
			jum+=((long long)x[j]*(long long)y[k]);
			k--;
		}
		printf("Case #%d: %lld\n",i+1,jum);
	}
	
	return 0;
}
