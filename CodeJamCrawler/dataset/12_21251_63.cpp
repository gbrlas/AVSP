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

#define N 20
int a[N];
PII b[1<<N];

int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d:\n",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int n,i,j,mask;
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",a+i);
		for(mask=0;mask<bit(n);mask++)
		{
			int s=0;
			for(i=0;i<n;i++)
				if(mask & bit(i)) s+=a[i];
			b[mask]=mp(s,mask);
		}
		sort(b,b+bit(n));
		for(i=1;i<bit(n);i++)
			if(b[i].X==b[i-1].X)
			{
				for(j=0;j<n;j++) if(b[i].Y & bit(j)) printf("%d ",a[j]);
				printf("\n");
				for(j=0;j<n;j++) if(b[i-1].Y & bit(j)) printf("%d ",a[j]);
				printf("\n");
				break;
			}
		if(i==bit(n)) puts("Impossible");
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
