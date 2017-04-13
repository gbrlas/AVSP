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

#define N 111

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		fprintf(stderr,"Case #%d:\n",tst);
		printf("Case #%d: ",++tst);
		int n,m;
		scanf("%d%d",&n,&m);
		int a[N][N];
		int r[N]={0},c[N]={0};
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",a[i]+j);
				MAX(r[i],a[i][j]);
				MAX(c[j],a[i][j]);
			}
		bool yes=true;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]<r[i] && a[i][j]<c[j])
					yes=false;
		puts(yes?"YES":"NO");
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
