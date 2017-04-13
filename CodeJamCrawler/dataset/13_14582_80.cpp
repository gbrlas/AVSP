#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#define fi(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;

const int maxN=200;
int n,m,a[maxN][maxN],r[maxN],c[maxN],ans[maxN][maxN];

void init()
{
	scanf("%d%d",&n,&m);
	ms(r,0);ms(c,0);
	fi(i,1,n) fi(j,1,m)
	{
		scanf("%d",&a[i][j]);
		r[i]=max(r[i],a[i][j]);
		c[j]=max(c[j],a[i][j]);
	}
}

void work()
{
	fi(i,1,n) fi(j,1,m) ans[i][j]=100;
	fd(h,100,1)
	{
		fi(i,1,n) fi(j,1,m) if (r[i]<=h || c[j]<=h) ans[i][j]=h;
	}
}

bool judge()
{
	fi(i,1,n) fi(j,1,m) if (a[i][j]!=ans[i][j]) return false;
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	fi(i,1,T)
	{
		init();
		work();
		printf("Case #%d: ",i);
		if (judge()) printf("YES\n");else printf("NO\n");
	}
	return 0;
}
