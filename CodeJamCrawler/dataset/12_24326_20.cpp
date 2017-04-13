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
const int maxn=111111;
struct node
{
	int x,y,f;
};
node a[maxn];
int n,u,m;
bool flag;
bool cmp(node x,node y)
{
	return x.x<y.x;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n",&u);
	for (int v=1;v<=u;v++)
	{
		scanf("%d\n",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d\n",&a[i].x,&a[i].y);
			a[i].f=0;
		}
		scanf("%d\n",&m);
		a[1].f=a[1].x;
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n;i++)
		{
			int j=i;
			while (j<=n&&a[j+1].x<=a[i].x+a[i].f)
			{
				j++;
				a[j].f=max(min(a[j].y,a[j].x-a[i].x),a[j].f);
			}
		}
		flag=false;
		for (int i=1;i<=n;i++)
			if (a[i].f!=0&&a[i].x+a[i].f>=m) flag=true;
		printf("Case #%d: ",v);
		if (flag) printf("YES\n");else printf("NO\n");
	}
	return 0;
}
