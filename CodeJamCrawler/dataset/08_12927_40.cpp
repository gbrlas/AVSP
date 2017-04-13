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

int n,m;
int d[100];
int head,L;
int a[5010];
int ans[5010];

void solve()
{
	int left=n;

	head=1;
	for(int i=1;i<=n;i++) a[i]=i;
	L=n+2;

	for(int i=1;i<=n;i++) {
		for(int j=1;j<i;j++) {
			a[(head+left)%L]=a[head];
			head=(head+1)%L;
		}

		ans[a[head]]=i;
		head=(head+1)%L;
		left--;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d:",i);

		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++) scanf("%d",&d[i]);

		solve();

		for(int i=0;i<m;i++) printf(" %d",ans[d[i]]);
		printf("\n");
	}

	return 0;
}
