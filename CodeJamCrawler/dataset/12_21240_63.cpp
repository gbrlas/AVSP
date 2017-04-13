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
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d:",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int n,i,j;
		scanf("%d",&n);
		int s[111];
		int sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",s+i);
			sum+=s[i];
		}
		for(i=0;i<n;i++)
		{
			double L=0;
			double R=1;
			for(int it=0;it<50;it++)
			{
				double p=(L+R)/2;
				double sp=0;
				for(j=0;j<n;j++)
					sp+=max(p+(s[i]-s[j]+0.)/sum,0.);
				if(sp<1) L=p; else R=p;
			}
			printf(" %.6lf",100*L);
		}
		printf("\n");
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
