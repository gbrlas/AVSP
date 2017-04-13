#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<math.h>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert> 
#include <list>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i=0;i<n;i++)
#define fr2(i, a, n) for(i=a;i<n;i++)
#define mem(a, n) memset(a, n, sizeof(a))

string s;
int ls, lcmp;
string cmp;
int dp[500][21];
int solve(int x, int y) {
	if(y==lcmp)
		return 1;
	if(x>=ls || y>lcmp)
		return 0;
	if(dp[x][y]!=-1)
		return dp[x][y];
	int m = 0;
	if(s[x]==cmp[y]) 
		m = (solve(x+1, y+1) % 10000+ solve(x+1, y) % 10000) % 10000;
	else
		m = solve(x+1, y) % 10000;
	
	return dp[x][y] = m;
}
int main() {
	int n;
	cmp = "welcome to code jam";
	lcmp = cmp.sz;
	scanf("%d", &n);
	getline(cin, s);
	int k;
	
	fr2(k, 1, n+1) {
		char a[1000];
		gets(a);
		mem(dp, -1);
		s = a;
		ls = s.sz;
	//	cout << solve(0, 0) << endl;
		printf("Case #%d: %04d\n", k, solve(0, 0))%10000;
	}

}
