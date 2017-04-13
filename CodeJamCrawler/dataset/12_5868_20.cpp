
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T gcd(T a,T b){return a==0?b:gcd(b%a,a);}
template<class T> inline int countbit(T n){return n==0?0:(1+countbit(n&(n-1)));}
template<class T> inline void pout(T A[],int n){cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}
template<class T> inline void pout(vector<T> A,int n=-1){if (n==-1) n=A.size();cout<<"{";for (int i=0;i<n;i++)cout<<A[i]<<", ";cout<<"}\n";}

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,cs,h) for(i=(cs);i<=(h);++i)
#define FORD(i,h,cs) for(i=(h);i>=(cs);--i)
#define FORIT(a,aa) for(a=aa.begin();a!=aa.end();++a)
#define split(str) {vs.clear();istringstream sss(str);while(sss>>(str))vs.push_back(str);}

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;


void solve();

void main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,cs;
	cin>>T; 
	for (cs=1;cs<=T;cs++)
	{
		printf("Case #%d: ",cs); solve();//cout<<ans<<endl;
	}
	return ;
}
void f(int *x,int *y,int n)
{
	int i;
	REP(i,n) cout<<x[i]<<" "<<y[i]<<" ";
	cout<<endl;
}
void solve()
{
	int i,j,k,n,w,h;
	PII r[1000];
	cin>>n>>w>>h;
	REP(i,n)
	{
		cin>>r[i].first;
		r[i].second=i;
	}
	REP(i,n) for (j=i+1;j<n;j++)
	{
		if (r[i].first<r[j].first) swap(r[i],r[j]);
	}
	int up=0,down=0,lef=0,rig=0;
	int x=0;
	int x1[1000],y1[1000];
	REP(i,n)
	{
		int p=r[i].first;
		int d=r[i].second;
		if (x==0)
		{
			x1[d]=x;y1[d]=0;
			x=p;continue;
		}
		else
		{
			if (x+p>w) break;
			x1[d]=x+p;y1[d]=0;
			x+=2*p;continue;	
		}
	}
	if (i==n){ f(x1,y1,n);return;}
	up=r[0].first;
	down=r[i].first;
	x=0;
	for (;i<n;i++)
	{
		int p=r[i].first;
		int d=r[i].second;
		if (x==0)
		{
			x1[d]=x;y1[d]=h;
			x=p;
		}
		else
		{
			if (x+p>w) break;
			x1[d]=x+p;y1[d]=h;
			x+=2*p;	
		}
	}
	if (i==n){ f(x1,y1,n);return;}
	lef=r[i].first;
	int y=up;
	for (;i<n;i++)
	{
		int p=r[i].first;
		int d=r[i].second;
		if (y+p>h-down) break;
		x1[d]=0;y1[d]=y+p;
		y+=2*p;	
	}
	rig=r[i].first;
	y=up;
	for (;i<n;i++)
	{
		int p=r[i].first;
		int d=r[i].second;
		if (y+p>h-down) break;
		x1[d]=w;y1[d]=y+p;
		y+=2*p;	
	}
	if (i==n){ f(x1,y1,n);return;}
	w-=lef+rig;
	h-=up+down;
	x=0;y=0;
	int inc=0;
	for (;i<n;i++)
	{
		int p=r[i].first;
		int d=r[i].second;
		if (inc==0) inc=2*p;
		if (x+p>w) 
		{
			x=0;i--;y+=inc;inc=0;
		}
		else
		{
			x+=2*p;
			x1[d]=x+lef; y1[d]=y+up;
		}
	}
	f(x1,y1,n);
}