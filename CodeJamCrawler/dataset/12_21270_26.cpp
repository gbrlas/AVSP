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

#define N 5555
#define K 34

int main()
{
	freopen("d1.in","r",stdin);
	freopen("d1.out","w",stdout);
	int w[26];
	fill(w,255);
	w['o'-'a'] = 26 + 0;
	w['i'-'a'] = 26 + 1;
	w['e'-'a'] = 26 + 2;
	w['a'-'a'] = 26 + 3;
	w['s'-'a'] = 26 + 4;
	w['t'-'a'] = 26 + 5;
	w['b'-'a'] = 26 + 6;
	w['g'-'a'] = 26 + 7;
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int k;
		char s[N];
		scanf("%d %s",&k,s);
		int n=strlen(s);
		LL ans=0;
		int i,j;
		if(k==2)
		{
			int q[K][K]={0};
			for(i=1;i<n;i++)
			{
				int a=s[i]-'a';
				int b=s[i-1]-'a';
				q[a][b]=1;
				if(w[a]>=0) q[w[a]][b]=1;
				if(w[b]>=0) q[a][w[b]]=1;
				if(w[a]>=0 && w[b]>=0) q[w[a]][w[b]]=1;
			}
			int in[K]={0},out[K]={0};
			for(i=0;i<K;i++)
				for(j=0;j<K;j++)
				{
					in[i]+=q[i][j];
					out[j]+=q[i][j];
				}
			int dif=0;
			for(i=0;i<K;i++)
			{
				dif+=in[i]!=out[i];
				ans+=max(in[i],out[i]);
			}
			ans+=dif==0;
		}
		printf("%lld\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
