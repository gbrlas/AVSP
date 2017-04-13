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

int r,c;

string grid[5];

int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,1,-1};

int dp[2][5][5][1<<17];

int solve(int row, int col, int mask, int turn) {
	int &ret=dp[turn][row][col][mask];
	if(ret!=-1) return ret;
	for(int i=0;i<8;i++) {
		int nrow=row+dy[i];
		int ncol=col+dx[i];
		if(nrow<0||ncol<0||nrow==r||ncol==c) continue;
		if(grid[nrow][ncol]=='#') continue;
		int cannon=nrow*c+ncol;
		if(mask&1<<cannon) continue;
		if(solve(nrow,ncol,mask|1<<cannon,!turn)==turn) return ret=turn;
	}
	return ret=!turn;
}

int main() {
	int cases;
	cin>>cases;
	for(int tc=1;tc<=cases;tc++) {
		cout<<"Case #"<<tc<<": ";
		cin>>r>>c;
		for(int i=0;i<r;i++) cin>>grid[i];
		int y,x;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(grid[i][j]=='K') {
			y=i;
			x=j;
		}
		memset(dp,-1,sizeof(dp));
		int cannon=y*c+x;
		cout<<char(solve(y,x,1<<cannon,0)+'A')<<endl;
	}
}
