#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int a,b;
		scanf("%d%d",&a,&b);
		int ans=0;
		for(int n=a;n<=b;n++)
		{
			int d[11];
			int i=0,j,k;
			for(int x=n;x;x/=10) d[i++]=x%10;
			int ms[11];
			int len=0;
			for(j=0;j<i;j++) if(d[(j+i-1)%i])
			{
				int m=0,p=1;
				for(k=0;k<i;k++)
				{
					m+=p*d[(j+k)%i];
					p*=10;
				}
				if(n<m && m<=b) ms[len++]=m;
			}
			sort(ms,ms+len);
			ans+=unique(ms,ms+len)-ms;
		}
		printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
