#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

#define llong long long

int bad[11];
bool invalid[1<<11];
int rows,cols;

int trans(int mask) {
	int ret=0;
	for(int i=0;i<cols;i++) if(mask&(1<<i)) {
		int low=i-1, high=i+1;
		if(low>=0) ret|=1<<low;
		if(high<cols) ret|=1<<high;
	}
	return ret;
}

int dp[1<<11][11];

int solve(int row, int mask) {
	if(row==rows) return 0;
	int &ret=dp[mask][row];
	if(ret!=-1) return ret;
	ret=0;
	for(int i=0;i<(1<<cols);i++) {
		if(invalid[i]) continue;
		if(bad[row]&i) continue;
		if(mask&i) continue;
		ret=max(ret,solve(row+1,trans(i))+__builtin_popcount(i));
	}
	return ret;
}

int main() {
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++) {
		cin>>rows>>cols;
		char c;
		for(int i=0;i<rows;i++) {
			int mask=0;
			for(int j=0;j<cols;j++) {
				cin>>c;
				if(c=='x') mask|=1<<j;
			}
			bad[i]=mask;
		}
		for(int i=0;i<(1<<cols);i++) {
			bool ok=1;
			for(int j=0;j<cols;j++) if(i&(1<<j)) {
				int low=j-1, high=j+1;
				if(low>=0&&(i&(1<<low))) {
					ok=0;
					break;
				}
				if(high<cols&&(i&(1<<high))) {
					ok=0;
					break;
				}
			}
			if(ok) invalid[i]=0;
			else invalid[i]=1;
		}
		memset(dp,-1,sizeof(dp));
		cout<<"Case #"<<tc<<": "<<solve(0,0)<<endl;
	}
}
