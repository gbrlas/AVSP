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

int n;
PII a[100];

int solve()
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

	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++) {
				I64 u=(I64)a[i].first+a[j].first+a[k].first;
				I64 v=(I64)a[i].second+a[j].second+a[k].second;
				if(u%3==0 && v%3==0) ans++;
			}
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d: %d\n",i,solve());
	}

	return 0;
}
