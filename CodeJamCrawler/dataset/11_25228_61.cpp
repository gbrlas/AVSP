#include <stdio.h>
const int maxn=10000;
int n,i,j,k,tt;
double st[maxn],en[maxn],w[maxn],len[maxn],s,t,r,ans,x,s0,tmp;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tt);
	for (int count_t=1;count_t<=tt;++count_t)
	{
		scanf("%lf %lf %lf %lf %d",&x,&s,&r,&t,&n);
		s0=x;
		for (i=0;i<n;i++) 
		{
			scanf("%lf %lf %lf",st+i,en+i,w+i);
			len[i]=en[i]-st[i];
			s0-=len[i];
		}
		len[n]=s0;
		w[n]=0;
		n++;
		for (i=0;i<n;i++)
			for (j=i+1;j<n;j++)
				if (w[i]>w[j])
				{
					tmp=w[i];w[i]=w[j];w[j]=tmp;
					tmp=len[i];len[i]=len[j];len[j]=tmp;
				}
		ans=0;
		for (i=0;i<n;i++)
		{
			s0=len[i]/(w[i]+r);
			if (s0>t) s0=t;
			ans+=s0;
			t-=s0;
			len[i]-=s0*(w[i]+r);
			ans+=len[i]/(w[i]+s);
		}
		printf("Case #%d: %0.6lf\n",count_t,ans);
	}
}