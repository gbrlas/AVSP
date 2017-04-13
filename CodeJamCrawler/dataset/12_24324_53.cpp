#include<algorithm>
#include<iterator>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2001;
struct node
{
	int x,y;
};
node a[maxn];
int f[maxn];
int v,n,s,t,y;
bool flag=false;

void search()
{
	int x=0;
	for (int i=1;i<=n;i++)
		if	(s>=a[i].y&&f[i]!=2)
		{
			x=1;
			s+=2-f[i];
			t++;
			f[i]=2;
		}
	if (x==1) search();
}
void search0()
{
	int x=0;
	for (int i=1;i<=n;i++)
		if (f[i]==0&&a[i].x<=s)
		{
			x=i;
			break;
		}
	for (int i=x+1;i<=n;i++)
		if (a[i].y>a[x].y&&a[i].x<=s&&f[i]==0) x=i;
	if (x==0) printf("!!!!!\n");
	s++;
	t++;
	f[x]=1;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d\n",&v);
	for (int u=1;u<=v;u++)
	{
		scanf("%d\n",&n);
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
			scanf("%d %d\n",&a[i].x,&a[i].y);
		s=0;t=0;
		y=s;
		while (s<2*n)
		{
			flag=true;
			y=s;
			for (int i=1;i<=n;i++)
				if ((f[i]==0&&s>=a[i].x)||(f[i]==1&&s>=a[i].y))
				{
					flag=false;
					break;
				}
			if (flag) break;
			search();
			if (s==y) search0();
		}
		if (s>2*n) printf("!!!\n");
		if (s==2*n) printf("Case #%d: %d\n",u,t);
		else printf("Case #%d: Too Bad\n",u);
	}
	return 0;
}
