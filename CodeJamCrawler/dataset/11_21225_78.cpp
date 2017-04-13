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
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

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

#define N 1111

int main()
{
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int L,s,r,n,i;
		double t;
		scanf("%d%d%d%lf%d",&L,&s,&r,&t,&n);
		PII a[N];
		for(i=0;i<n;i++)
		{
			int b,e,w;
			scanf("%d%d%d",&b,&e,&w);
			a[i]=mp(w,e-b);
			L-=e-b;
		}
		a[n++]=mp(0,L);
		sort(a,a+n);
		double res=0;
		for(i=0;i<n;i++)
		{
			double curt=min(t,1.*a[i].Y/(r+a[i].X));
			res+=curt;
			t-=curt;
			res+=(a[i].Y-curt*(r+a[i].X))/(s+a[i].X);
		}
		printf("%.9lf\n",res);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
