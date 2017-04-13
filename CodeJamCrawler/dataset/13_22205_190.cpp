#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
//#include <cassert>
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

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

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

#define N 1000000
string a[N];
int len;

int n;
int cur[111];

void rec(int i,int s2)
{
	if(s2>=10) return;
	if(i==(n+1)/2)
	{
		for(int i=0;i<n/2;i++)
			cur[n-1-i]=cur[i];
		int cur2[111]={0};
		for(int i=0;i<n;i++) if(cur[i])
			for(int j=0;j<n;j++)
				cur2[i+j]+=cur[i]*cur[j];
		string s="";
		for(int i=0;i<2*n-1;i++)
		{
			assert(cur2[i]<10);
			assert(cur2[i]==cur2[2*n-2-i]);
			s+=char(cur2[i]+'0');
		}
		a[len++]=s;
		//for(int i=0;i<n;i++) fprintf(stderr,"%d",cur[i]);		fprintf(stderr," %s\n",s.c_str());
		return;
	}
	for(int d=!i;d<=3;d++)
	{
		cur[i]=d;
		int s2d = s2 + 2*d*d;
		if(2*i==n-1) s2d -= d*d;
		rec(i+1,s2d);
		cur[i]=-1;
	}
}

bool cmp(string a,string b)
{
	return a.sz<b.sz || a.sz==b.sz && a<b;
}

int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	for(n=1;n<=51;n++)
	{
		rec(0,0);
		fprintf(stderr,"len=%d\n",len);
	}
	int TST,tst=0;
	for(cin >> TST;TST--;)
	{
		fprintf(stderr,"Case #%d:\n",tst);
		printf("Case #%d: ",++tst);
		string L,R;
		cin >> L >> R;
		int ans = upper_bound(a,a+len,R,cmp)-lower_bound(a,a+len,L,cmp);
		printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
