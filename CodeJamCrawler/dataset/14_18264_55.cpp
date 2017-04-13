#include<stdio.h>
static int compare(const void *i1,const void *i2)
{
	double *p1=(double *)i1;
	double *p2=(double *)i2;
	if(*p1 < *p2)
		return -1;
	return 1;
}

int main()
{
	int st,end,ct,ct2,x,n,t,t1;
	double a1[1001],a2[1001];
	scanf("%d",&t);
	for(t1=1;t1<=t;t1++)
	{
		scanf("%d",&n);
		for(x=0;x<n;x++)
			scanf("%lf",&a1[x]);
		for(x=0;x<n;x++)
			scanf("%lf",&a2[x]);
		printf("Case #%d: ",t1);
		qsort(a1,n,sizeof(double),compare);
		qsort(a2,n,sizeof(double),compare);
		st = 0;ct = 0;
		for(x=0;x<n;x++)
		{
			if(a1[x] > a2[st])
			{
				ct++;
				st++;
			}
		}
		ct2 = 0;end = n-1;
		for(x=n-1;x>=0;x--)
		{
			if(a1[x]>a2[end])
				ct2++;
			else
				end--;
		}
		printf("%d %d\n",ct,ct2);
	}
	return 0;
}
