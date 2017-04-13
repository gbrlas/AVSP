#include<stdio.h>
#include<algorithm>

using namespace std;

struct dat
{
	int r,pos;
	int x,y;
};

bool cmp1(dat a,dat b)
{
	return (a.r>b.r);
}

bool cmp2(dat a, dat b)
{
	return (a.pos<b.pos);
}

dat a[1001];

int main()
{
	int t,p;
	int n;
	int w,l;
	int i;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		scanf("%d%d",&w,&l);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i].r);
			a[i].pos=i;
		}
		sort (a+1,a+n+1,cmp1);
		a[1].x=0;
		a[1].y=0;
		int s=a[1].r;
		for (i=2;i<=n;i++)
		{
			if (a[i].r+s<=w)
			{
				a[i].x=s+a[i].r;
				a[i].y=0;
				s=s+a[i].r*2;
			}
			else break;
		}
		int s1=a[i-1].r;
		s=a[1].r;
		for (;i<=n;i++)
		{
			if (a[i].r+s<=l)
			{
				a[i].y=s+a[i].r;
				a[i].x=0;
				s=s+a[i].r*2;
			}
			else break;
		}
		s=a[i-1].r;
		for (;i<=n;i++)
		{
			if (a[i].r+s<=w)
			{
				a[i].x=s+a[i].r;
				a[i].y=l;
				s=s+a[i].r*2;
			}
			else break;
		}
		s=s1;
		s1=l-a[i-1].r;
		for (;i<=n;i++)
		{
			if (a[i].r+s<=s1)
			{
				a[i].y=s+a[i].r;
				a[i].x=w;
				s=s+a[i].r*2;
			}
			else break;
		}
		if (i<=n) printf("isahfya\n");
		sort (a+1,a+n+1,cmp2);
		printf("Case #%d:",p);
		for (i=1;i<=n;i++)
			printf(" %d %d",a[i].x,a[i].y);
		printf("\n");
	}
	return 0;
}

		