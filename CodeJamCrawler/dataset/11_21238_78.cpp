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

#define N 1010101
int a[N];
int p[N],plen=0;

int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	int i,j;
	for(i=2;i<N;i++) if(!a[i])
	{
		p[plen++]=i;
		for(j=i+i;j<N;j+=i) a[j]=1;
	}
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		LL n;
		scanf("%lld\n",&n);
		LL ans=1;
		for(i=0;i<plen;i++)
		{
			int q=p[i];
			if(LL(q)*q>n) break;
			ans+=int(log(1.*n)/log(1.*q)-1+eps);
		}
		if(n==1) ans=0;
		printf("%lld\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
