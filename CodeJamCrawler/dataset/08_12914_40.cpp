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

typedef pair<int,int> PII;

const int MAXN=100010;

int n;
PII a[MAXN];
int f[3][3];
PII p[3];

I64 comP()
{
	if(p[0]==p[1]) {
		if(p[1]==p[2]) {
			I64 v=f[p[0].first][p[0].second];
			if(v<3) return 0;			
			return v*(v-1)*(v-2)/6;
		}
		else {
			I64 v=f[p[0].first][p[0].second];
			if(v<2) return 0;

			return v*(v-1)/2*f[p[2].first][p[2].second];
		}
	}
	else {
		if(p[1]==p[2]) {
			I64 v=f[p[1].first][p[1].second];
			if(v<2) return 0;

			return v*(v-1)/2*f[p[0].first][p[0].second];
		}
		else {
			return (I64)f[p[0].first][p[0].second]*f[p[1].first][p[1].second]*f[p[2].first][p[2].second];
		}
	}
}

I64 com()
{
	I64 res=0;

	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++) f[a[i].first%3][a[i].second%3]++;
	
	for(int i1=0;i1<3;i1++)
		for(int i2=0;i2<3;i2++) {
			int i3=(3-i1-i2)%3;
			if(i3<0) i3+=3;

			for(int j1=0;j1<3;j1++)
				for(int j2=0;j2<3;j2++) {
					int j3=(3-j1-j2)%3;
					if(j3<0) j3+=3;

					p[0]=PII(i1,j1);
					p[1]=PII(i2,j2);
					p[2]=PII(i3,j3);

					if(p[0]<=p[1] && p[1]<=p[2]) res+=comP();
				}
		}

	return res;
}

I64 solve()
{
	int x0,y0;
	int A,B,C,D,M;

	scanf("%d",&n);
	scanf("%d%d%d%d",&A,&B,&C,&D);
	scanf("%d%d",&x0,&y0);
	scanf("%d",&M);

	a[0].first=x0,a[0].second=y0;

	int x=x0,y=y0;
	for(int i=1;i<n;i++) {
		x=((I64)A*x+B)%M;
		y=((I64)C*y+D)%M;
		a[i].first=x,a[i].second=y;
	}

	return com();
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d: %I64d\n",i,solve());
	}

	return 0;
}
