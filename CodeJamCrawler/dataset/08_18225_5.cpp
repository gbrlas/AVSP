#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
pair<int,int> ro[10],pa[12];
int c[10007][10007];
int cnt(int x1,int y1,int x2,int y2)
{
	if((x2+y2-x1-y1)%3)return 0;
	if((x2+y2-x1-y1)<0)return 0;
	if((x2+x2-y2-x1-x1+y1)%3)return 0;
	if((x2+x2-y2-x1-x1+y1)<0)return 0;
	return c[(x2+y2-x1-y1)/3%10007][(x2+x2-y2-x1-x1+y1)/3%10007];
}
int main()
{
	freopen("D-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	c[0][0]=1;
	for(int i=1;i<10007;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%10007;
	}
	int n;
	scanf("%d",&n);
	for(int nn=1;nn<=n;nn++)
	{
		int h,w,r;
		scanf("%d%d%d",&h,&w,&r);
		for(int i=0;i<r;i++)scanf("%d%d",&ro[i].first,&ro[i].second);
		sort(ro,ro+r);
		int ans=0;
		for(int m=0;m<1<<r;m++)
		{
			int lp=1;
			pa[0]=make_pair(1,1);
			for(int i=0;i<r;i++)if((1<<i)&m)pa[lp++]=ro[i];
			pa[lp++]=make_pair(h,w);
			int am=1;
			for(int i=1;i<lp;i++)am=am*cnt(pa[i-1].first,pa[i-1].second,pa[i].first,pa[i].second)%10007;
			ans=(ans+10007+((lp%2)?-1:1)*am)%10007;
		}
		printf("Case #%d: %d\n",nn,ans);
	}
}
