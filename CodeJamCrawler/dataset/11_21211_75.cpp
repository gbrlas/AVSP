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
#pragma comment(linker, "/STACK:16777216")
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

clock_t start=clock();

int main()
{
	freopen("b1.in","r",stdin);
	freopen("b1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);

		//Code
		int n,d,i;
		scanf("%d%d",&n,&d);
		int a[222],b[222];
		for(i=0;i<n;i++)
			scanf("%d%d",a+i,b+i);
		double L=0;
		double R=1e13;
		for(int it=0;it<100;it++)
		{
			double x=(L+R)/2;
			double prev=-1e20;
			for(i=0;i<n;i++)
			{
				MAX(prev,a[i]-x);
				if(prev+(b[i]-1)*d<=a[i]+x)
					prev+=b[i]*d;
				else break;
			}
			if(i<n) L=x; else R=x;
		}
		printf("%.10lf\n",R);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
