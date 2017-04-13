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
#define LL long long
using namespace std;

const int maxN=100;
LL ans[maxN],a[20];

bool judge(LL x)
{
	LL xx=x*x;
	ms(a,0);
	while (x!=0) a[++a[0]]=x%10,x/=10;
	fi(i,1,a[0]) if (a[i]!=a[a[0]+1-i]) return false;
	ms(a,0);
	while (xx!=0) a[++a[0]]=xx%10,xx/=10;
	fi(i,1,a[0]) if (a[i]!=a[a[0]+1-i]) return false;

	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ms(ans,0);
	fi(i,1,10000000)
		if (judge(i)) ans[++ans[0]]=i;
	fi(i,1,ans[0]) ans[i]=ans[i]*ans[i];

	int T,a,b,cnt;
	scanf("%d",&T);
	fi(i,1,T)
	{
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		cnt=0;
		fi(j,1,ans[0]) if (ans[j]>=a && ans[j]<=b) cnt++;
		printf("Case #%d: %d\n",i,cnt);
	}

	return 0;
}


