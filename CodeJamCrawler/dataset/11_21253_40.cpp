#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:216777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;
typedef unsigned __int64 ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

int main()
{
	freopen("b1.in","r",stdin);
	freopen("b1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int a[1111];
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		int ans=inf;
		multiset<int> s, s0;
		int cur = -inf;
		for(i=0;i<n;i++)
		{
			if(a[i]!=cur+1)
			{
				if(s.sz) MIN(ans,*s.begin());
				s=s0;
				s0.cl;
				cur++;
				if(a[i]!=cur+1)
				{
					if(s.sz) MIN(ans,*s.begin());
					s.cl;
					cur=a[i]-1;
				}
			}
			if(!s.sz) s0.insert(1); else
			{
				s0.insert(*s.begin() + 1);
				s.erase(s.begin());
			}
		}
		if(s.sz) MIN(ans,*s.begin());
		if(s0.sz) MIN(ans,*s0.begin());
		if(ans==inf) ans=0;
		printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
