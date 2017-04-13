#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int a[600],b[600];
int gcd(int x,int y)
{
	if (x<y)return gcd(y,x);
	return x%y?gcd(y,x%y):y;
}
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,c=0,n;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)scanf("%d",a+i);
		sort(a,a+n);
		n=unique(a,a+n)-a;
		if (n==1)
		{
			printf("Case #%d: %d\n",++c,0);
			continue;
		}
		for (i=0;i<n-1;i++)
		{
			b[i]=abs(a[i]-a[i+1]);
		}
		int g=b[0];
		for (i=0;i<n-1;i++)
		{
			if (b[i]==0)continue;
			g=gcd(g,b[i]);
		}
		int tmp=a[0]%g;
		//printf("%d\n",g);
		if (!tmp)
		{
			;
		}
		else 
		{
			tmp=a[0]/g;
			tmp++;
			tmp*=g;
			tmp-=a[0];
		}
		printf("Case #%d: %d\n",++c,tmp);
	}
	return 0;
}
