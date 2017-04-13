#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main()
{
	int n;
	int t,i,j,k,jum;
	int x[10],y[10];
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
			jum+=(x[j]*y[k]);
			k--;
		}
		printf("Case #%d: %d\n",i+1,jum);
	}
	
	return 0;
}
