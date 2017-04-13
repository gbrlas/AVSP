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

#define N 1111

int main()
{
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d:\n",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int w,l,u,g;
		scanf("%d%d%d%d",&w,&l,&u,&g);
		int n=l+u;
		int x[N],y[N];
		int i,k;
		for(i=0;i<l;i++)
			scanf("%d%d",x+i,y+i);
		for(i=n-1;i>=l;i--)
			scanf("%d%d",x+i,y+i);
		int ar=0;
		for(i=0;i<n;i++)
		{
			int j=(i+1)%n;
			ar+=x[i]*y[j]-x[j]*y[i];
		}
		ar=abs(ar);
		for(k=1;k<g;k++)
		{
			double kar=1.*k*ar/g;
			double L=0;
			double R=w;
			for(int it=0;it<50;it++)
			{
				double xx[N],yy[N];
				int len=0;
				double M=(L+R)/2;
				for(i=0;i<l-1;i++)
				{
					if(x[i]<=M) xx[len]=x[i],yy[len++]=y[i];
					if(x[i]<M && M<=x[i+1])
					{
						double y1=y[i]+(y[i+1]-y[i])*(M-x[i])/(x[i+1]-x[i]);
						xx[len]=M,yy[len++]=y1;
					}
				}
				for(i=l+1;i<n;i++)
				{
					if(x[i]<M && M<=x[i-1])
					{
						double y2=y[i]+(y[i-1]-y[i])*(M-x[i])/(x[i-1]-x[i]);
						xx[len]=M,yy[len++]=y2;
					}
					if(x[i]<=M) xx[len]=x[i],yy[len++]=y[i];
				}
				double cur=0;
				for(i=0;i<len;i++)
				{
					int j=(i+1)%len;
					cur+=xx[i]*yy[j]-xx[j]*yy[i];
				}
				cur=fabs(cur);
				if(cur<kar) L=M; else R=M;
			}
			printf("%.9lf\n",L);
		}
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
