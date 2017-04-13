#include<stdio.h>
#include<algorithm>

using namespace std;

struct dat
{
	int sh,sm;
	int eh,em;
	bool flag;
};

bool operator < (dat a, dat b)
{
	if (a.sh==b.sh)
	{
		if (a.sm==b.sm)
		{
			if (a.eh==b.eh) return a.em<b.em;
			else return a.eh<b.eh;
		}
		else return a.sm<b.sm;
	}
	else return a.sh<b.sh;
}

dat a[201];
struct dat1
{
	int h;
	int m;
	bool flag;
};

dat1 pp[201];

int main()
{
	int t,p;
	int n,m;
	int tt;
	int i,j;
	int resa,resb;
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-small-attempt0.ans","w",stdout);
	freopen("B-large.in","r",stdin);
	freopen("B-large.ans","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&tt);
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
		{
			scanf("%d:%d %d:%d",&a[i].sh,&a[i].sm,&a[i].eh,&a[i].em);
			a[i].flag=true;
		}
		for (i=1;i<=m;i++)
		{
			scanf("%d:%d %d:%d",&a[i+n].sh,&a[i+n].sm,&a[i+n].eh,&a[i+n].em);
			a[i+n].flag=false;
		}
		sort (a+1,a+n+m+1);
		resa=0;
		resb=0;
		for (i=1;i<=n+m;i++)
		{
			for (j=1;j<=resa+resb;j++)
				if ((pp[j].flag==a[i].flag)&&(pp[j].h<a[i].sh||(pp[j].h==a[i].sh&&pp[j].m<=a[i].sm))) break;
			if (j==resa+resb+1)
			{
				if (a[i].flag) resa++;
				else resb++;
			}
			pp[j].flag=!a[i].flag;
			pp[j].m=a[i].em+tt;
			if (pp[j].m>=60)
			{
				pp[j].h=a[i].eh+1;
				pp[j].m=pp[j].m-60;
			}
			else pp[j].h=a[i].eh;
		}
		printf("Case #%d: %d %d\n",p,resa,resb);
	}
	return 0;
}


