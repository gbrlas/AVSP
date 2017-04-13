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

#define N 2020
int n;
int x[N];
int y[N];
bool bad;

void rec(int L,int R,int a,LL b,int c) // y[i] < (a*i+b)/c, L<=i<R, y[R] fixed
{
	VI q;
	int i;
	for(i=L;i<R;i=x[i])
		q.pb(i);
	if(i>R)
	{
		bad=true;
		return;
	}
	int j=R;
	for(int h=q.sz;h--;)
	{
		i=q[h];
		y[i]=(LL(a)*i+b-1)/c;
		a=y[j]-y[i];
		b=LL(j)*y[i]-LL(i)*y[j];
		c=j-i;
		if(i+1<j)
		{
			rec(i+1,j,a,b,c);
			if(bad) return;
		}
		j=i;
	}
}

int main()
{
	freopen("C1.in","r",stdin);
	freopen("C1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		scanf("%d",&n);
		int i;
		for(i=0;i<n-1;i++)
		{
			scanf("%d",x+i);
			x[i]--;
		}
		y[n-1]=inf;
		bad=false;
		rec(0,n-1,0,inf,1);
		if(bad) puts("Impossible"); else
		{
			for(i=0;i<n;i++)
				printf("%d%c",y[i],i<n-1?' ':'\n');
		}
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
