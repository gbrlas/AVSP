#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:216777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;
typedef unsigned __int64 ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

bool is_sq(LL x)
{
	LL y=sqrt(1.*x)+2;
	for(;y*y>x;y--);
	return y*y==x;
}

int main()
{
	freopen("d1.in","r",stdin);
	freopen("d1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int i;
		char s[66];
		scanf("%s",s);
		int n=strlen(s);
		VI q;
		for(i=0;i<n;i++)
			if(s[i]=='?')
				q.pb(i);
		int m=q.sz;
		char w[66];
		for(int mask=0;mask<bit(m);mask++)
		{
			strcpy(w,s);
			for(i=0;i<m;i++)
				w[q[i]]=mask & bit(i)?'0':'1';
			LL x=0;
			for(i=0;i<n;i++)
				x=2*x+w[i]-'0';
			if(is_sq(x))
				break;
		}
		puts(w);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
