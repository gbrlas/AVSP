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

#define llong unsigned long long

bool bad[101][101];

llong dp[101][101];
bool got[101][101];

llong solve(int rows, int cols) {
	if(rows<0||cols<0||bad[rows][cols]) return 0;
	if(rows+cols==0) return 1;
	if(got[rows][cols]) return dp[rows][cols];
	got[rows][cols]=1;
	llong &ret=dp[rows][cols];
	return ret=(solve(rows-1,cols-2)+solve(rows-2,cols-1))%10007;
}

int main() {
	int cases;
	cin>>cases;
	int x,y;
	for(int tc=1;tc<=cases;tc++) {
		memset(bad,0,sizeof(bad));
		memset(got,0,sizeof(got));
		cout<<"Case #"<<tc<<": ";
		int width, height, rocks;
		cin>>width>>height>>rocks;
		for(int i=0;i<rocks;i++) {
			cin>>x>>y;
			bad[x-1][y-1]=1;
		}
		cout<<solve(width-1,height-1)<<endl;
	}
}
