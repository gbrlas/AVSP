#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-7
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,x;
	scanf("%d",&t);

	for (x=1; x<=t; ++x)
	{
	    int a[110];
	    int n,s,p,i,cnt= 0,done= 0,temp;
	    bool made[110]= {0};
	    scanf("%d%d%d",&n,&s,&p);

	    for (i=1; i<=n; ++i) scanf("%d",&a[i]);

	    for (i=1; i<=n; ++i)
	    {
	        if (!p) {cnt++; made[i]= 1;continue;}

	        if (a[i]>=p+p-1+p-1) cnt++, made[i]= 1;
	    }

	    for (i=1; i<=n; ++i)
	    {
	        if (done==s) break;
	        if (made[i]) continue;
	        temp= p-2+p-2+p;
	        temp= max(temp,2);
	        if (a[i]>=temp) cnt++,done++;
	    }

	    printf("Case #%d: %d\n",x,cnt);
    }

	return 0;
}
