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

LL rev(LL x)
{
	LL y=0;
	for(;x;x/=10)
		y=10*y+x%10;
	return y;
}

LL a[111111];
int len=0;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int pw[8]={1};
	for(int n=1;n<=7;n++)
	{
		pw[n]=10*pw[n-1];
		int m=(n+1)/2;
		for(int x=pw[m-1];x<pw[m];x++)
		{
			int pal = pw[n/2] * x + rev(x/(n%2?10:1));
			LL sq = LL(pal)*pal;
			if(rev(sq)==sq)
			{
				a[len++]=sq;
				fprintf(stderr,"%d\n",pal);
			}
		}
	}
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		fprintf(stderr,"Case #%d:\n",tst);
		printf("Case #%d: ",++tst);
		LL L,R;
		scanf("%lld%lld",&L,&R);
		int ans = upper_bound(a,a+len,R)-lower_bound(a,a+len,L);
		printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
