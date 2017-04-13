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

int n,m,a;

void solve()
{
	int x1,y1,x2,y2,x3,y3;

	scanf("%d%d%d",&n,&m,&a);

	for(int dx2=0;dx2<=n;dx2++)
		for(int dy1=-m;dy1<=m;dy1++) {
			int w=dy1*dx2+a;
			for(int dx1=0;dx1<=n;dx1++) {
				if(dx1!=0 && w%dx1!=0) continue;
				if(dx1==0 && w!=0) continue;

				int dy2;
				if(dx1==0) dy2=0; else dy2=w/dx1;
				if(dy2<-m || dy2>m) continue;

				x1=dx1,x2=dx2,x3=0;
				y1=dy1,y2=dy2,y3=0;

				int dx=n-(x1>?x2>?x3);
				x1+=dx,x2+=dx,x3+=dx;
				
				int dy=m-(y1>?y2>?y3);
				y1+=dy,y2+=dy,y3+=dy;
				
				if(x1<0 || x2<0 || x3<0) continue;
				if(y1<0 || y2<0 || y3<0) continue;

				printf("%d %d %d %d %d %d",x1,y1,x2,y2,x3,y3);
				return;
			}
		}

	printf("IMPOSSIBLE");
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
