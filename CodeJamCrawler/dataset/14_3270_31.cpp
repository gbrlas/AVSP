#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int n;
int a[1005];
map<int,int> id;

int dp[1005][1005];
int idx[1005];
int lower[1005];
int go(int s, int e) {
	int &ret = dp[s][e];
	if(ret != -1) return ret;
	ret = 10000000;

	if(s >= e) return ret = 0;

	int lft = s;
	int rht = n-1-e;
	int cnt = lft+rht;

	ret = min(ret, abs(idx[cnt]-rht+lower[cnt] - (s)) + go(s+1,e));
	ret = min(ret, abs(idx[cnt]-rht+lower[cnt] - (e)) + go(s,e-1));

	return ret;
}

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int Ts;
	scanf("%d",&Ts);
	for(int cs=1;cs<=Ts;++cs) {
		id.clear(), memset(dp,-1,sizeof(dp));
		memset(lower,0,sizeof(lower));
		printf("Case #%d: ", cs);

		scanf("%d",&n);
		vector<int>b;
		for(int i=0;i<n;++i) {
			scanf("%d",a+i), b.push_back(a[i]);
		}
		sort(b.begin(),b.end());
		for(int i=0;i<n;++i) id[b[i]] = i;
		int mx_idx = -1;
		for(int i=0;i<n;++i) {
			a[i] = id[a[i]];
			if(a[i] == n-1) mx_idx=i;
		}
		for(int i=0;i<n;++i) idx[a[i]] = i;	

		for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) lower[a[i]] += (a[i] > a[j]);
		
		printf("%d\n",go(0,n-1));

	}
}