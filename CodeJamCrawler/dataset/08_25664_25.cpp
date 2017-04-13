#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cctype>
using namespace std;

#define llong long long

int m,v;

bool kind[10002], change[10002];
bool leaf[10002], val[10002];

bool got[10002][2];
int dp[10002][2];

int best(int a, int b) {
	if(a==-1) return b;
	if(b==-1) return a;
	return min(a,b);
}

int solve(int node, int need) {
	if(got[node][need]) return dp[node][need];
	if(leaf[node]) return (need==val[node]?0:-1);
	int &ret=dp[node][need];
	int left1=solve(2*node,1), left0=solve(2*node,0);
	int right1=solve(2*node+1,1), right0=solve(2*node+1,0);
	got[node][need]=1;
	ret=-1;
	if(need==0) {
		if(kind[node]==1) {
			if((left0>=0||right0>=0)) ret=best(ret,best(left0,right0));
			if(change[node]&&((left0>=0)&&(right0>=0))) ret=best(ret,left0+right0+1);
		} else {
			if((left0>=0)&&(right0>=0)) ret=best(ret,left0+right0);
			if(change[node]&&((left0>=0||right0>=0))) ret=best(ret,best(left0,right0)+1);
		}
	} else {
		if(kind[node]==1) {
			if((left1>=0&&right1>=0)) ret=best(ret,left1+right1);
			if(change[node]&&((left1>=0)||(right1>=0))) ret=best(ret,best(left1,right1)+1);
		} else {
			if((left1>=0)||(right1>=0)) ret=best(ret,best(left1,right1));
			if(change[node]&&((left1>=0&&right1>=0))) ret=best(ret,(left1+right1+1));
		}
	}
	return ret;
}

int main() {
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++) {
		cin>>m>>v;
		memset(got,0,sizeof(got));
		memset(leaf,0,sizeof(leaf));
		for(int i=1;i<=(m-1)/2;i++) {
			cin>>kind[i]>>change[i];
		}
		for(int i=(m-1)/2+1;i<=m;i++) {
			cin>>val[i];
			leaf[i]=1;
		}
		cout<<"Case #"<<tc<<": ";
		int ret=solve(1,v);
		if(ret==-1) cout<<"IMPOSSIBLE"<<endl;
		else cout<<ret<<endl;
	}
}

