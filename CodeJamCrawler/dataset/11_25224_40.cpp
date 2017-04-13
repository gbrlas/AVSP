#include <stdio.h>
#include <stdlib.h>
const int maxn=1000001;
double a[maxn],d[maxn],ans,m;
int i,j,k,n,tt,t,l,c;

int mycmp(const void *i,const void *j)
{
	static double ii;
	ii=*(double*)i;
	static double jj;
	jj=*(double*)j;
	if (ii<jj) return -1;
	else if (ii==jj) return 0;
	else return 1;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tt);
	for (int count_t=1;count_t<=tt;count_t++)
	{
		scanf("%d %d %d %d",&l,&t,&n,&c);
		for (i=0;i<c;i++) scanf("%lf",a+i);
		for (i=c;i<n;i++) a[i]=a[i-c];
		m=0;
		for (i=0;i<n;i++)
			if (m+a[i]*2>t)
			{
				d[i]=(m+a[i]*2-t)/2;
				m=t;
			} else
			{
				m+=a[i]*2;
				d[i]=0;
			}
		qsort(d,n,sizeof(double),mycmp);
		ans=0;
		for (i=0;i<n;i++) ans=ans+a[i]*2;
		for (i=n-1;i>=n-l;i--) ans=ans-d[i];
		printf("Case #%d: %0.0lf\n",count_t,ans);
	}
}