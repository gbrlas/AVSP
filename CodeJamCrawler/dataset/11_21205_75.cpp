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

#define N 111

int main()
{
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d:\n",++tst);
		fprintf(stderr,"Case #%d:\n",tst);

		//Code
		int n,i,j;
		scanf("%d",&n);
		char a[N][N];
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		int win[N],tot[N];
		double wp[N],owp[N],oowp[N];
		for(i=0;i<n;i++)
		{
			int wini=0;
			int toti=0;
			for(j=0;j<n;j++)
			{
				if(a[i][j]!='.')
					toti++;
				if(a[i][j]=='1')
					wini++;
			}
			win[i]=wini;
			tot[i]=toti;
			wp[i]=1.*wini/toti;
		}
		for(i=0;i<n;i++)
		{
			double sum=0;
			for(j=0;j<n;j++) if(a[i][j]!='.')
				sum+=1.*(win[j]-(a[i][j]=='0'))/(tot[j]-1);
			owp[i]=sum/tot[i];
		}
		for(i=0;i<n;i++)
		{
			double cur=0;
			for(j=0;j<n;j++) if(a[i][j]!='.')
				cur+=owp[j];
			oowp[i]=cur/tot[i];
		}
		for(i=0;i<n;i++)
		{
			double rpi=(wp[i]+2*owp[i]+oowp[i])/4;
			printf("%.10lf\n",rpi);
		}
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
