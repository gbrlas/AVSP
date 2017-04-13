/*By Zine.Chant*/
#include<algorithm>
#include<iterator>
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<queue>
#include<map>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
const int maxn=11111;
struct node
{
	int x,y,k;
};
struct square
{
	int r,k,x,y;
};
square a[maxn];
int n,v,t,w,l;
node d[maxn];
bool cmp(square x,square y)
{
	return x.r>y.r;
}
bool cmp2(square x,square y)
{
	return x.k<y.k;
}
void putith(int l,int x,int y)
{
	while (t<=n&&2*a[t].r+x<=l)
	{
		x+=a[t].r;
		a[t].y=x;
		x+=a[t].r;
		a[t].x=y;
		t++;
	}
}
void putitl(int l,int x,int y)
{
	while (t<=n&&2*a[t].r+x<=l)
	{
		x+=a[t].r;
		a[t].x=x;
		x+=a[t].r;
		a[t].y=y;
		t++;
	}
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d\n",&v);
	for (int u=1;u<=v;u++)
	{
		scanf("%d %d %d\n",&n,&w,&l);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].r);
			a[i].k=i;
		}
		scanf("\n");
		sort(a+1,a+n+1,cmp);
		a[1].x=0;a[1].y=0;
		t=2;
		putith(l,a[1].r,0);
		putitl(w,a[1].r,0);
		d[1].x=a[1].r;
		d[1].y=l;
		d[1].k=a[1].r;
		for (int i=t,t=1;i<=n;i++)
			for (int j=1;j<=t;j++)
				if (d[j].y-d[j].x>a[i].r*2&&d[j].k+a[i].r*2<=w)
				{
					a[i].x=d[j].x+a[i].r;
					a[i].y=d[j].k+a[i].r;
					d[++t].x=d[j].x;
					d[t].y=d[j].x+a[i].r*2;
					d[t].k=d[j].k+a[i].r*2;
					d[j].x=d[j].x+a[i].r*2;
					break;
				}
		sort(a+1,a+n+1,cmp2);
		printf("Case #%d:",u);
		for (int i=1;i<=n;i++)
		    printf(" %d %d ",a[i].x,a[i].y);
		printf("\n");
	}
	return 0;
}
