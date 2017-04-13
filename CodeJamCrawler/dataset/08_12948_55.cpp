#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define size(x) int((x).size())
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
typedef long long I64; typedef unsigned long long U64;
const double EPS=1e-12;
const int INF=999999999;
typedef vector<int> VI;
typedef vector<string> VS;

const int MAXN=1010;

int n;
int a[MAXN][3];
int range[3][2];
int b[MAXN];

double comV(double x,double y,double z)
{
	double res=0;
	for(int i=0;i<n;i++) {
		double w=fabs(x-a[i][0])+fabs(y-a[i][1])+fabs(z-a[i][2]);
		w/=b[i];
		res>?=w;
	}

	return res;
}

double comZ(double x,double y)
{
	double lx=range[2][0],rx=range[2][1],x1,x2;
	double v1,v2;
	do {
		x1=(lx*2+rx)/3,x2=(lx+rx*2)/3;
		v1=comV(x,y,x1),v2=comV(x,y,x2);
		if(v1>v2+EPS) lx=x1; else rx=x2;
	} while(lx+1e-7<rx);
	return v1;
}

double comY(double x)
{
	double lx=range[1][0],rx=range[1][1],x1,x2;
	double v1,v2;
	do {
		x1=(lx*2+rx)/3,x2=(lx+rx*2)/3;
		v1=comZ(x,x1),v2=comZ(x,x2);
		if(v1>v2+EPS) lx=x1; else rx=x2;
	} while(lx+1e-7<rx);
	return v1;
}

void solve()
{
	scanf("%d",&n);
	for(int i=0;i<3;i++) {
		range[i][0]=INF;
		range[i][1]=-INF;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<3;j++) {
			scanf("%d",&a[i][j]);
			range[j][0]<?=a[i][j];
			range[j][1]>?=a[i][j];
		}
		scanf("%d",&b[i]);
	}

	double lx=range[0][0],rx=range[0][1],x1,x2;
	double v1,v2;
	do {
		x1=(lx*2+rx)/3,x2=(lx+rx*2)/3;
		v1=comY(x1),v2=comY(x2);
		if(v1>v2+EPS) lx=x1; else rx=x2;
	} while(lx+1e-7<rx);

	printf("%.6lf",v1);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d: ",i);
		solve();
		printf("\n");
	}

	return 0;
}
