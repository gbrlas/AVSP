#include <stdio.h>

#define PI (3.1415926535897932384626433832795L)

long long int r,t;
long long int find(long long int lo,long long int hi)
{
	if(lo>=hi)
		return lo;
	long long int mid = (lo+hi)/2+1;
	long long int cal = (2*r-3)*mid+2*mid*(mid+1);
	if(cal<=t)
		return find(mid,hi);
	else
		return find(lo,mid-1);
}

long long int min(long long int x,long long int y)
{
	return x<y?x:y;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%I64d%I64d",&r,&t);
		printf("Case #%d: %I64d\n",i+1,find(1,min(t/r,1000000000)));
	}
	return 0;
}
/*
(r+3)^2-(r+2)^2
	6r+9-4r-4
	2r+5
pi((r+1)^2-r^2)
	(2r+1)pi
	(2r+5)
	2r+9

	sigma n=1 to ans (2r+4n-3)pi
	(2r-3)*ans+2ans(ans+1)<=t

	2^64
	1024^6
	*/