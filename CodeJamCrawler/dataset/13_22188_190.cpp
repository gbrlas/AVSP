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

const int n = 4;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		fprintf(stderr,"Case #%d:\n",tst);
		printf("Case #%d: ",++tst);
		char a[n][n+1];
		int dots=0;
		int xxx=0,ooo=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			int x=0,o=0;
			for(int j=0;j<n;j++)
			{
				if(a[i][j]=='.') dots++;
				if(a[i][j]=='X') x++;
				if(a[i][j]=='O') o++;
				if(a[i][j]=='T') x++,o++;
			}
			if(x==4) xxx++;
			if(o==4) ooo++;
		}
		for(int j=0;j<n;j++)
		{
			int x=0,o=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][j]=='.') dots++;
				if(a[i][j]=='X') x++;
				if(a[i][j]=='O') o++;
				if(a[i][j]=='T') x++,o++;
			}
			if(x==4) xxx++;
			if(o==4) ooo++;
		}
		{
			int x=0,o=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][i]=='.') dots++;
				if(a[i][i]=='X') x++;
				if(a[i][i]=='O') o++;
				if(a[i][i]=='T') x++,o++;
			}
			if(x==4) xxx++;
			if(o==4) ooo++;
		}
		{
			int x=0,o=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][n-1-i]=='.') dots++;
				if(a[i][n-1-i]=='X') x++;
				if(a[i][n-1-i]=='O') o++;
				if(a[i][n-1-i]=='T') x++,o++;
			}
			if(x==4) xxx++;
			if(o==4) ooo++;
		}
		if(xxx) puts("X won"); else
		if(ooo) puts("O won"); else
		if(dots) puts("Game has not completed"); else
			puts("Draw");
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
